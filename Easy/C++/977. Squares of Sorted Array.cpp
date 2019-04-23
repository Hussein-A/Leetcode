//Given an array of integers A sorted in non-decreasing order, 
//return an array of the squares of each number, also in sorted non-decreasing order.
//Speed: (120ms) faster than 58.03% of C++ submissions; Memory: (15.7mb) less than 8.19% of C++ submissions

class Solution {
public:
	vector<int> merge2sorted(vector<int> left, vector<int> right) {
		vector<int> sorted(left.size() + right.size());
		int l{ 0 };
		int r{ 0 };
		int pos{ 0 };
		while (l < left.size() && r < right.size()) {
			if (left[l] < right[r]) sorted[pos++] = left[l++];
			else sorted[pos++] = right[r++];
		}

		//copy rest
		while (l < left.size()) { sorted[pos] = left[l++]; ++pos; }
		while (r < right.size()) { sorted[pos] = right[r++]; ++pos; }
		return sorted;
	}

	vector<int> sortedSquares(vector<int>& A) {
		vector<int> neg;
		vector<int> pos;
		for (int x : A) {
			if (x < 0) neg.push_back(x);
			else pos.push_back(x);
		}
		for (int& x : neg) x *= x;
		for (int& x : pos) x *= x;
		reverse(neg.begin(), neg.end());

		return merge2sorted(neg, pos);


	}
};