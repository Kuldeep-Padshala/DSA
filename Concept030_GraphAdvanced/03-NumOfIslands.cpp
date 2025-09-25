// LC: 200 m 

class Solution {

  void bfs(int row, int col, vector<vector<char>>& grid){

    int m = grid.size();
    int n = grid[0].size();
    
    queue<pair<int, int>> q;

    // visited[row][col] = true;
    grid[row][col]='0';
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
        if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == '1') {
          
          // visited[nrow][ncol] = true;
          grid[nrow][ncol] = '0';
          q.push({nrow, ncol});
        }
      }




      // if(r-1 >= 0 && !visited[r-1][c] && grid[r-1][c] == '1'){
      //   visited[r-1][c] = true;
      //   q.push({r-1, c});
      // }
      // // down
      // if(r+1 < m && !visited[r+1][c] && grid[r+1][c] == '1'){
      //   visited[r+1][c] = true;
      //   q.push({r+1, c});
      // }
      // // left
      // if(c-1 >= 0 && !visited[r][c-1] && grid[r][c-1] == '1'){
      //   visited[r][c-1] = true;
      //   q.push({r, c-1});
      // }
      // // right
      // if(c+1 < n && !visited[r][c+1] && grid[r][c+1] == '1'){
      //   visited[r][c+1] = true;
      //   q.push({r, c+1});
      // }
    }


  }
public:
    int numIslands(vector<vector<char>>& grid) {
        
        // * 4 directions

        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<bool>> visited(m, vector<bool>(n, false));   ani jagya , mark grid[i][j] '0' after visiting
        int ans=0;

        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){

            if(grid[i][j]=='1'){
              bfs(i, j, grid);
              ans++;
            }
          }
        }
        return ans;
    }
};

// SC: O(n*n)
// TC: O(n*n)