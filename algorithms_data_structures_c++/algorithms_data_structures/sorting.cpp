//
//  sorting.cpp
//  data_structures
//
//  Created by Bharat Mukheja on 11/23/19.
//  Copyright © 2019 Bharat Mukheja. All rights reserved.
//

#include <iostream>

using namespace std;

class Sorting{
private:
    void heapify(int[], int, int);
    void swap(int[], int, int);
    void merge_sort(int[], int, int);
    void merge(int[], int, int, int);
    void quick_sort(int[], int, int);
    int partition(int[], int, int);
    void counting_sort(int[], int, int);
public:
    void heap_sort(int[],int);
    void radix_sort(int[],int);
    void quick_sort(int[],int);
    void merge_sort(int[],int);
    void insertion_sort(int[],int);
};

void Sorting::swap(int arr[], int first, int second){
    int temp = arr[first];
    arr[first] = arr[second];
    arr[second] = temp;
}

void Sorting::heapify(int arr[], int arr_length, int root){
    int largest = root;
    int left_child = 2*root + 1;
    int right_child = 2*root + 2;
    
    if (left_child < arr_length && arr[largest] < arr[left_child])
        largest = left_child;
    
    if (right_child < arr_length && arr[largest] < arr[right_child])
        largest = right_child;
    
    if (largest != root){
        swap(arr, largest, root);
        heapify(arr, arr_length, largest);
    }
}

void Sorting::heap_sort(int arr[], int arr_length){
    
    //Build a max heap from the input data
    for (int i = arr_length/2 -1; i>=0; i--){
        heapify(arr, arr_length, i);
    }
    
    //Root is largest. Swap it with last element and heapify the root of heap
    for(int i = arr_length-1; i>0 ; i--){
        swap(arr, 0, i);
        heapify(arr, i, 0); // This step heapifies array of size one less than
                            // last step
    }
}

void Sorting::merge_sort(int arr[], int arr_length){
    merge_sort(arr, 0, arr_length-1);
}

void Sorting::merge_sort(int arr[], int start, int end){
    if (start<end){
        int mid = (start+end)/2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

void Sorting::merge(int arr[], int start, int mid, int end){
    int left_index = start;
    int right_index = mid+1;
    
    int A[end-start+1];
    int k =0;
    for (int i = start;i<=end;i++){
        if (left_index > mid)
            A[k++] = arr[right_index++];
        
        else if (right_index > end)
            A[k++] = arr[left_index++];
        
        else if (arr[left_index] < arr[right_index])
            A[k++] = arr[left_index++];
        
        else
            A[k++] = arr[right_index++];
    }
    for(int i = 0; i<k; i++){
        arr[start++] = A[i];
    }
}

void Sorting::quick_sort(int arr[], int length){
    quick_sort(arr, 0, length-1);
}

void Sorting::quick_sort(int arr[], int left, int right){
    if (left<right){
        /*partition the array by taking the last element and get
         the partition index*/
        int pi = partition(arr, left, right);
        
        quick_sort(arr, left, pi-1);
        quick_sort(arr, pi+1, right);
    }
}

int Sorting::partition(int arr[], int left, int right){
    int control_element = left -1;
    int pivot = right;
    
    for (int i = left; i<right; i++){
        if (arr[i]<arr[pivot]){
            control_element++;
            swap(arr, control_element, i);
        }
        
    }
    control_element++;
    swap(arr, control_element, pivot);
    
    return control_element;
}


void Sorting::insertion_sort(int arr[],int length){
    for (int i = 1; i < length; i++){
        int j=i-1;
        int x = arr[i];
        while (j>=0 && arr[j]>x){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}

void Sorting::radix_sort(int arr[], int length){
    if (length == 0)
        return;
    
    //Find the maximum number to know the max number of digits
    int max = arr[0];
    for (int i = 0; i<length;i++){
        if (arr[i]>max){
            max = arr[i];
        }
    }
    int multiplier = 1;
    while (max){
        counting_sort(arr, length, multiplier);
        multiplier *= 10;
        max /= 10;
    }
    
}

void Sorting::counting_sort(int arr[], int length, int bit_place){
    int i, freq[10] = {0};
    int output[length];
    
    // Fill the count array
    for (i=0; i<length; i++){
        freq[(arr[i]/bit_place)%10]++;
    }
    
    //Cumulatively add the frequency array
    for (i = 1; i<10; i++){
        freq[i] += freq[i-1];
    }
    int x,key; //key means the bit place digit at the designated bit place
    for(i= length-1;i>=0;i--){
        x = arr[i];
        key = (x/bit_place)%10;
        output[freq[key] - 1] = x;
        freq[key]--;
    }
    for (i = 0; i<length; i++){
        arr[i] = output[i];
    }
}
