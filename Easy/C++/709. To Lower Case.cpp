//Implement function ToLowerCase() that has a string parameter str, and returns the same string in lowercase.
//Speed: (4ms) Faster than 100% of C++ submissions; Mem: (8.2mb) less than 56.25% of C++ submissions

class Solution {
public:
	string toLowerCase(string str) {
		for (char& c : str) {
			if ('A' <= c && c <= 'Z') c = c - 'A' + 'a';
		}
		return str;
	}
};