from graph import Graph
from dfs import DFS
from bfs import BFS

graph = Graph(8)
graph.addEdge(0,1)
graph.addEdge(0,2)
graph.addEdge(0,3)
graph.addEdge(0,5)

graph.addEdge(1,2)

graph.addEdge(2,5)

graph.addEdge(3,5)

graph.addEdge(4,5)

graph.addEdge(5,7)

graph.addEdge(7,6)

print(DFS.dfs(graph,0,4))
print(BFS.bfs(graph,0,4))

print(DFS.dfs(graph,0,7))
print(BFS.bfs(graph,0,7))
