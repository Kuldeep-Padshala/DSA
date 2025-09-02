// LC: 1034 m 

class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        int m = grid.size();
        int n = grid[0].size();

        int original = grid[row][col];   // original color of component

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        queue<pair<int,int>> q;
        q.push({row, col});
        visited[row][col] = true;

        // store border cells
        vector<pair<int,int>> borders;

        // directions
        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()){

          row = q.front().first;
          col = q.front().second;
          q.pop();

          bool isBorder = false;

          for(auto& [del_row, del_col] : directions){

            int nrow = row + del_row;
            int ncol = col + del_col;

            // if nrow ncol is out of bounds  →  row col is border cell
            if(nrow < 0 || ncol < 0 || nrow >= m || ncol >= n){
              isBorder = true;
              continue;
            }

            // if neighbor has different color → border
            if(grid[nrow][ncol] != original){
              isBorder = true;
              continue;
            }

            // if same color and not visited → add to queue
            if(!visited[nrow][ncol]){
              visited[nrow][ncol] = 1;
              q.push({nrow, ncol});
            }
          }

          if(isBorder){
            borders.push_back({row, col});
          }
        }

        for(auto& it : borders){
          grid[it.first][it.second] = color;
        }

        return grid;
    }
};