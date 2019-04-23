/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
Note:
	The length of num is less than 10002 and will be >= k.
	The given num does not contain any leading zero.

Runtime: 24 ms, faster than 29.04% of C++ online submissions for Remove K Digits.
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Remove K Digits.
*/

class Solution {
public:
	//idea is to go through the number removing only 1 digit at a time to minimize the resulting number, and continuing this
	//until the number of digits to remove is 0.

	void removedigit(string& num) {
		//if possible to remove a leading digit and a 0, keep removing until remainder does not have a leading 0
		if (num.size() > 1 && num[1] == '0') {
			int i = 0;
			while (num[i + 1] == '0') { ++i; }
			num.erase(num.begin(), num.begin() + i + 1);
			if (num.size() == 0) num = "0";
			return;
		}
		else {
			if (num.size() == 1) { num = "0"; return; }
			auto p = num.begin();
			while (p != num.end() - 1) {
				if (*p <= *(p + 1)) ++p;
				else { num.erase(p); return; }
			}
			num.erase(p);
		}


	}

	string removeKdigits(string num, int k) {
		if (k == 0) return num;
		else if (num.size() == 0) { num = "0"; return num; }

		while (k != 0) { removedigit(num); --k; }
		return num;
	}
};