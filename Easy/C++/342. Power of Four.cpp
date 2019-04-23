/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Runtime: 8 ms, faster than 38.73% of C++ online submissions for Power of Four.
Memory Usage: 8.1 MB, less than 52.11% of C++ online submissions for Power of Four.
*/

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num <= 1) return num == 1 ? true : false;

		bool flag = false;
		unsigned int mask = 1;
		//int b = num&mask;
		int power = 0;
		for (int i = 0; i < 32; ++i) {
			if (num&mask) {
				if (flag) return false;
				else { flag = true; power = i; }
			}
			mask = mask << 1;
		}


		if (power % 2 == 0 && power > 1) return true;
		else return false;
