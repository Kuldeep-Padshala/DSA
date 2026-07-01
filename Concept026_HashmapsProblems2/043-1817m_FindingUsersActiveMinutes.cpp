// LC: 1817 m 

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        
        // userid -> times
        unordered_map<int, unordered_set<int>> mp1;

        // UAM -> userid
        unordered_map<int, int> mp2;

        for(auto& log: logs){
          mp1[log[0]].insert(log[1]);
        }
        for(auto it=mp1.begin(); it!=mp1.end(); it++){
          mp2[it->second.size()]++;
        }


        vector<int> ans(k,0);

        for(int i=0; i<k; i++){
          if(mp2.find(i+1) != mp2.end()){
            ans[i] = mp2[i+1];
          }
        }

        return ans;
    }
};