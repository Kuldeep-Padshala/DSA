// LC: 1282 m 

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        
        int n = groupSizes.size();
        unordered_map<int, vector<int>> mp;
        vector<vector<int>> ans;
        
        for(int i=0; i<n; i++){
          
          int grp = groupSizes[i];
          mp[grp].push_back(i);
          
          if(mp[grp].size() == grp){
            ans.push_back(mp[grp]);
            mp[grp].clear();
          }
        }
        return ans;
    }
};