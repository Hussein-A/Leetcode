/*
Given a string, you need to reverse the order of characters in each word 
within a sentence while still preserving whitespace and initial word order.

Runtime: 128 ms, faster than 6.35% of C++ online submissions for Reverse Words in a String III.
Memory Usage: 271.6 MB, less than 6.25% of C++ online submissions for Reverse Words in a String III.
*/

class Solution {
public:
	string reverseWords(string s) {
		istringstream ist{ s };
		string temp;
		string reversed;
		while (ist >> temp) {
			reverse(temp.begin(), temp.end());
			reversed = reversed + temp + " ";
		}
		reversed.erase(reversed.end() - 1); //remove the last space
		return reversed;

	}
};
