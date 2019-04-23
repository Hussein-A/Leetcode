/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only

Memory Usage: 9.1 MB, less than 59.80% of C++ online submissions for Length of Last Word.

*/

class Solution {
public:
	int lengthOfLastWord(string s) {
		stringstream ss{ s };
		string word;
		while (!ss.eof()) {
			ss >> word;
		}
		return word.size();
	}
};