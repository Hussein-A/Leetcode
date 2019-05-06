/*
Given an array of strings, group anagrams together.

Runtime: 44 ms, faster than 89.03% of C++ online submissions for Group Anagrams.
Memory Usage: 20.1 MB, less than 59.24% of C++ online submissions for Group Anagrams.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        
        unordered_map<string,vector<string>> mymap;
        for (const string& word : strs){
            string temp = word; sort(temp.begin(), temp.end());
            mymap[temp].push_back(word);
        }
        for (auto it : mymap){
            result.push_back(it.second);
        }
        return result;
    }
};
