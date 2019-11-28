from graph import Graph

class DFS(Graph):
    @staticmethod
    def dfs(graph:Graph, source: int, destination: int):
        visited: set = set()
        return DFS.helper(graph, source,destination,visited)

    @staticmethod
    def helper(graph:Graph, cur_node:int, destination:int, visited:set):
        if cur_node in visited:
            return False
        visited.add(cur_node)

        if cur_node == destination:
            return True
        for nbr in graph.getNeighbors(cur_node):
            if DFS.helper(graph, nbr,destination,visited):
                return True

        return False

