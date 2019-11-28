from graph import Graph
import math
from priority_queue import PriorityQueue

def dijkstra():
    graph = Graph(6)

    graph.addEdge(0,1,2)
    graph.addEdge(0,2,4)

    graph.addEdge(1,2,1)
    graph.addEdge(1,3,7)

    graph.addEdge(2,4,3)

    graph.addEdge(3,5,1)

    graph.addEdge(4,3,2)
    graph.addEdge(4,5,5)

    sourceVertex: int = 0

    distances = dict()
    for nbr,wgt in graph.getNeighborsWithWeights(sourceVertex):
        distances[nbr] = wgt

    #Mark remaining distances as infinity
    for vertex in graph.getAllVertices():
        if vertex != sourceVertex and vertex not in distances:
            distances[vertex] = math.inf

    print(distances)
    pq = PriorityQueue()
    #Add all the distances in a priority queue
    for node, distance in distances.items():
        pq.push(node,distance)

    visited = set()
    #In a loop select all the nodes from priority queue

    while not pq.is_empty():
        du, u = pq.pop()
        visited.add(u)
        for v,cuv in graph.getNeighborsWithWeights(u):
            # Relax the edge
            if du + cuv < distances[v]:
                distances[v] = du + cuv
                if v not in visited:
                    pq.update(v,distances[v])

    print(distances)
    print("done")

dijkstra()
