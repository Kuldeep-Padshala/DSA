// LC: 1260 e 

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        
        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
              
            int newJ = (j+k) % n; // (j + numbers of columns added)%m
            
            int newI = (i+(j+k)/n) % m; // (i + numbers of rows added)%n 
            
            ans[newI][newJ] = grid[i][j];
          }
        }
        return ans;
    }
};