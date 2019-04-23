//Write a function that reverses a string. 
//The input string is given as an array of characters char[].
//Do not allocate extra space for another array, you must do this by modifying the input array 
//in - place with O(1) extra memory. You may assume all the characters consist of printable ascii characters.
//Speed (64ms) Faster than 36.68% of C++ submissions; Mem: (15.2mb) Less than 98.64% of C++ submissions

class Solution {
public:
	string reverseString(string s) {
		int i = 0, j = s.size() - 1;
		if (j == -1) return;

		while (i < j) {
			swap(s[i++], s[j--]);
		}

		return s;
	}
};