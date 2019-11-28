from __future__ import annotations
from priority_queue import PriorityQueue
from typing import List, Tuple, Dict



def a_star(maze: List[list], start: Tuple[int,int], end: Tuple[int,int]):
    # Store G,H anf D values
    G = {}
    H = {}
    F = {}
    parent:Dict[Tuple,Tuple] = {}


    #Create start node and end node
    G[start] = F[start] = H[start] = 0
    parent[start] = None
    G[end] = H[end] = F[end] = 0

    end_node = end

    open_list = PriorityQueue()
    open_list.push(start,F[start])
    closed_list = set()

    while not open_list.is_empty():
        cur_node_f, cur_node = open_list.pop()

        if cur_node == end_node:
            path = []
            current = cur_node
            while current is not None:
                path.append(current)
                current = parent[current]
            return path[::-1]

        closed_list.add(cur_node)

        #Get adjacent 8 nodes
        for x_step, y_step in [
            (0,1),
            (0,-1),
            (1,1),
            (1,-1),
            (1,0),
            (-1,0),
            (-1,-1),
            (-1,1)
        ]:
            next_pos = (cur_node[0] + x_step, cur_node[1] + y_step)
            
            # Make sure indices acceptable
            if next_pos[0] <0 or next_pos[0]>(len(maze)-1) or next_pos[1]<0 or next_pos[1]>(len(maze[0])-1):
                continue

            # Make sure walkable i.e. not = 1
            if maze[next_pos[0]][next_pos[1]] != 0:
                continue
            
            if next_pos in closed_list:
                continue

            # Create new node
            next_node = next_pos
            parent[next_node] = cur_node


            next_node_g = G[cur_node] + 1
            next_node_h = ((next_node[0] - end_node[0]) ** 2) + ((next_node[1] - end_node[1]) ** 2) #Euclidean distance as heuristic

            if not open_list.contains(next_node):
                open_list.push(next_node, next_node_g + next_node_h)
            elif G[next_node]<next_node_g:
                continue #This G score is worse then previously found
            

            G[next_node] = next_node_g
            H[next_node] = next_node_h
            F[next_node] = next_node_g + next_node_h
            parent[next_node] = cur_node

    # If unable to find a solution till now        
    raise RuntimeError("A* failed to find a solution")




if __name__ == "__main__":
    maze = [[0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
            [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
    
    start = (0,0)
    end = (7,6)

    path = a_star(maze, start, end)
    print(path)

            


