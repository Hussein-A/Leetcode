/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

Runtime: 32 ms, faster than 40.66% of C++ online submissions for Course Schedule II.
Memory Usage: 12.8 MB, less than 65.07% of C++ online submissions for Course Schedule II.
*/

class Solution {
public:
#define undiscovered 0
#define discovered 1
#define processed 2

	bool flag = true;
	vector<int> order;
	void dfs(vector<vector<int>>& graph, vector<int>& states, const int& start) {
		states[start] = discovered;
		auto edge = graph[start].begin();

		while (edge != graph[start].end()) {
			if (states[*edge] == discovered) { flag = false; return; }//must be a backedge, not a DAG return.
			if (states[*edge] == undiscovered) { dfs(graph, states, *edge); }
			++edge;
		}
		states[start] = processed;
		order.push_back(start);
	}

	vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		//implement a topological sort

		//make graph
		vector<vector<int>> graph(numCourses);
		vector<int> states(numCourses);
		for (auto p : prerequisites) { graph[p.second].push_back(p.first); }

		//go through all connected components
		auto it = find(states.begin(), states.end(), 0);
		while (it != states.end()) {
			dfs(graph, states, distance(states.begin(), it));
			//check in case dfs found a backedge
			if (flag == false) { order = {}; cout << "IMPOSSIBLE!\n"; return order; }
			it = find(states.begin(), states.end(), 0);
		}
		reverse(order.begin(), order.end());
		return order;

	}
};