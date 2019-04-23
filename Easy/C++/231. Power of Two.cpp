/*
Given an integer, write a function to determine if it is a power of two.

Runtime: 4 ms, faster than 100.00% of C++ online submissions for Power of Two.
Memory Usage: 8 MB, less than 70.21% of C++ online submissions for Power of Two.
*/

class Solution {
public:
	bool isPowerOfTwo(int n) {
		//count number of 1s in binary
		//if more than 1 cannot be power of 2
		if (n < 0) return false;

		int count = 0;
		while (n != 0) {
			n &= n - 1;
			++count;
		}
		if (count > 1 || count == 0) return false;
		else return true;
	}
};