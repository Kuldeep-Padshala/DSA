// LC: 822 m 

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        
        int n = fronts.size();
        int ans = INT_MAX;

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
          if(fronts[i] == backs[i]){
            mp[fronts[i]]++;
          }
        }

        for(int i=0; i<n; i++){
          
          if(!mp.count(fronts[i])){
            ans = min(ans, fronts[i]);
            mp[fronts[i]]++;
          }
          if(!mp.count(backs[i])){
            ans = min(ans, backs[i]);
            mp[backs[i]]++;
          }
        }

        if(ans == INT_MAX){
          return 0;
        }
        return ans;
    }
};