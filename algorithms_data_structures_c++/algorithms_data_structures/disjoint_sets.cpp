//
//  disjoint_sets.cpp
//  data_structures
//
//  Created by Bharat Mukheja on 11/11/19.
//  Copyright © 2019 Bharat Mukheja. All rights reserved.
//

#include <iostream>
#include <map>



class Node{
    int rank;
    int data;
    Node* parent;
public:
    Node(int data){
        this->rank = 0;
        this->data = data;
        this->parent = this;
    }
    friend class DisjointSet;
};
class Edge{
public:
    int weight;
    Node* vertex1;
    Node* vertex2;
};

class DisjointSet {
private:
    std::map<int, Node*> map;
public:
    void makeSet(Node* node){
        this->makeSet(node->data);
    }
    void makeSet(int data){
        Node* node = new Node(data);
        this->map[data] = node;
    }
    void Union(int a1, int b1){
        
        a1 = findSet(a1);
        b1 = findSet(b1);
        Node* a = map[a1];
        Node* b = map[b1];
        Node* parent;
        Node* child;
        
        if (a->rank == b->rank || a->rank > b->rank){
            parent = a;
            child = b;
        } else{
            parent = b;
            child = a;
        }
        
        child->parent = parent;
        if (parent->rank == child->rank){
            parent->rank++;
        }
        child->rank = 0;
    }
    void pathCompression(Node* root);
    
    
    
    int findSet(int data){
        Node* elem = map[data];
    while (elem->parent && elem->parent != elem){
        elem = elem->parent;
        }
    return elem->data;
    }
    
    
    
};


void DisjointSetUsingMap(){
    DisjointSet ds;
    ds.makeSet(1);
    ds.makeSet(2);
    ds.makeSet(3);
    ds.makeSet(4);
    ds.makeSet(5);
    ds.makeSet(6);
    ds.makeSet(7);
    
    ds.Union(1,2);
    ds.Union(2,3);
    ds.Union(4,5);
    ds.Union(6,7);
    ds.Union(5,6);
    ds.Union(3,7);
    
    std::cout<<(ds.findSet(1))<<std::endl;
    std::cout<<(ds.findSet(2))<<std::endl;
    std::cout<<(ds.findSet(3))<<std::endl;
    std::cout<<(ds.findSet(4))<<std::endl;
    std::cout<<(ds.findSet(5))<<std::endl;
    std::cout<<(ds.findSet(6))<<std::endl;
    std::cout<<(ds.findSet(7))<<std::endl;
    
}
