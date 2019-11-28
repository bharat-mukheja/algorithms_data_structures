//
//  main.cpp
//  data_structures
//
//  Created by Bharat Mukheja on 11/2/19.
//  Copyright © 2019 Bharat Mukheja. All rights reserved.
//

#include <iostream>
#include "graph.cpp"
#include "sorting.cpp"

const int N = 4;

template<int N>
void print_array(int (&array)[N]){
    for (const auto& e : array) {
        std::cout << e << " "<<std::flush;
    }
    cout<<endl;
}

void test_graph(){
    Graph graph(N);
    
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    
    graph.addEdge(1,2);

    graph.addEdge(2,3);
    
    for (auto edge : graph.getAllEdges()){
        cout<<edge.first<<" -> "<<edge.second<<endl;
    }
}


void test_array_sorting(){
    int array[9] = {8, 3, 1, 2, 6, 4, 7, 9, 5};
    cout<<"Original Array:"<<endl;
    print_array(array);
    
    Sorting sort;
    
    sort.heap_sort(array,9);
    cout<<"Sorted with Heap Sort:"<<endl;
    print_array(array);
    
    int array2[9] = {8, 3, 1, 2, 6, 4, 7, 9, 5};
    sort.merge_sort(array2, 9);
    cout<<"Sorted with Merge Sort:"<<endl;
    print_array(array2);
    
    int array3[9] = {8, 3, 1, 2, 6, 4, 7, 9, 5};
    sort.quick_sort(array3, 9);
    cout<<"Sorted with Quick Sort:"<<endl;
    print_array(array3);
    
    int array4[9] = {8, 3, 1, 2, 6, 4, 7, 9, 5};
    sort.insertion_sort(array4, 9);
    cout<<"Sorted with Insertion Sort:"<<endl;
    print_array(array4);
    
    int array5[9] = {8, 3, 1, 2, 6, 4, 7, 9, 5};
    sort.radix_sort(array5, 9);
    cout<<"Sorted with Radix Sort:"<<endl;
    print_array(array5);
}


int main(int argc, const char * argv[]) {
    test_array_sorting();
    
    return 0;
}
