// LC: 79 m

class Solution {

  int del_row[4]={-1,1,0,0};
  int del_col[4]={0,0,-1,1};

    bool solve(int row,int col,vector<vector<char>>& board,int m,int n,int index,string &word,int size,vector<vector<bool>>&vis){

        // base case
        if(index==size){
          return true;
        }

        vis[row][col]=true;

        for(int i=0;i<4;i++){

          int nrow = row + del_row[i];
          int ncol = col + del_col[i];

          if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[nrow][ncol]==false){

            if(board[nrow][ncol]==word[index]){
              if(solve(nrow, ncol, board, m, n, index+1, word, size, vis)){
                return true;
              }
            }
          }
        }
        vis[row][col]=false;
        return false;
    }

    bool helper(int row,int col,vector<vector<char>>& board,int m,int n,int index,string &word,int size){
          
        if(index==size) return true;

        char ch=board[row][col];
        board[row][col]='$';

        for(int i=0;i<4;i++){

          int nrow = row + del_row[i];
          int ncol = col + del_col[i];

          if(nrow>=0 and nrow<m and ncol>=0 and ncol<n ){

            if(board[nrow][ncol]==word[index]){
              if(helper(nrow,ncol,board,m,n,index+1,word,size)){
                return true;
              }
            }
          }
        }
        board[row][col]=ch;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {


        // Backtracking with In-Place Modification

        int m=board.size();
        int n=board[0].size();
        char ch=word[0];
        int size=word.size();
      
        for(int i=0; i<m; i++){
           for(int j=0; j<n; j++){

            if(board[i][j]==ch){

              if(helper(i, j, board, m, n, 1, word, size)){
              return true;
              }
            }
           }
        }
        return false;
        
        // backtracking with 2d visited array

        int m=board.size();
        int n=board[0].size();
        char ch=word[0];
        int size=word.size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
      
        for(int i=0; i<m; i++){
           for(int j=0; j<n; j++){

            if(board[i][j]==ch){
              if(solve(i, j, board, m, n, 1, word, size, visited)){
                return true;
              }
            }
           }
        }
        return false;
    }
};