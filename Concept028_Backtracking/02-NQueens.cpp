// LC: 51 h

class Solution {
public:

void addSolution(vector<vector<string>>& board, vector<vector<string>>& ans, int n){

  vector<string> temp;
  
  for(int i=0; i<n; i++){
    string row = "";
    for(int j=0; j<n; j++){
      row += board[i][j];
    }
    temp.push_back(row);
  }
  ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<string>>& board, int n){

  int x=row;
  int y=col;

  // left thi right fill kari chhi, atle only left side j check karvani

  // same row mate check
  while(y>=0){
    if(board[x][y]=="Q"){
      return false;
    }
    y--;
  }


  // diagonal 1 mate
  x=row;
  y=col;

  while(x>=0 && y>=0){       // next column mate top left check
    
    if(board[x][y]=="Q"){
      return false;
    }
    y--;
    x--;
  }

  // diagonal 2 mate
  x=row;
  y=col;

  while(x<n && y>=0){           // bottom left check
    
    if(board[x][y]=="Q"){
      return false;
    }
    y--;
    x++;
  }
  return true;


}

void solve(int col, int n, vector<vector<string>>& ans, vector<vector<string>>& board){

  // base case
  if(col==n){
    addSolution(board, ans, n);
    return;
  }

  // solve 1 case
  for(int row=0; row<n; row++){
    if(isSafe(row, col, board, n)){

      board[row][col] = "Q";
      solve(col+1, n, ans, board);

      // backtrack
      board[row][col] = ".";
    }
  }
}
    vector<vector<string>> solveNQueens(int n) {
        // Backtracking
        // ek column ma badhi row trace kari ne joi chhi, baki recursion

        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans ;

        solve(0, n, ans, board);

        return ans;
    }
};