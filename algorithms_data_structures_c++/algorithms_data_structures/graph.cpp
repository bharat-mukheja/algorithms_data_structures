//
//  graph.cpp
//  data_structures
//
//  Created by Bharat Mukheja on 11/2/19.
//  Copyright © 2019 Bharat Mukheja. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <array>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef vector<list<pair<int,int>>> adjlist;


// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

class Graph{
private:
    int N;
    adjlist adjList;
public:
    Graph(int N){
        this->N = N;
        this->adjList.resize(N);
        for (int i = 0; i<N; i++){
            this->adjList[i] = list<pair<int,int>>();
        }
    };
    
    int getNodeCount(){return this->N;}
    
    void addEdge(int node1, int node2, int weight){
        this->adjList[node1].push_back(std::make_pair(node2,weight));
    }
    void addEdge(int node1, int node2){
        addEdge(node1, node2, 1);
    }
    
    int getEdge(int node1, int node2){
        if (node1 >= this->N || node2 >= this->N || node1 < 0 || node2 < 0){
            return -10000;
        }
        list<pair<int,int>>::iterator it;
        for (it = adjList[node1].begin(); it != adjList[node1].end(); ++it){
            if ((*it).first == node2){
                return (*it).second;
            }
        };
        return 10000;
    }
    
    vector<int> getNeighbors(int node){
        list<pair<int,int>>::iterator it;
        vector<int> neighbors;
        for (it = this->adjList[node].begin(); it!= this->adjList[node].end();++it){
            neighbors.push_back((*it).first);
        }
        return neighbors;
    }
    
    vector<pair<int,int>> getNeighborsWithWeights(int node){
        list<pair<int,int>>::iterator it;
        vector<pair<int,int>> neighbors;
        for (it = this->adjList[node].begin(); it!= this->adjList[node].end();++it){
            neighbors.push_back(*it);
        }
        return neighbors;
    }
    
    int* getAllVertices(){
        int vertices[N];
        for(int i =0;i<N;i++)
            vertices[i] = i;
        return vertices;
    }
    
    unordered_set<pair<int,int>,hash_pair> getAllEdges(){
        unordered_set<pair<int,int>,hash_pair> edges;
        adjlist::iterator cur_node;
        int cur_node_name = 0;
        for(cur_node = this->adjList.begin(); cur_node!= this->adjList.end(); ++cur_node, cur_node_name++){
            list<pair<int,int>>::iterator nbr;
            int nbr_name;
            pair<int,int> key;
            for (nbr = (*cur_node).begin(); nbr!= (*cur_node).end();++nbr){
                nbr_name = (*nbr).first;
                key = make_pair(min(cur_node_name,nbr_name), max(cur_node_name,nbr_name));
                edges.insert(key);
            }
        }
        return edges;
    }
    
    unordered_map<pair<int,int>,int, hash_pair> getAllEdgesWithWeights(){
        unordered_map<pair<int,int>,int, hash_pair> edges_weights;
        adjlist::iterator cur_node;
        int cur_node_name = 0;
        for(cur_node = this->adjList.begin(); cur_node!= this->adjList.end(); ++cur_node, cur_node_name++){
            list<pair<int,int>>::iterator nbr;
            int nbr_name;
            int edge_weight;
            pair<int,int> key;
            for (nbr = (*cur_node).begin(); nbr!= (*cur_node).end();++nbr){
                nbr_name = (*nbr).first;
                edge_weight = (*nbr).second;
                key = make_pair(min(cur_node_name,nbr_name), max(cur_node_name,nbr_name));
                edges_weights.insert(make_pair(key,edge_weight));
            }
        }
        return edges_weights;
    }
    
    
};


