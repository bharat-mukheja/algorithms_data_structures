from typing import List, Tuple, Dict
import math

class Graph:
    N: int
    adjList: List[List[Tuple]]

    def __init__(self,N) -> None:
        self.N = N
        self.adjList = [[] for _ in range(N)]

    def addEdge(self, node1: int, node2: int, weight: int = 1) -> None:
        self.adjList[node1].append((node2,weight))

    def getEdge(self, node1: int, node2: int) -> int:
        """
        :param node1: first node
        :param node2: second node
        :return: weight if edge exists, infinity if edge doesn't exist, negative infinity if node doesn't exist
        """
        if node1 < 0 or node1 >= self.N or node2<0 or node2>= self.N:
            return int(-math.inf)

        for node,weight in self.adjList[node1]:
            if node == node2:
                return weight
        return int(math.inf)

    def getAllVertices(self) -> List[Tuple]:
        return [x for x in range(self.N)]

    def getAllEdges(self) -> List[Tuple]:
        output: set = set()
        for node1, nbrs in enumerate(self.adjList):
            for node2, _ in nbrs:
                output.add((min(node1,node2),max(node1,node2)))
        return list(output)

    def getAllEdgesWithWeights(self) -> List[Dict[Tuple,int]]:
        output: set[Tuple] = set()
        for node1, nbrs in enumerate(self.adjList):
            for node2, weight in nbrs:
                output.add((min(node1,node2),max(node1,node2),weight))
        return list(output)

    def getNeighbors(self, node: int):
        adj = self.adjList[node]
        return [edge[0] for edge in adj]

    def getNeighborsWithWeights(self,node) -> List[Tuple]:
        return self.adjList[node]

    def dfs(self):
        pass

    def bfs(self):
        pass

N = 4

if __name__ == "__main__":
    graph = Graph(N)

    graph.addEdge(0,1)
    graph.addEdge(0,2)

    graph.addEdge(1,2)

    graph.addEdge(2,3)


    for edge in graph.getAllEdges():
        print(f"{edge[0]} -> {edge[1]}")


