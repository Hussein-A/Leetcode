/*
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group.
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.

Runtime: 200 ms, faster than 84.94% of C++ online submissions for Possible Bipartition.
Memory Usage: 49.8 MB, less than 77.14% of C++ online submissions for Possible Bipartition.
*/



class Solution {
public:
#define undiscovered 0
#define discovered 1
#define processed 2

#define red 0
#define blue 1

	bool isbipartite(vector<vector<int>>& graph, vector<int>& states, vector<int>& colors, const int& start) {
		queue<int> myqueue; myqueue.push(start);
		states[start] = discovered;//0, 1 or 2
		colors[start] = red; // 0 or 1

		while (!myqueue.empty()) {
			int curr = myqueue.front();
			for (int& neighbor : graph[curr]) {
				if (states[neighbor] == undiscovered) {
					states[neighbor] = discovered;
					colors[neighbor] = colors[curr] == red ? blue : red;
					myqueue.push(neighbor);
				}
				else {
					if (colors[neighbor] == colors[curr]) return false;
				}
			}

			states[curr] = processed;
			myqueue.pop();
		}

		for (int i = 0; i < states.size(); ++i) { if (states[i] == undiscovered) return isbipartite(graph, states, colors, i); }
		return true;
	}

	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		//convert to graph first
		vector<vector<int>> graph(N);
		for (const vector<int>& v : dislikes) {
			graph[v[0] - 1].push_back(v[1] - 1); graph[v[1] - 1].push_back(v[0] - 1); //undirected graph, hence two copies of same edge in adj list
		}
		vector<int> states(N); vector<int> colors(N);
		return isbipartite(graph, states, colors, 0);

	}
};