// LC: 130 m 

class Solution {
  void dfs(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& board){

    visited[row][col] = true;

    int m = board.size();
    int n = board[0].size();

    vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    for(auto& [del_row, del_col]: directions){

      int nrow = row + del_row;
      int ncol = col + del_col;

      if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && !visited[nrow][ncol] && board[nrow][ncol]=='O') {     
        dfs(nrow, ncol, visited, board);
      }
    }
    
  }
public:
    void solve(vector<vector<char>>& board) {
        
        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // first anf last row
        for(int j = 0; j < n; j++){
          if(board[0][j] == 'O' && !visited[0][j]){
           dfs(0, j, visited, board); 
          }
          if(board[m-1][j] == 'O' && !visited[m-1][j]){
            dfs(m-1, j, visited, board);
          }
        }

        // first and last columns
        for(int i = 0; i < m; i++) {
          if(board[i][0] == 'O' && !visited[i][0]){
            dfs(i, 0, visited, board);
          }
          if(board[i][n-1] == 'O' && !visited[i][n-1]){
            dfs(i, n-1, visited, board);
          }
        }

        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
            if(!visited[i][j] && board[i][j]=='O'){
              board[i][j] = 'X';
            }
          }
        }


    }
};