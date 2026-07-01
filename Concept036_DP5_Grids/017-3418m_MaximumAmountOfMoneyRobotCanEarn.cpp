// LC: 3418 m 

class Solution {

    int recur(int i, int j, int k, vector<vector<int>>& coins) {

        int m = coins.size();
        int n = coins[0].size();

        // out of bounds
        if(i >= m || j >= n) return INT_MIN;

        // destination
        if(i == m-1 && j == n-1){
          
          if(coins[i][j] < 0 && k > 0){
            return 0; // neutralize
          }
          return coins[i][j];
        }

        int val = coins[i][j];

        // move right & down
        int right = recur(i, j + 1, k, coins);
        int down  = recur(i + 1, j, k, coins);

        int best = INT_MIN;

        // case 1: take value normally
        int take = val + max(right, down);
        best = max(best, take);

        // case 2: neutralize (only if negative)
        if(val < 0 && k > 0){
            
          int skip = max(
            recur(i, j+1, k-1, coins),
            recur(i+1, j, k-1, coins)
          );
          best = max(best, skip);
        }

        return best;
    }

    int recurMemo(int i, int j, int k, vector<vector<int>>& coins, auto& dp) {

        int m = coins.size();
        int n = coins[0].size();

        // out of bounds
        if (i >= m || j >= n) return INT_MIN;

        // base case
        if(i == m-1 && j == n-1){
          if(coins[i][j] < 0 && k > 0){
            return 0;   // neutralize
          }
          return coins[i][j];
        }

        // check dp
        if (dp[i][j][k] != -1) return dp[i][j][k];

        int val = coins[i][j];

        int best = INT_MIN;

        // move normally
        int right = recurMemo(i, j+1, k, coins, dp);
        int down  = recurMemo(i+1, j, k, coins, dp);

        int nextBest = max(right, down);

        if(nextBest != INT_MIN){
          best = max(best, val + nextBest);
        }

        // neutralize if negative
        if(val < 0 && k > 0){
            
          int right2 = recurMemo(i, j+1, k-1, coins, dp);
          int down2  = recurMemo(i+1, j, k-1, coins, dp);

          int skipBest = max(right2, down2);

          if(skipBest != INT_MIN){
            best = max(best, skipBest);
          }
        }

        return dp[i][j][k] = best;
    }

public:
    int maximumAmount(vector<vector<int>>& coins) {
        
        int m = coins.size();
        int n = coins[0].size();

        // Recursion
        // return recur(0, 0, 2, coins);

        // TopDown
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1)));
        return recurMemo(0, 0, 2, coins, dp);
        
    }
};