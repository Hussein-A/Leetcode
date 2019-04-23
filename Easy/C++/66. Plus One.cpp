/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

Runtime: 4 ms, faster than 100.00% of C++ online submissions for Plus One.
Memory Usage: 8.4 MB, less than 99.80% of C++ online submissions for Plus One.
*/

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int last = digits.size() - 1;
		int pos = last - 1;
		if (digits.size() == 1 && digits[0] == 9) { digits.push_back(1); digits[0] = 0; swap(digits[0], digits[digits.size() - 1]); return digits; }
		else if (digits.size() == 1) { ++digits[0]; return digits; }
		else if (digits[last] < 9) ++digits[last];
		else {
			digits[last] = 0;
			while (pos >= 0) {
				if (pos == 0 && digits[pos] == 9) { digits.push_back(1); digits[0] = 0; swap(digits[0], digits[digits.size() - 1]); --pos; }//increase size of array by one and make the leading digit 1
				else if (digits[pos] == 9) { digits[pos] = 0; --pos; }
				else { ++digits[pos]; return digits; }
			}
		}
		return digits;
	}
};