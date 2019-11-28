from graph import Graph

def has_cycle(graph):
    unvisited = set()
    visiting = set()
    visited = set()

    for vertex in graph.getAllVertices():
        unvisited.add(vertex)

    while unvisited:
        cur_node = unvisited.pop()
        if dfs(graph, cur_node, unvisited, visiting, visited):
            return True

    return False


def dfs(graph: Graph, vertex: int, unvisited: set, visiting:set, visited:set):
    visiting.add(vertex)

    for nbr in graph.getNeighbors(vertex):
        if nbr in visited:
            continue

        if nbr in visiting:
            return True

        if dfs(graph, nbr, unvisited, visiting, visited):
            return True

    visiting.remove(vertex)
    visited.add(vertex)
    return False

if __name__ == "__main__":
    graph = Graph(6)
    graph.addEdge(0,1)
    graph.addEdge(0,2)
    graph.addEdge(1,2)
    graph.addEdge(3,0)
    graph.addEdge(3,4)
    graph.addEdge(4,5)
    graph.addEdge(5,3)

    print(has_cycle(graph))