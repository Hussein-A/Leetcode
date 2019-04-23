/*
Given an integer, write a function to determine if it is a power of three.

Runtime: 60 ms, faster than 40.19% of C++ online submissions for Power of Three.
Memory Usage: 8.2 MB, less than 20.65% of C++ online submissions for Power of Three.
*/

class Solution {
public:
	bool isPowerOfThree(int n) {
		if (n % 3 != 0 && n != 1) return false;

		for (int i = 0; pow(3, i) <= n; ++i) { if (pow(3, i) == n) return true; }
		return false;
	}
};