// LC: 1293 m Shortest Path in a Grid with Obstacles Elimination

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        
        int m = grid.size();
        int n = grid[0].size();

        if (k >= m+n-2){        // m-1 + n-1
          return n+m-2;
        }

        // minObs[r][c] = min obstacles eliminated to reach (r,c)
        vector<vector<int>> minObs(m, vector<int>(n, INT_MAX));
        minObs[0][0] = 0;

        // visited[r][c] = whether we ever pushed (r,c) in queue
        // vector<vector<bool>> visited(m, vector<bool>(n, false));
        // visited[0][0] = true;

        queue<tuple<int,int,int,int>> q; // {r, c, steps, used}
        q.push({0, 0, 0, 0});

        int del_row[4] = {-1, 1, 0, 0};
        int del_col[4] = {0, 0, -1, 1};

        while(!q.empty()){

            auto [row, col, steps, used] = q.front();
            q.pop();

            for(int d=0; d<4; d++){

                int nrow = row + del_row[d];
                int ncol = col + del_col[d];

                if(nrow<0 || nrow>=m || ncol<0 || ncol>=n){              // out of bound
                  continue;
                }

                int newUsed = used + grid[nrow][ncol];

                // if we already found a path to (nrow,ncol) with fewer or equal eliminations, skip
                if(newUsed >= minObs[nrow][ncol] || newUsed > k){
                  continue;                             // no need for visited cause of this
                }

                minObs[nrow][ncol] = newUsed;

                if(nrow == m-1 && ncol == n-1){
                  return steps + 1;
                }

                q.push({nrow, ncol, steps+1, newUsed});
                // visited[nrow][ncol] = true;
            }
        }

        return -1;
    }
};