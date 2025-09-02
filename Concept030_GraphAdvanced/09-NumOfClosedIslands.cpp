class Solution {

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    
private:
    void dfs(int row, int col, vector<vector<int>>& grid, bool &isClosed){

        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds or land
        if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 1){
          return;
        }

        // If on the border, not closed
        if(row == 0 || col == 0 || row == m-1 || col == n-1){
            isClosed = false;
            // return;     // fun will not return here, it will mark all adjacent lands as visible
        }

        // visited[row][col] = true;
        grid[row][col] = 1;             // make it water, same as marking visited

        for(auto& [dr, dc] : directions){
          
          // int nrow = row + dr;
          // int ncol = col + dc;
          // if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && grid[nrow][ncol] == 0){
          //   dfs(nrow, ncol, visited, grid, isClosed);
          // }

          dfs(row+dr, col+dc, grid, isClosed);
        }
    }

public:
    int closedIsland(vector<vector<int>>& grid){

        int m = grid.size();
        int n = grid[0].size();
        // vector<vector<bool>> visited(m, vector<bool>(n, false));

        int ans = 0;
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){

            if(grid[i][j] == 0){     // for all lands which is not already visited
              bool isClosed = true;
              dfs(i, j, grid, isClosed);
              if(isClosed){
                ans++;
              }

            }
          }
        }
        return ans;
    }
};


class Solution {
private:
    vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    void dfs(int row, int col, vector<vector<int>>& grid){
      int m = grid.size();
      int n = grid[0].size();

      if(row < 0 || col < 0 || row >= m || col >= n || grid[row][col] == 1){
        return;
      }

      grid[row][col] = 1;
      for(auto& [dr, dc] : directions){
        dfs(row + dr, col + dc, grid);
      }
    }

public:
    int closedIsland(vector<vector<int>>& grid){
        
        int m = grid.size();
        int n = grid[0].size();

        // Step 1: Remove all border-connected lans
        for(int i = 0; i < m; i++){
          if(grid[i][0] == 0){
            dfs(i, 0, grid);
          }
          if(grid[i][n-1] == 0){
            dfs(i, n-1, grid);
          }
        }
        for(int j = 0; j < n; j++){
          if(grid[0][j] == 0){
            dfs(0, j, grid);
          }
          if(grid[m-1][j] == 0){
            dfs(m-1, j, grid);
          }
        }

        // Step 2: Count closed islands
        int count = 0;
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            if(grid[i][j] == 0){
              count++;
              dfs(i, j, grid);
            }
          }
        }
        return count;
    }
};
