// LC: 554 m 

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        
        int n = wall.size();
        unordered_map<long long, int> mp;
        
        int maxi = 0;         // most occurence of an edge

        for(auto& row: wall){

          long long edge = 0;
          int m = row.size();

          for(int brick=0; brick<m-1; brick++){

            int len = row[brick];
            edge = edge + len;
            mp[edge]++;
            maxi = max(maxi, (mp[edge]));
          }
        }

        return n - maxi;
    }
};