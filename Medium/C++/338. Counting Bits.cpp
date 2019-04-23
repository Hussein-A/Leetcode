/*
Given a non negative integer number num. For every numbers i in the range 
0 <= i <= num calculate the number of 1's in their binary representation and return them as an array.

Runtime: 68 ms, faster than 25.66% of C++ online submissions for Counting Bits.
Memory Usage: 9.4 MB, less than 97.47% of C++ online submissions for Counting Bits.
*/

class Solution {
	int count_ones(int n) {
		int count = 0;
		while (n != 0) {
			n &= n - 1;
			++count;
		}
		return count;
	}
public:
	vector<int> countBits(int num) {
		vector<int> numbits(num + 1);
		for (int i = 0; i <= num; ++i) {
			numbits[i] = count_ones(i);
		}
		return numbits;
	}
};