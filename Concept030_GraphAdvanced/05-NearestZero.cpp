// LC: 542 m 

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // push all 0 into queue
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            if(mat[i][j] == 0){
              q.push({i,j});
              dist[i][j]=0;
            }
          }
        }

        vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // bfs
        while(!q.empty()){

          int row = q.front().first;
          int col = q.front().second;
          q.pop();

          for(auto [del_row, del_col] : directions){
            
            int nrow = row + del_row;
            int ncol = col + del_col;
            //                                                or mat[row][col] == 1
            if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && dist[nrow][ncol] == -1) {
              
              dist[nrow][ncol] = dist[row][col] + 1;
              q.push({nrow, ncol});
            }
          }
        }
        return dist;
    }
};
