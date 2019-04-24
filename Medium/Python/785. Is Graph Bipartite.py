"""
Given an undirected graph, return true if and only if it is bipartite.
Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.
The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  
Each node is an integer between 0 and graph.length - 1.  
There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Runtime: 48 ms, faster than 80.24% of Python3 online submissions for Is Graph Bipartite?.
Memory Usage: 13.2 MB, less than 5.62% of Python3 online submissions for Is Graph Bipartite?.
"""

class Solution:
    def bfs(self, graph: List[List[int]], state: List[int], color: List[int], start)-> bool:
        undiscovered, discovered, processed = 0, 1,2
        uncolored, red, blue = 0, 1, 2
        
        #assumes graph of at least 1 vertex
        myqueue = collections.deque()
        myqueue.append(start)
        color[start] = red
        
        while myqueue:
            node = myqueue.popleft()
            for neighbor in graph[node]:
                if state[neighbor] == undiscovered:
                    state[neighbor] = discovered
                    color[neighbor] = red if color[node] == blue else blue
                    myqueue.append(neighbor)
                else:
                    if color[neighbor] == color[node]:
                        return False
            state[node] = processed
        return True
        
    
    def isBipartite(self, graph: List[List[int]]) -> bool:
        #is bipartite if can be 2 colored
        state = [0]*len(graph)
        color = [0]*len(graph)
        
        #deal with all connected components
        while 0 in state:
            pos = state.index(0)
            if not self.bfs(graph, state, color, pos): return False
            
        return True
        
