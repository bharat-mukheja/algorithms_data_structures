from graph import Graph
from collections import deque

class BFS(Graph):
    @staticmethod
    def bfs(graph:Graph, source:int, destination:int):
        visited: set = set()
        queue: deque = deque()
        queue.append(source)

        while queue:
            cur_node = queue.popleft()
            if cur_node in visited:
                continue
            visited.add(cur_node)

            if cur_node == destination:
                return True
            for nbr in graph.getNeighbors(cur_node):
                queue.append(nbr)

        return False

