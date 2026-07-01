// LC: 1277 m 

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prev(m, 0), curr(m, 0);
        int sum = 0;

        for(int i=0; i<n; i++){
          for(int j=0; j<m; j++){

            if(matrix[i][j] == 1){
              if(i == 0 || j == 0)
                curr[j] = 1;
              else
                curr[j] = 1 + min({prev[j], curr[j-1], prev[j-1]});
            } 
            else{
              curr[j] = 0;
            }
            sum += curr[j];
        }
        prev = curr;                 // move row
        fill(curr.begin(), curr.end(), 0);
        }
        return sum;

        // vector<vector<int>> dp(n, vector<int>(m, 0));
        // int sum = 0;

        // for(int i=0; i<n; i++){
        //   dp[i][0] = matrix[i][0];
        //   sum += dp[i][0];
        // }
        // for(int j=0; j<m; j++){
        //   dp[0][j] = matrix[0][j];
        //   sum += dp[0][j];
        // }
        // sum -= dp[0][0];

        // for(int i=1; i<n; i++){
        //   for(int j=1; j<m; j++){

        //     if(matrix[i][j] != 0){
        //       dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
        //       sum += dp[i][j];
        //     }
        //   }
        // }
        // return sum;

    }
};