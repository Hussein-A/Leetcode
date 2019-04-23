//

class Solution {
public:
	int numUniqueEmails(vector<string>& emails) {
		map<string, int> email_addresses;
		for (string s : emails) {
			string local;
			string domain;
			int pos_delim = s.find('@');
			for (int i = 0; i < pos_delim; ++i) {
				if (s[i] == '.') {} //do nothing, ignore
				else if (s[i] == '+')break;//ignore everything after the first '+'
				else { local += s[i]; } //must be an okay character, carry on
			}
			for (int i = pos_delim; i < s.size(); ++i) { domain += s[i]; }
			++email_addresses[local + domain];
		}
		int sum = 0;
		for (const auto& p : email_addresses) {
			++sum;
		}
		return sum;
	}
};