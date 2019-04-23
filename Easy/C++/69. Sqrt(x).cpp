/*
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Runtime: 4 ms, faster than 100.00% of C++ online submissions for Sqrt(x).
Memory Usage: 8 MB, less than 100.00% of C++ online submissions for Sqrt(x).
*/

class Solution {
public:
	int mySqrt(int n) {
		int low = 1, high = n / 2;//root will always be less than half as long as 4<=n
		int mid;
		while (low < high) {
			mid = low + (high - low) / 2;
			if (mid == n) return mid;
			else if (mid < n / mid) { low = mid + 1; }
			else { high = mid - 1; }
		}
		if (low > n / low) {
			return low - 1;
		}
		else if ((low + 1) <= n / (low + 1)) {
			return low + 1;
		}
		else return low;
	}
};