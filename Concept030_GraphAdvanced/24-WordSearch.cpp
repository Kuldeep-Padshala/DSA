// LC: 79 m 

class Solution {

  bool dfs(int row, int col, int idx, string& word, vector<vector<char>>& board){

    if(idx == word.length()){
      return true;
    }
    int m = board.size();
    int n = board[0].size();

    if(row < 0 || col < 0 || row >= m || col >= n || board[row][col] != word[idx]) {
      return false;
    }

    char temp = board[row][col];
    board[row][col] = '#';
    idx++;

    bool found =   dfs(row+1, col, idx, word, board) 
                || dfs(row-1, col, idx, word, board) 
                || dfs(row, col+1, idx, word, board) 
                || dfs(row, col-1, idx, word, board);

    board[row][col] = temp;

    return found;
  }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0; i<board.size(); i++){
          for(int j=0; j<board[0].size(); j++){
            if(board[i][j] == word[0]){
              if(dfs(i, j, 0, word, board)) return true;
            }
          }
        }
        return false;
    }
};