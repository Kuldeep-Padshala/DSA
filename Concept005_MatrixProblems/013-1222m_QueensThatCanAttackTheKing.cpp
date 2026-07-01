// LC: 1222 m 

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        
        vector<vector<bool>> board(8, vector<bool>(8, false));

        for(auto& q: queens){
          board[q[0]][q[1]] = true;
        }
        vector<vector<int>> ans;

        int dx[8] = {-1, -1, -1, 0, 1, 1,  1,  0};
        int dy[8] = {-1,  0,  1, 1, 1, 0, -1, -1};

        int x = king[0], y = king[1];
        for(int i=0; i<8; i++){

            int row = x + dx[i];
            int col = y + dy[i];

            while (row>=0 && row<8 && col>=0 && col<8){

              if(board[row][col]) {
                ans.push_back({row, col});
                break;
              }
              row += dx[i]; 
              col += dy[i];
            }
        }
        return ans;
    }
};