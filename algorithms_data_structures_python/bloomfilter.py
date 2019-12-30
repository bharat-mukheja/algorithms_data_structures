"""
Python 3 program to create a Bloom Filter
Install mmh3 and bitarray 3rd party module first
pip install mmh3 - murmur3 hash function
pip install bitarray
"""
import math, mmh3
from bitarray import bitarray
from typing import Union, Generator

class BloomFilter(object):
    """
    Class for Bloom Filter, using murmur3 hash function
    """
    def __init__(self, items_count: int, false_positive_prob: float):
        """
        :param items_count: Number of items to be expected in bloom filter
        :param false_positive_prob: Self-descriptive, in decimal
        """
        # False positive probability in decimal
        self.fp_prob: float = false_positive_prob

        #Size of bit array to use
        self.size: int = self.get_size(items_count,false_positive_prob)

        # Number of hash functions to use
        self.hash_count: int = self.get_hash_count(self.size, items_count)

        # Bit array of given size
        self.bit_array = bitarray(self.size)

        # Initialize all bits as 0
        self.bit_array.setall(0)

    def add(self, item: Union[str,int]):
        """
        Add an item to the filter
        """
        # Get all hashes
        hashes: Generator = self.get_hashes(item)

        # For each hash, find out the bitarray index and set that to True
        for hash_modulus in hashes:
            self.bit_array[hash_modulus] = True

    def check(self, item: Union[str,int]) -> bool:
        """
        Check if the item exists in the filter
        """
        # Get all hashes
        hashes: Generator = self.get_hashes(item)

        # For each hash if any of the bit is not set, it is definitely not present
        # Else there is a probability it might exist
        for hash_modulus in hashes:
            if self.bit_array[hash_modulus] == False:
                return False
        return True

    def get_size(self, n:int, P:int) -> int:
        """
        Return the minimum size of bit array to be used for getting the desired
        false positive probability
        Formula: m = -(n*lnP)/(ln2)**2
        """
        return int(-(n * math.log(P))/(math.log(2)**2))

    def get_hash_count(self, bitarray_size:int, items_count:int)->int:
        """
        Return the optimum number of hash functions to be used for getting the desired
        false positive probability given bit array size
        Formala:  k = (m/n) * ln(2)
        """
        return int((bitarray_size*math.log(2))/items_count)

    def get_hashes(self, item:Union[str,int])-> Generator:
        """
        Get hash modulus for an item, depending upon bitarray size
        """
        for i in range(self.hash_count):
            # We are using murmur3 hash function
            yield int(mmh3.hash(item,i) % self.size)

# Test the bloom filter
from random import shuffle

n = 20
p = 0.05

bloomf = BloomFilter(n,p)
print(f"Size of bit array:{bloomf.size}")
print(f"False positive Probability:{bloomf.fp_prob}")
print(f"Number of hash functions:{bloomf.hash_count}")

# Words to be added
word_present = ['abound','abounds','abundance','abundant','accessable',
                'bloom','blossom','bolster','bonny','bonus','bonuses',
                'coherent','cohesive','colorful','comely','comfort',
                'gems','generosity','generous','generously','genial']

# Word not added
word_absent = ['bluff','cheater','hate','war','humanity',
               'racism','hurt','nuke','gloomy','facebook',
               'geeksforgeeks','twitter']

for word in word_present:
    bloomf.add(word)

shuffle(word_present)
shuffle(word_absent)

test_words = word_present[:10]+word_absent

shuffle(test_words)
print("Testing random present words and all the absent words")
for word in test_words:
    if bloomf.check(word):
        if word in word_absent:
            print(f"'{word}' is a FALSE positive!")
        else:
            print(f"'{word}' is a probably present!")
    else:
        print(f"'{word}' is definitely not present!")
