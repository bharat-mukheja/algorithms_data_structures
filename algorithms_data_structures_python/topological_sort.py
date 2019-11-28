from graph import Graph

def topological_sort(graph: Graph):
    stack = list()
    visited = set()

    for vertex in graph.getAllVertices():
        if vertex in visited:
            continue
        topological_sort_util(graph, vertex, stack, visited)
    return stack[::-1]

def topological_sort_util(graph: Graph, vertex: int, stack: list, visited: set):
    visited.add(vertex)
    for nbr in graph.getNeighbors(vertex):
        if nbr in visited:
            continue
        topological_sort_util(graph, nbr, stack, visited)
    stack.append(vertex)
    return stack

if __name__ == "__main__":
    graph = Graph(8)
    graph.addEdge(0,2)
    graph.addEdge(1,2)
    graph.addEdge(1,3)
    graph.addEdge(2,4)
    graph.addEdge(4,7)
    graph.addEdge(3,5)
    graph.addEdge(4,5)
    graph.addEdge(5,6)

    print(topological_sort(graph))