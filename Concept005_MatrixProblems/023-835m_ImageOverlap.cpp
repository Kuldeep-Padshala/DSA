// LC: 835 m 

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        
        // map
        
        int n = img1.size();

        vector<pair<int,int>>first;
        vector<pair<int,int>>second;

        for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){

            if(img1[i][j]==1){
              first.push_back({i,j});
            }
            if(img2[i][j]==1){
              second.push_back({i,j});
            }
          }
        }

        int ans=0;

        map<pair<int,int>,int> mp;

        for(auto [i1,j1]:first){
          for(auto [i2,j2]:second){
            
            int x = i1-i2;
            int y = j1-j2;

            mp[{x,y}]++;
            ans = max(ans,mp[{x,y}]);
            
          }
        }
        return ans;
    }
};