/*
Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.

Runtime: 4 ms, faster than 100.00% of C++ online submissions for Ugly Number.
Memory Usage: 8.1 MB, less than 40.17% of C++ online submissions for Ugly Number.
*/

class Solution {
public:
	bool isUgly(int num) {
		if (num == 0) return false;
		else if (num == 1) return true;
		//find highest power of 2, 3 and 5 dividing num
		// divide the num by the product of those, if the remainder isnt 1 then is not an ugly number

		//get highest power of 2,3,5 remainder must be 1

		while (num % 2 == 0) { num /= 2; }
		while (num % 3 == 0) { num /= 3; }
		while (num % 5 == 0) { num /= 5; }

		if (num != 1) return false;
		else return true;
	}
};