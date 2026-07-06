class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        //

        int m = board.size();
        int n = board[0].size();

        vector<vector<int>> ans = board;

        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){

            vector<int> temp(4, 0);

            if(i>0 && j>0) temp[board[i-1][j-1]]++;
            if(i>0) temp[board[i-1][j]]++;
            if(i>0 && j<n-1) temp[board[i-1][j+1]]++;
            if(j>0) temp[board[i][j-1]]++;
            if(j<n-1) temp[board[i][j+1]]++;
            if(i<m-1 && j>0) temp[board[i+1][j-1]]++;
            if(i<m-1) temp[board[i+1][j]]++;
            if(i<m-1 && j<n-1) temp[board[i+1][j+1]]++;

            // int live = temp[1] + temp[2];

            // if(board[i][j]==0 && live==3){
            //   board[i][j] = 3;
            // }
            // else if(board[i][j]==1 && (live<2 || live>3)){
            //   board[i][j] = 2;
            // }

            if((board[i][j]==0) && (temp[1]+temp[2])==3){
              board[i][j] = 3; 
            }
            else if(((temp[1]+temp[2])<2 || (temp[1]+temp[2])>3) && board[i][j]==1){
              board[i][j] = 2;
            }
          }
        }

        for(int i=0; i<m; i++){
          for(int j=0; j<n; j++){
              
            if(board[i][j] == 2){
              board[i][j] = 0; // Finalize live -> dead
            } 
            else if(board[i][j] == 3) {
              board[i][j] = 1; // Finalize dead -> live
            }
          }
        }
        
        // int m = board.size();
        // int n = board[0].size();

        // vector<vector<int>> ans = board;

        // for(int i=0; i<m; i++){
        //   for(int j=0; j<n; j++){

        //     vector<int> temp(2, 0);

        //     if(i>0 && j>0) temp[board[i-1][j-1]]++;
        //     if(i>0) temp[board[i-1][j]]++;
        //     if(i>0 && j<n-1) temp[board[i-1][j+1]]++;
        //     if(j>0) temp[board[i][j-1]]++;
        //     if(j<n-1) temp[board[i][j+1]]++;
        //     if(i<m-1 && j>0) temp[board[i+1][j-1]]++;
        //     if(i<m-1) temp[board[i+1][j]]++;
        //     if(i<m-1 && j<n-1) temp[board[i+1][j+1]]++;

        //     if(board[i][j]==0 && temp[1]==3) ans[i][j] = 1;
        //     if(temp[1]<2 || temp[1]>3) ans[i][j] = 0;
        //   }
        // }
        // board = ans;
        
    }
};