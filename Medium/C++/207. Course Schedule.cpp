/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, 
which is expressed as a pair: [0,1] Given the total number of courses and a list of prerequisite pairs, 
is it possible for you to finish all courses?

Runtime: 20 ms, faster than 95.42% of C++ online submissions for Course Schedule.
Memory Usage: 12.1 MB, less than 73.58% of C++ online submissions for Course Schedule.
*/

class Solution {
public:
#define undiscovered 0
#define discovered 1
#define processed 2

	bool flag = true;
	void dfs(vector<vector<int>>& graph, vector<int>& states, int start) {
		states[start] = discovered;
		auto neighbor = graph[start].begin();

		while (neighbor != graph[start].end()) {
			if (states[*neighbor] == discovered) {
				flag = false;
				return;
			}
			dfs(graph, states, *neighbor);
			++neighbor;
		}

		states[start] = processed;
		return;
	}


	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		//do dfs, if backedge is found then impossible
		//construct graph
		vector<vector<int>> graph(numCourses); if (graph.size() == 0) return true;
		vector<int> states(numCourses);
		for (pair<int, int> edge : prerequisites) {
			graph[edge.second].push_back(edge.first);
		}
		auto it = find(states.begin(), states.end(), undiscovered);
		while (it != states.end()) {
			dfs(graph, states, distance(states.begin(), it));
			it = find(states.begin(), states.end(), undiscovered);
		}
		return flag;

	}
};