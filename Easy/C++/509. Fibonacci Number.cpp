/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

Runtime: 8 ms, faster than 38.08% of C++ online submissions for Fibonacci Number.
Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Fibonacci Number.
*/

class Solution {
public:
	int fib(int N) {
		if (N == 0) return 0;
		if (N == 1 || N == 2) return 1;

		return fib(N - 1) + fib(N - 2);
	}
};