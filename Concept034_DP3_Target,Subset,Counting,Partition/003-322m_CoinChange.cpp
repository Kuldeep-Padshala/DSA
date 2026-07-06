// LC: 322 m 


// in infinite supply, whenever you take, stand at the same index

class Solution {

      int recur(int idx, int amt, vector<int>& coins){

        // Base case
        if(idx==0){
          if(amt % coins[0] == 0){
            return amt/coins[0];
          }
          else{
            return 1e9;
          }
        }

        int notTake = 0 + recur(idx-1, amt, coins);
        int take = INT_MAX;
        if(coins[idx] <= amt){
          take = 1 + recur(idx, amt - coins[idx], coins);
        }
        return min(take, notTake);
      }

      int recurMemo(int idx, int amt, vector<int>& coins, vector<vector<int>>& dp){

        // Base case
        if(idx==0){
          if(amt % coins[0] == 0){
            return amt/coins[0];
          }
          else{
            return 1e9;
          }
        }

        // check dp
        if(dp[idx][amt] != -1){
          return dp[idx][amt];
        }

        int notTake = 0 + recurMemo(idx-1, amt, coins, dp);
        int take = INT_MAX;
        if(coins[idx] <= amt){
          take = 1 + recurMemo(idx, amt - coins[idx], coins, dp);
        }
        return dp[idx][amt] = min(take, notTake);
      }

      int tabulation(vector<int>& coins, int amount){

        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        for(int i=0; i<=amount; i++){
          if(i % coins[0] == 0){
            dp[0][i] = i / coins[0];
          }
          else{
            dp[0][i] = 1e9;
          }
        }

        for(int idx=1; idx<n; idx++){
          for(int amt=0; amt<=amount; amt++){

            int notTake = 0 + dp[idx-1][amt];
            int take = INT_MAX;
            if(coins[idx] <= amt){
              take = 1 + dp[idx][amt - coins[idx]];
            }
            dp[idx][amt] = min(take, notTake);
          }
        }

        if(dp[n-1][amount] >= 1e9) return -1;
        else return dp[n-1][amount];
      }


public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();
        
        // Recursion
        // int ans = recur(n-1, amount, coins);
        // if(ans >= 1e9) return -1;
        // else return ans;

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = recurMemo(n-1, amount, coins, dp);
        // if(ans >= 1e9) return -1;
        // else return ans;

        // BottomUp
        return tabulation(coins, amount);

        // DP BottomUp: Tabulation
        // vector<int> dp(amount+1, INT_MAX);
        // dp[0] = 0;

        // for(int i=1; i<=amount; i++){

        //   for(int c : coins){

        //     if( i-c >= 0 && dp[i-c] != INT_MAX){
        //       // 
        //       dp[i] = min(dp[i], dp[i-c] + 1);
        //     }
        //   }
        // }
        // if(dp[amount] != INT_MAX) return dp[amount];
        // else return -1;
    }
};