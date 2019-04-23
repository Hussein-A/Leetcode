/*
Write a function that takes an unsigned integer and return the number of '1' bits it has 
(also known as the Hamming weight).

Runtime: 8 ms, faster than 37.75% of C++ online submissions for Number of 1 Bits.
Memory Usage: 8.1 MB, less than 64.09% of C++ online submissions for Number of 1 Bits.
*/

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;
		while (n != 0) {
			n &= n - 1;
			++count;
		}
		return count;

	}
};