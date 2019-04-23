/*
Given an undirected graph, return true if and only if it is bipartite.

Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such 
that every edge in the graph has one node in A and another node in B.

The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes 
i and j exists.  Each node is an integer between 0 and graph.length - 1.  
There are no self edges or parallel edges: graph[i] does not contain i, and it doesn't contain any element twice.

Runtime: 28 ms, faster than 75.31% of C++ online submissions for Is Graph Bipartite?.
Memory Usage: 11.2 MB, less than 98.48% of C++ online submissions for Is Graph Bipartite?.
*/

class Solution {
public:

	bool flag = true;
	void bfs(vector<vector<int>>& graph, vector<int>& colors, vector<int>& state, const int start) {
		//do bfs
		//initialize
		queue<int> myqueue; myqueue.push(start);
		colors[start] = 1;
		state[start] = 1;

		int curr = start;
		while (!myqueue.empty()) {
			curr = myqueue.front();

			for (const int& neighbor : graph[curr]) {
				if (state[neighbor] == 0) {
					state[neighbor] = 1;
					//set color
					if (colors[curr] == 1) colors[neighbor] = 2;
					else colors[neighbor] = 1;
					myqueue.push(neighbor);
				}

				else {//already seen or processed, check color
					if (colors[curr] == colors[neighbor]) flag = false;
				}
			}
			state[curr] = 2;
			myqueue.pop();
		}
	}

	bool isBipartite(vector<vector<int>>& graph) {
		if (graph.size() == 0) return true;
		vector<int> colors(graph.size(), 0);//0 for uncolored, 1 for red, 2 for blue
		vector<int> state(graph.size(), 0);//0 for undiscovered, 1 for discovered, 2 for processed
		auto it = find(state.begin(), state.end(), 0);

		while (it != state.end()) {
			bfs(graph, colors, state, distance(state.begin(), it));
			if (flag == false) return false;
			it = find(state.begin(), state.end(), 0);
		}

		//check

		return flag;
	}
};