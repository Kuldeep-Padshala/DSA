// LC: 102 m 

class Solution {

    void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& grid){

        visited[row][col] = true;
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for(auto& [dr, dc] : directions){
          
          int nr = row + dr;
          int nc = col + dc;
          if (nr >= 0 && nc >= 0 && nr < m && nc < n && !visited[nr][nc] &&
            grid[nr][nc] == 1) {
            dfs(nr, nc, visited, grid);
          }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // First and last row
        for(int j = 0; j < n; j++){
          if(grid[0][j] == 1 && !visited[0][j]){
            dfs(0, j, visited, grid);
          }
          if(grid[m - 1][j] == 1 && !visited[m - 1][j]) {
            dfs(m - 1, j, visited, grid);
          }
        }

        // First and last column
        for(int i = 0; i < m; i++){
          if(grid[i][0] == 1 && !visited[i][0]){
            dfs(i, 0, visited, grid);
          }
          if(grid[i][n - 1] == 1 && !visited[i][n - 1]){
            dfs(i, n - 1, visited, grid);
          }
        }

        // Count enclaves
        int count = 0;
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            if (grid[i][j] == 1 && !visited[i][j]) {
              count++;
            }
          }
        }
        return count;
    }
};
