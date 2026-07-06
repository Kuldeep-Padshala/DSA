// LC: 807 m 

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<int> row(n), col(n);

        for(int i=0; i<n; i++){
            
          int mx1 = -1;
          int mx2 = -1;

          for(int j=0; j<n; j++){
            mx1=max(mx1,grid[i][j]);
            mx2=max(mx2,grid[j][i]);
          }

          col[i] = mx2;
          row[i] = mx1;
        }

        int ans=0;
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            
            ans += abs(min(row[i],col[j]) - grid[i][j]);
          }
        }
        return ans;
    }
};