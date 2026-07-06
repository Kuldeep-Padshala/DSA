class Solution {

    double poured;
    
    double recur(int row, int col) {
        
      // Base case
      if(col<0 || col>row){         // invalid
        return 0.0;
      }
      
      if(row==0 && col==0){       // top glass
        return poured;
      }
      

      double left = (recur(row-1, col-1) - 1.0) / 2.0;          // champagne from left parent
      if(left < 0){
        left = 0;
      }
           
      double right = (recur(row-1, col) - 1.0) / 2.0;           // champagne from right parent
      if(right < 0){
        right = 0;
      }
      
      return left + right;
    }

    double recurMemo(int row, int col, vector<vector<double>>& dp){
        
      // Base case
      if(col<0 || col>row){         // invalid
        return 0.0;
      }
      
      if(row==0 && col==0){       // top glass
        return poured;
      }

      // check dp
      if(dp[row][col] != -1){
        return dp[row][col];
      }
      

      double left = (recurMemo(row-1, col-1, dp) - 1.0) / 2.0;          // champagne from left parent
      if(left < 0){
        left = 0;
      }
           
      double right = (recurMemo(row-1, col, dp) - 1.0) / 2.0;           // champagne from right parent
      if(right < 0){
        right = 0;
      }
      
      return dp[row][col] = left + right;
    }

    double tabulation(int query_row, int query_glass){

      vector<vector<double>> dp(query_row+1, vector<double>(query_row+1, 0));   // query_row instead of glass
      dp[0][0] = poured;

      for(int row=0; row<=query_row; row++){
        for(int col=0; col<=row; col++){           // also change here

          if(row==0 && col==0) continue;

          double left, right;

          if(row==0 || col==0){
            left = 0;
          }
          else{
            left = (dp[row-1][col-1] - 1.0) / 2.0;
            if(left < 0) left = 0;
          }
      
          if(row==0){
            right = 0;
          }
          else{
            right = (dp[row-1][col] - 1.0) / 2.0;           // champagne from right parent
            if(right < 0) right = 0;
          }
          
          dp[row][col] = left + right;
        }
      }

      return min(1.0, dp[query_row][query_glass]);

    }

    
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        
        this->poured = poured;

        // Recursion   
        // double ans = recur(query_row, query_glass);
        // return min(1.0, ans);

        // TopDown

        // vector<vector<double>> dp(query_row+1, vector<double>(query_glass+1, -1.0));
        // double ans = recurMemo(query_row, query_glass, dp);
        // return min(1.0, ans);

        // BottomUp

        return tabulation(query_row, query_glass);
    }
};