//
//  Dijkstra.cpp
//  data_structures
//
//  Created by Bharat Mukheja on 11/15/19.
//  Copyright © 2019 Bharat Mukheja. All rights reserved.
//

#include <iostream>
#include <map>
#include <queue>
#include <list>

std::map<Node,int> shortestPathUsingDijkstra(Graph graph, Node sourceVertex){
    //We need a priority queue to store the minimum distance nodes
    std::priority_queue<int, Node> pq;
    pq.push(0,sourceVertex);
    
    
    std::map<Node,int> distance_from_source;
    
    while (!pq.empty()){
        Node curNode = pq.pop(0);
        std::list<Node> nbrs = curNode.getAllNeighbors();
        for (Node nbr: nbrs){
            // Check if the cur distance to that node is more than going via the
            // current node
            if (node.distance > curDistance + graph.getEdge(curNode,nbr).weight){
                node.distance = curDistance + graph.getEdge(curNode,nbr).weight;
            }
        }
    }
}

typedef std::pair<int,int> iPair;

class Graph {
    int V;
    std::list<iPair> *adj;
    
public:
    Graph(int V);
    
    void addEdge(int u, int v, int w);
    
    void shortestPath(int s);
}
Graph:: Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v,int w){
    adj[u].push_back(std::make_pair(v,w));
    adj[v].push_back(std::make_pair(u,w));
}


void Graph::shortestPath(int src){
    
    std::priority_queue<iPair, std::vector<iPair>, std::greater<iPair>> pq;
    
    std::vector<int> dist(V,INF);
    
    pq.push(std::make_pair(0,src));
    dist[src] = 0;
    
    while(!pq.empty()){
        
        int u = pq.top().second;
        pq.pop();
        
        std::list<iPair>::iterator i;
        for (i = adj[u].begin(); i!=adj[u].end(); ++i){
            int v = (*i).first;
            int weight = (*i).second;
            
            if (dist[v] > dist[u] + weight){
                
                dist[v] = dist[u] + weight;
                pq.push(std::make_pair(dist[v],v));
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}


int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
  
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
  
    g.shortestPath(0);
  
    return 0;
} 
