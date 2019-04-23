//Given an array A of non-negative integers, return an array consisting of all the even elements of A, 
//followed by all the odd elements of A.
//You may return any answer array that satisfies this condition.
//Speed: (32ms) faster than 78.78% of C++ submissions; MEM: less than 98.07% of C++ submissions

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		vector<int> even;
		vector<int> odd;

		for (int x : A) {
			if (x % 2 == 0) { even.push_back(x); }
			else odd.push_back(x);
		}
		for (int x : odd) { even.push_back(x); }
		return even;


	}
};