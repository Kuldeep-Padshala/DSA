// LC: 1411 h 

class Solution {

      static const int MOD = 1e9 + 7;

      int recur(int row, int n, int p1, int p2, int p3) {

        // Base case: all rows painted
        if (row == n)
            return 1;

        int ways = 0;

        // Try all color combinations for current row
        for(int c1=0; c1<3; c1++){
          for(int c2=0; c2<3; c2++){
            for (int c3=0; c3<3; c3++){

              // Same row constraint
              if(c1==c2 || c2==c3){
                continue;
              }

              // Vertical constraint with previous row
              if(row>0){
                if(c1 == p1 || c2 == p2 || c3 == p3){
                  continue;
                }
              }
              ways += recur(row + 1, n, c1, c2, c3);

            }
          }
        }

        return ways;
      }

      int recurMemo(int row, int n, int p1, int p2, int p3, vector<vector<vector<vector<int>>>>& dp) {

        // Base case
        if(row == n){
          return 1;
        }

        int &res = dp[row][p1+1][p2+1][p3+1];
        if(res != -1){
          return res;
        }

        long long ways = 0;

        for(int c1=0; c1<3; c1++){
          for(int c2=0; c2<3; c2++){
            for(int c3=0; c3<3; c3++){

              // same row constraint
              if(c1 == c2 || c2 == c3){
                continue;
              }

              // vertical constraint
              if(p1 != -1 && (c1 == p1 || c2 == p2 || c3 == p3)){
                continue;
              }

              ways += recurMemo(row + 1, n, c1, c2, c3, dp);
              ways %= MOD;
            }
          }
        }

        return res = ways;
    }

public:
    int numOfWays(int n) {

        // Recursion
        // return recur(0, n, -1, -1, -1);

        // topDown
        vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(4, vector<vector<int>>(4, vector<int>(4, -1))));
        return recurMemo(0, n, -1, -1, -1, dp);

    }
};