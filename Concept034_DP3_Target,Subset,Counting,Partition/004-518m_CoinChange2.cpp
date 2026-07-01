// LC: 518 m 

class Solution {

      int recur(int idx, int tgt, vector<int>& coins){

        // base case
        if (idx == 0) 
        return (tgt % coins[0] == 0);

        int notTake=0, take=0;
        if(coins[idx] <= tgt){
          take = recur(idx, tgt-coins[idx], coins);
        }
        notTake = recur(idx-1, tgt, coins);

        return take + notTake;
      }

      int recurMemo(int idx, int tgt, vector<int>& coins, vector<vector<int>>& dp){

        // base case
        if (idx == 0) 
        return (tgt % coins[0] == 0);

        // check dp
        if(dp[idx][tgt] != -1){
          return dp[idx][tgt];
        }

        int notTake=0, take=0;
        if(coins[idx] <= tgt){
          take = recurMemo(idx, tgt-coins[idx], coins, dp);
        }
        notTake = recurMemo(idx-1, tgt, coins, dp);

        return dp[idx][tgt] = take + notTake;
      }

      int tabulation(int amount, vector<int>& coins) {
        
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        // base case
        for (int tgt = 0; tgt <= amount; tgt++) {
            dp[0][tgt] = (tgt % coins[0] == 0);
        }

        for (int idx = 1; idx < n; idx++) {
            for (int tgt = 0; tgt <= amount; tgt++) {

                int notTake = dp[idx - 1][tgt];
                int take = 0;

                if (coins[idx] <= tgt)
                    take = dp[idx][tgt - coins[idx]];

                dp[idx][tgt] = take + notTake;
            }
        }

        return dp[n - 1][amount];
      }


public:
    int change(int amount, vector<int>& coins) {


        int n = coins.size();

        // Recursion
        // return recur(n-1, amount, coins);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // return recurMemo(n-1, amount, coins, dp);

        // BottomUp (TLE)
        // return tabulation(amount, coins);

        // BottomUp Space Optimized
        vector<long long> dp(amount + 1, 0);                    // TLE for <int>
        dp[0] = 1;                          // only one way

        for(int c : coins) {
          for(int i = c; i <= amount; i++) {
            if(dp[i-c] >= INT_MAX || dp[i]>=INT_MAX) continue;
            dp[i] += dp[i-c];
          }
        }
        return (int)dp[amount];

        // coins: 1 2 5    amount: 5

        // dp[0] = 1               dp[0] = 1 ()
        // dp[1] = 1               dp[1] = 1 (1)
        // dp[2] = 1               dp[2] = 2 (1,1)     added: (2) from dp[0]
        // dp[3] = 1               dp[3] = 2 (1,1,1)   added: (1,2) from dp[1]
        // dp[4] = 1               dp[4] = 3 (1,1,1,1) added: (1,1, 2)(2, 2) from dp[2]
        // dp[5] = 1(1,1,1,1,1)    dp[5] = 3 (1,1,1,1) added: (1,1,1, 2)(1,2, 2)

    }
};