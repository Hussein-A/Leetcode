/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
Note: For the purpose of this problem, we define empty string as valid palindrome.

Runtime: 16 ms, faster than 22.68% of C++ online submissions for Valid Palindrome.
Memory Usage: 9.8 MB, less than 5.19% of C++ online submissions for Valid Palindrome.
*/

class Solution {
public:
	bool isPalindrome(string& s) {
		if (s.size() <= 1) return true;
		string temp;
		for (char c : s) { if (isalnum(c)) { if (isalpha(c)) temp += tolower(c); else temp += c; } }
		s = temp;

		string reversed_s = s; reverse(reversed_s.begin(), reversed_s.end());
		for (int i = 0; i <= s.size() / 2; ++i) {
			if (tolower(s[i]) != tolower(reversed_s[i])) return false;
		}


		return true;
	}
};