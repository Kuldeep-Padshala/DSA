// LC: 3573 m 

// so only thing we chaged from previous 2 problem is
// int state instead of canBuy

// State	Meaning
// 0	    No position (free)
// 1	    Holding a BUY position (bought, need to sell)
// 2	    Holding a SHORT position (sold first, need to buy back)

class Solution {

      int recur(int idx, int state, int times, int* n, vector<int>& prices) {
        

        // Base case
        // if(idx == *n || times == 0){
        //   return 0;
        // }

        if (idx == *n) {
          if (state != 0) return INT_MIN / 2; // open position → invalid
          return 0;
        }

        // very important
        if (times == 0) {
          if (state != 0) return INT_MIN / 2; // cannot close anymore
          return 0;
        }

        int profit = 0;

        if (state == 0) { // no position

          // max ({skip, buy, sold})
          profit = max({ recur(idx+1, 0, times, n, prices), recur(idx+1, 1, times, n, prices) - prices[idx],
                          recur(idx+1, 2, times, n, prices) + prices[idx] });
        }

        else if (state == 1) { // holding buy

          // max(keep, sold) 
          profit = max( recur(idx+1, 1, times, n, prices),
                        recur(idx+1, 0, times-1, n, prices) + prices[idx] );
        }
        else { // holding short

          // max(keep sold, buy)
          profit = max( recur(idx+1, 2, times, n, prices),
                        recur(idx+1, 0, times-1, n, prices) - prices[idx] );
        }
        return profit;
      }

      long long recurMemo(int idx, int state, int times, int* n, vector<int>& prices, vector<vector<vector<long long>>>& dp) {
        

        // Base case
        // if(idx == *n || times == 0){
        //   return 0;
        // }

        if (idx == *n) {
          if (state != 0) return INT_MIN / 2; // open position → invalid
          return 0;
        }

        // very important
        if (times == 0) {
          if (state != 0) return INT_MIN / 2; // cannot close anymore
          return 0;
        }

        // check dp
        if(dp[idx][state][times] != -1){
          return dp[idx][state][times];
        }

        long long profit = 0;

        if (state == 0) { // no position

          // max ({skip, buy, sold})
          profit = max({ recurMemo(idx+1, 0, times, n, prices, dp), recurMemo(idx+1, 1, times, n, prices, dp) - prices[idx],
                          recurMemo(idx+1, 2, times, n, prices, dp) + prices[idx] });
        }

        else if (state == 1) { // holding buy

          // max(keep, sold) 
          profit = max( recurMemo(idx+1, 1, times, n, prices, dp),
                        recurMemo(idx+1, 0, times-1, n, prices, dp) + prices[idx] );
        }
        else { // holding short

          // max(keep sold, buy)
          profit = max( recurMemo(idx+1, 2, times, n, prices, dp),
                        recurMemo(idx+1, 0, times-1, n, prices, dp) - prices[idx] );
        }
        return dp[idx][state][times]= profit;
      }

      long long tabulation(vector<int>& prices, int k) {

        int n = prices.size();
        const long long NEG = -1e18;

        // dp[idx][state][times]
        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(3, vector<long long>(k + 1, NEG))
        );

        /* ---------------- BASE CASES ---------------- */

        // idx == n
        for (int t = 0; t <= k; t++) {
            dp[n][0][t] = 0;        // no position → valid
            dp[n][1][t] = NEG;     // open buy → invalid
            dp[n][2][t] = NEG;     // open short → invalid
        }

        // times == 0
        for (int i = 0; i <= n; i++) {
            dp[i][0][0] = 0;       // no position → valid
            dp[i][1][0] = NEG;    // cannot close
            dp[i][2][0] = NEG;
        }

        /* ---------------- TRANSITIONS ---------------- */

        for (int idx = n - 1; idx >= 0; idx--) {
            for (int times = 1; times <= k; times++) {

                // state = 0 (no position)
                dp[idx][0][times] = max({
                    dp[idx + 1][0][times],                     // skip
                    dp[idx + 1][1][times] - prices[idx],       // buy
                    dp[idx + 1][2][times] + prices[idx]        // short
                });

                // state = 1 (holding buy)
                dp[idx][1][times] = max(
                    dp[idx + 1][1][times],                     // keep
                    dp[idx + 1][0][times - 1] + prices[idx]    // sell
                );

                // state = 2 (holding short)
                dp[idx][2][times] = max(
                    dp[idx + 1][2][times],                     // keep
                    dp[idx + 1][0][times - 1] - prices[idx]    // cover
                );
            }
        }

        return dp[0][0][k];
      }

      long long spaceOpt(vector<int>& prices, int k) {

        int n = prices.size();
        const long long NEG = -1e18;

        // next[state][times], curr[state][times]
        vector<vector<long long>> next(3, vector<long long>(k + 1, NEG));
        vector<vector<long long>> curr(3, vector<long long>(k + 1, NEG));

        /* ---------- BASE CASE (idx == n) ---------- */
        for (int t = 0; t <= k; t++) {
            next[0][t] = 0;
            next[1][t] = NEG;
            next[2][t] = NEG;
        }

        /* ---------- ITERATE DAYS ---------- */
        for (int idx = n - 1; idx >= 0; idx--) {

            // times == 0
            curr[0][0] = 0;
            curr[1][0] = NEG;
            curr[2][0] = NEG;

            for (int times = 1; times <= k; times++) {

                // state = 0 (free)
                curr[0][times] = max({
                    next[0][times],                 // skip
                    next[1][times] - prices[idx],   // buy
                    next[2][times] + prices[idx]    // short
                });

                // state = 1 (holding buy)
                curr[1][times] = max(
                    next[1][times],                 // hold
                    next[0][times - 1] + prices[idx] // sell
                );

                // state = 2 (holding short)
                curr[2][times] = max(
                    next[2][times],                 // hold
                    next[0][times - 1] - prices[idx] // cover
                );
            }

            next = curr;
        }

        return next[0][k];
      }


public:
    long long maximumProfit(vector<int>& prices, int k) {
        

        int n = prices.size();

        // Recursion
        // return recur(0, 0, k, &n, prices);

        // TopDown
        // vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(3, vector<long long>(k + 1, -1)));
        // return recurMemo(0, 0, k, &n, prices, dp);

        // Tabulation
        // return tabulation(prices, k);

        // Space Optimization
        return spaceOpt(prices, k);
        

        // int n = prices.size();
        // if (n == 0 || k == 0) return 0;

        // const int NEG = -1e9;

        // vector<long long> neutral(k+1, NEG),
        //             longPos(k+1, NEG),
        //             shortPos(k+1, NEG);

        // neutral[0] = 0;

        // for (int price : prices) {
        //     vector<long long> newNeutral = neutral;
        //     vector<long long> newLong = longPos;
        //     vector<long long> newShort = shortPos;

        //     for (int t = 0; t <= k; t++) {
        //         // Open positions (no transaction completed)
        //         newLong[t]  = max(newLong[t], neutral[t] - price);
        //         newShort[t] = max(newShort[t], neutral[t] + price);

        //         // Close positions (complete transaction)
        //         if (t < k) {
        //             newNeutral[t+1] = max(newNeutral[t+1], longPos[t] + price);
        //             newNeutral[t+1] = max(newNeutral[t+1], shortPos[t] - price);
        //         }
        //     }

        //     neutral = newNeutral;
        //     longPos = newLong;
        //     shortPos = newShort;
        // }

        // return *max_element(neutral.begin(), neutral.end());
    }
};