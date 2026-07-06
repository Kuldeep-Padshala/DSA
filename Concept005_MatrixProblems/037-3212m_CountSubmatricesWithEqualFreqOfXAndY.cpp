// LC: 3212 m 

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int, int>>> prefixSum(m, vector<pair<int, int>>(n));

        int ans = 0;

        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
            
            int x = 0, y = 0;
            if(i>0){
              x += prefixSum[i-1][j].first;
              y += prefixSum[i-1][j].second;
            }
            if(j>0){
              x += prefixSum[i][j-1].first;
              y += prefixSum[i][j-1].second;
            }
            if(i>0 && j>0){
              x -= prefixSum[i-1][j-1].first;
              y -= prefixSum[i-1][j-1].second;
            }
            if(grid[i][j] == 'X') x++;
            if(grid[i][j] == 'Y') y++;

            if(x == y && x>0) ans++;

            prefixSum[i][j] = {x,y};
          }
        }

        return ans;
    }
};