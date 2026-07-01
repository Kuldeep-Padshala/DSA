// LC: 123 h 

class Solution {

      int recur(int idx, bool canBuy, int times, int* n, vector<int>& prices){

        // Base case
        if(idx == *n) return 0;
        if(times == 0) return 0;
        

        int profit = 0;
        if(canBuy){
          profit = max( recur(idx+1, false, times, n, prices) - prices[idx],    // bought, so bought value minus, no more buy now
                        recur(idx+1, true, times, n, prices));                  // not bought today, can buy tomorrow
        }
        else{
          profit = max( recur(idx+1, true, times-1, n, prices) + prices[idx],     // sold it, now i can buy again tomorrow
                        recur(idx+1, false, times, n, prices));                 // not sold yet, no more buy 
        }
        return profit;
      }

      int recurMemo(int idx, bool canBuy, int times, int* n, vector<int>& prices, vector<vector<vector<int>>>& dp) {

        // Base cases
        if (idx == *n || times == 0){
          return 0;
        }

        if (dp[idx][canBuy][times] != -1)
            return dp[idx][canBuy][times];

        int profit = 0;

        if(canBuy){
            profit = max( recurMemo(idx + 1, false, times, n, prices, dp) - prices[idx],
                          recurMemo(idx + 1, true, times, n, prices, dp));
        } 
        else{
          profit = max( recurMemo(idx + 1, true, times - 1, n, prices, dp) + prices[idx],
                        recurMemo(idx + 1, false, times, n, prices, dp));
        }

        return dp[idx][canBuy][times] = profit;
      }

      int tabulation(vector<int>& prices) {

        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Base cases already 0:
        // dp[n][*][*] = 0
        // dp[*][*][0] = 0

        for (int idx = n - 1; idx >= 0; idx--) {
          for (int canBuy = 0; canBuy <= 1; canBuy++) {
            for (int times = 1; times <= 2; times++) {

              int profit = 0;

              if(canBuy){
                  profit = max( dp[idx + 1][0][times] - prices[idx],
                                dp[idx + 1][1][times]);
              } 
              else{
                profit = max( dp[idx + 1][1][times - 1] + prices[idx],
                              dp[idx + 1][0][times]);
              }

              dp[idx][canBuy][times] = profit;
            }
          }
        }

        return dp[0][1][2];
      }

      int spaceOpt(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> next(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int idx = n-1; idx>=0; idx--) {
            for (int canBuy=0; canBuy<=1; canBuy++) {
                for (int times=1; times<=2; times++) {

                  if (canBuy) {
                      curr[canBuy][times] = max(
                          -prices[idx] + next[0][times],
                          next[1][times]
                      );
                  } else {
                      curr[canBuy][times] = max(
                          prices[idx] + next[1][times - 1],
                          next[0][times]
                      );
                  }
                }
            }
            next = curr;
        }

        return next[1][2];
    }
    
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        // Recursion
        // return recur(0, true, 2, &n, prices);

        // TopDown
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // return recurMemo(0, true, 2, &n, prices, dp);

        // BottomUp
        // return tabulation(prices);

        // SpaceOpt
        // return spaceOpt(prices);
        
        int buy_1st = INT_MIN;
        int sell_1st = 0;
        int buy_2nd = INT_MIN;
        int sell_2nd = 0;

        int curr_bal = 0;

        for (int i=0; i<prices.size(); i++) {

            curr_bal = -prices[i];
            buy_1st  = max(buy_1st, curr_bal);   // max of not buying or buying first time here

            curr_bal = buy_1st + prices[i];
            sell_1st = max(sell_1st, curr_bal);   // max profit after first sell

            curr_bal = sell_1st - prices[i];
            buy_2nd  = max(buy_2nd, curr_bal);   // max of not buying second or buying second here

            curr_bal = buy_2nd + prices[i];
            sell_2nd = max(sell_2nd, curr_bal);   // max profit after second sell
        }
        return sell_2nd;
    }
};