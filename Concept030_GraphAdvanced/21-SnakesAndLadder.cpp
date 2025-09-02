// LC: 909 m

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {

        int n = board.size();

        // Step 1: flat board into 1D mapping
        vector<int> flat_board(n*n + 1, -1);
        int cell = 1;
        bool leftToRight = true;

        for(int row = n - 1; row >= 0; row--){

          if(leftToRight){
            for(int col = 0; col < n; col++){
              if(board[row][col] != -1){
                flat_board[cell] = board[row][col];
              }
              cell++;
            }
          } 
          else{
            for(int col = n - 1; col >= 0; col--){
              if (board[row][col] != -1){
                flat_board[cell] = board[row][col];
              }
              cell++;
            }
          }
          leftToRight = !leftToRight;
        }

        // BFS
        queue<int> q;

        //        cell  moves
        // queue<pair<int, int>> q;
        vector<bool> visited(n * n + 1, false);

        q.push(1);
        visited[1] = true;
        int moves = 0;

        while(!q.empty()){

          int size = q.size();

          for(int i=0; i< size; i++){    // if don't want this loop, take one more int in queue moves

            int curr = q.front();
            q.pop();

            if (curr == n*n){
              return moves;
            }
            for(int dice = 6; dice >= 1; dice--){
              
              int next = curr + dice;
              if(next > n*n){
                // break;        // for 1 to 6
                continue;         // for 6 to 1
              }


              if(flat_board[next] != -1){           // snake or ladder
                next = flat_board[next];
              }

              if(!visited[next]) {
                visited[next] = true;
                q.push(next);
                // q.push({next, moves + 1});
              }
            }
   
          }
          moves++;
        }
        return -1;        
    }
};