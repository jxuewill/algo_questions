/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res; //what you are returning
        unordered_map<string, vector<string>>m; //vector of strings, use the sorted word as the key 
        for (int i = 0; i< strs.size(); i++){
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(temp);
        }
        
        for (auto it = m.begin(); it != m.end(); it++){
            res.push_back(it->second);
        }
        return res;
        
    }
};
