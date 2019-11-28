//
//  KruskalMST.cpp
//  data_structures
//
//  Created by Bharat Mukheja on 11/12/19.
//  Copyright © 2019 Bharat Mukheja. All rights reserved.
//

#include <iostream>
#include "graph.cpp"
#include <list>
#include "disjoint_sets.cpp"

/*
 Date: 11/12/2019
 @author Bharat Mukheja
 
 Problem: Find minimum spanning tree using Kruskal's algorithm
 
 Time Complexity - O(ElogE)
 Space Complexity - O(E + V)
 
 References
 https://en.wikipedia.org/wiki/Kruskal%27s_algorithm
 
 */


class Graph{
public:
    std::list<Edge> getAllEdges();
    std::list<Node> getAllVertex();
};

class KruskalMST{
public:
    static bool comparator(Edge edge1, Edge edge2){
        return edge1.weight < edge2.weight;
    }
    
    
    std::list<Edge> getMST(Graph graph){
        std::list<Edge> allEdges = graph.getAllEdges();
        allEdges.sort(comparator);
        DisjointSet disjointSet;
        
        for (Node node: graph.getAllVertex()){
            disjointSet.makeSet(node);
        }
        
        std::list<Edge> resultEdge;
        
        for (Edge edge: allEdges){
            int node1 = disjointSet.findSet(edge.vertex1.data);
            int node2 = disjointSet.findSet(edge.vertex2.data);
            
            if (node1 == node2){
                continue;
            } else{
                resultEdge.push_back(edge);
                disjointSet.Union(edge.vertex1.data, edge.vertex2.data);
            }
            
        }
        return resultEdge;
    }
};

