from heapq import *

class PriorityQueue(object):

    def __init__(self, type='min'):
        self.pq = []
        self.item_dict: dict[tuple[int,int]] = {}
        self.order = 1 if type == 'min' else -1

    def __heapify__(self):
        heapify(self.pq)

    def contains(self, item):
        return True if item in self.item_dict else False

    def get_weight(self, item):
        if self.contains(item):
            return self.item_dict[item][0]
        raise ValueError("Item doesn't exist in Priority Queue")

    def push(self, item, weight):
        if self.contains(item):
            raise KeyError("Item exists")
        entry = (self.order * weight, item)
        self.item_dict[item] = entry
        heappush(self.pq, entry)

    def update(self, item:int, weight:int):
        if not self.contains(item):
            raise KeyError("Item not found")
        if weight == self.get_weight(item):
            return

        self.item_dict[item] = (weight,item)

        for i,entry in enumerate(self.pq):
            if entry[1] == item:
                self.pq[i] = (weight,item)
        self.__heapify__()

    def remove(self, item):
        if not self.contains(item):
            raise KeyError("Item doesn't exist")

        weight = self.get_weight(item)

        self.pq.remove((weight,item))
        del self.item_dict[item]

        self.__heapify__()

    def is_empty(self):
        return True if not self.pq else False

    def peek(self):
        if not self.is_empty():
            return self.pq[0]
        return None

    def pop(self):
        if self.is_empty():
            raise KeyError("Queue is Empty")
        entry = self.pq.pop(0)
        del self.item_dict[entry[1]]
        self.__heapify__()
        return entry






