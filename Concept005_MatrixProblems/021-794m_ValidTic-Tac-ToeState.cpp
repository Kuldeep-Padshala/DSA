// LC: 794 m 

class Solution {

    bool isWinner(vector<string>& board, char ch) {

        for(int i=0; i<3; i++){
            
          if(board[i] == string(3, ch) || 
            (board[0][i] == ch && board[1][i] == ch && board[2][i] == ch)) {
              return true;
          }
        }
        return (board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) ||
               (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch);
    }
public:
    bool validTicTacToe(vector<string>& board) {
        
        int x = 0, o = 0;
        for(int i=0; i<3; i++){
          for(int j=0; j<3; j++){
            if(board[i][j] == 'O') o++;
            else if(board[i][j] == 'X') x++;
          }
        }

        if(!( x-o == 0 || x-o == 1)) return false;

        bool xWins = isWinner(board, 'X');
        bool oWins = isWinner(board, 'O');

        if (xWins && oWins) return false;

        if (xWins && x != o+1) return false;
        if (oWins && x != o) return false;

        return true;
    }
};

/*
xxx
xoo
oo
*/