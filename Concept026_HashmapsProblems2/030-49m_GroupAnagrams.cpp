// LC: 49 m 

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map <string ,vector<string>> mp;
        vector<vector<string>> ans;

        for(string s: strs){
          string sorted = s;
          sort(sorted.begin(), sorted.end());
          mp[sorted].push_back(s);
        }

        for(auto& pair : mp){
          ans.push_back(pair.second);
        }
        return ans;
    }
};