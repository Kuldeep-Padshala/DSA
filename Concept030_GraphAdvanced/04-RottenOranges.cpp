// LC: 994 m ROTTEN ORSNGES

class Solution {

  void bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid, int& minutes, int& fresh) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()){
          int size = q.size();
            while(size--){
              auto [row, col] = q.front();
              q.pop();

              for (auto [dr, dc] : directions){
                int nr = row + dr;
                int nc = col + dc;

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1){
                  grid[nr][nc] = 2;
                  q.push({nr, nc});
                  fresh--;
                }
              }
            }
          minutes++;
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();

        //                row  col   mins
        queue <pair <pair<int, int>, int> > q;
        int fresh=0;

        // collect all rotten oranges in queue
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            if(grid[i][j] == 2){
             q.push( {{i, j}, 0} );
            }
            else if(grid[i][j] == 1){
              fresh++;
            }
          }
        }

        if(fresh==0) return 0;

        // int minutes = -1;
        // bfs(q, grid, minutes, fresh);

        int time=0;
        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while(!q.empty()){

          int row = q.front().first.first;
          int col = q.front().first.second;
          int mins = q.front().second;
          q.pop();
          time = max(time, mins);

          for(auto [del_row, del_col] : directions){
            
            int nrow = row + del_row;
            int ncol = col + del_col;

            // Check bounds & if land & not visited
            if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == 1) {
              // visited[nrow][ncol] = true;
              grid[nrow][ncol] = 2;
              q.push( {{nrow, ncol}, mins+1} );
              fresh--;
            }
          }
        }

        return fresh == 0 ? time : -1;
    }
};