/*
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting from the start of the string. If there are less than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, 
then reverse the first k characters and left the other as original.

Runtime:  beats 98.87 % of cpp submissions.
MEM: 9.3 MB
*/

class Solution {
public:
	string reverseStr(string s, int k) {

		for (int i = 0; 2 * k*i < s.size(); ++i) {
			auto first = s.begin() + 2 * k*i;
			auto last = first + k > s.end() ? s.end() : first + k;
			reverse(first, last);
		}
		return s;
	}
};