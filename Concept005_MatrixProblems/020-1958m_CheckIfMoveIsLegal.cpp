// LC: 1958 m 

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        
        int dr[8] = {-1,-1,-1,0,1,1,1,0};
        int dc[8] = {-1,0,1,1,1,0,-1,-1};

        char opp = (color == 'B') ? 'W' : 'B';

        for(int i=0; i<8; i++){
            
          int cnt = 0;
          int nrow = rMove + dr[i];
          int ncol = cMove + dc[i];

          while(nrow >= 0 && ncol >= 0 && nrow < 8 && ncol < 8) {
              
              if(board[nrow][ncol] == '.'){
                break;
              }

              if(board[nrow][ncol] == opp){
                cnt++;
              } 
              else if (board[nrow][ncol] == color) {       
                if (cnt >= 1) return true;
                else break;
              } 
              else {
                break;
              }

              nrow = nrow + dr[i];
              ncol = ncol + dc[i];
          }
        }

        return false;
    }
};