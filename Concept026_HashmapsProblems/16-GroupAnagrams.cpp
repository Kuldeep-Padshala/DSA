// LC: 49 m

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map <string ,vector<string>> main_map;
        vector<vector<string>> ans;

        for(string s : strs){
          string sorted = s;
          sort(sorted.begin(), sorted.end());
          main_map[sorted].push_back(s);
        }

        for(auto& pair : main_map){
          ans.push_back(pair.second);
        }
        return ans;
    }
};