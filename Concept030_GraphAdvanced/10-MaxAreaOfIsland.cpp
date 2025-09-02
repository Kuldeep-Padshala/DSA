// LC: 695 m 

class Solution {

  void bfs(int row, int col, vector<vector<int>>& grid, int& count){

    int m = grid.size();
    int n = grid[0].size();
    
    queue<pair<int, int>> q;

    // visited[row][col] = true;
    grid[row][col] = 0;
    count++;
    q.push({row, col});

    while(!q.empty()){

      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      // travel 4 directions
      //                                     up    down    left   right
      vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

      for(auto [del_row, del_col] : directions){
        
        int nrow = row + del_row;
        int ncol = col + del_col;
        // Check bounds & if land & not visited
        if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == 1) {
          
          // visited[nrow][ncol] = true;
          grid[nrow][ncol] = 0;
          count++;
          q.push({nrow, ncol});
        }
      }
    }

  }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<bool>> visited(m, vector<bool>(n, false));   ani jagya , mark grid[i][j] '0' after visiting
        int ans=0;

        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){

            if(grid[i][j] == 1){
              int curr=0;
              bfs(i, j, grid, curr);
              ans = max(ans, curr);
            }
          }
        }

        return ans;

    }
};