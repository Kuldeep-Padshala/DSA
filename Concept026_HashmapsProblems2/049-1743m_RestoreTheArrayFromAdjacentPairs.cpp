// LC: 1743 m 

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;
        unordered_set<int> s;
        vector<int> ans;

        for(auto& adj: adjacentPairs){

          int u = adj[0], v = adj[1];
          if(mp1.find(u) == mp1.end()){
            mp1[u] = v;
          }
          else{
            mp2[u] = v; 
          }

          if(mp1.find(v) == mp1.end()){
            mp1[v] = u;
          }
          else{
            mp2[v] = u; 
          }

          if(mp2.find(u) == mp2.end()) s.insert(u);
          else s.erase(u);

          if(mp2.find(v) == mp2.end()) s.insert(v);
          else s.erase(v);
        }

        int curr = *s.begin();
        int prev = -1e9;
        ans.push_back(curr);

        int n = adjacentPairs.size() + 1;

        for(int i=1; i<n; i++){
          
          int nextVal;
          if(mp1.count(curr) && mp1[curr] != prev) {
            nextVal = mp1[curr];
          } 
          else{
            nextVal = mp2[curr];
          }
          
          ans.push_back(nextVal);
          prev = curr;
          curr = nextVal;
        }
        return ans;
    }
};