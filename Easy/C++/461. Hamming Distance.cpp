/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.
Given two integers x and y, calculate the Hamming distance.
Note: 0 <= x, y < 231.

Runtime: 4 ms, faster than 100.00% of C++ online submissions for Hamming Distance.
Memory Usage: 8.2 MB, less than 99.64% of C++ online submissions for Hamming Distance.
*/

class Solution {
public:
	int hammingDistance(int x, int y) {
		int binary = x ^ y;
		int count = 0;
		//count how many 0s in binary
		while (binary != 0) {
			binary &= binary - 1;
			++count;
		}
		return count;
	}
};