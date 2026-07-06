// LC: 1278 h 

class Solution {

      int findCost(int l, int r, string& s){

        int cost = 0;
        while (l < r) {
            if (s[l] != s[r]) cost++;
            l++; r--;
        }
        return cost;
      }

      int recur(int idx, int parts, string& s) {

        // Base case
        if(idx == -1 && parts == 0){
          return 0;
        }

        // Invalid cases
        if(idx == -1 || parts == 0){
          return INT_MAX / 2;
        }

        int mini = INT_MAX;

        // Try last cut from k to idx
        for (int k=idx; k>=0; k--) {

          // cost to make s[k..idx] palindrome
          int cost = findCost(k, idx, s);
          

          int prev = recur(k-1, parts-1, s);
          mini = min(mini, cost + prev);
        }

        return mini;
      }

      int recurMemo(int idx, int parts, string& s, vector<vector<int>>& dp) {

        // Base case
        if(idx == -1 && parts == 0){
          return 0;
        }

        // Invalid cases
        if(idx == -1 || parts == 0){
          return INT_MAX / 2;
        }

        // check dp
        if(dp[idx][parts] != -1){
          return dp[idx][parts];
        }

        int mini = INT_MAX;

        // Try last cut from k to idx
        for (int k=idx; k>=0; k--) {

          // cost to make s[k..idx] palindrome
          int cost = findCost(k, idx, s);
          

          int prev = recurMemo(k-1, parts-1, s, dp);
          mini = min(mini, cost + prev);
        }

        return dp[idx][parts] = mini;
      }

      int tabulation(string& s, int K) {

        int n = s.size();
        // const int INT_MAX = 1e9;
        vector<vector<int>> dp(n, vector<int>(K+1, INT_MAX));

        /* ---------- BASE CASE ---------- */
        // idx == -1 && parts == 0  → 0
        // We simulate idx == -1 using initialization when k == 0
        // so nothing explicit needed here

        /* ---------- FILL DP ---------- */
        for(int idx=0; idx<n; idx++) {
          for(int parts=1; parts<=K; parts++) {
 
              int mini = INT_MAX;

              for(int k=idx; k>=0; k--){
                
                int cost = findCost(k, idx, s);

                if(k==0){
                  // corresponds to recur(-1, parts-1)
                  if(parts == 1){
                    mini = min(mini, cost);
                  }
                }
                else{
                  if(dp[k-1][parts-1] != INT_MAX) {
                    mini = min(mini, cost + dp[k-1][parts-1]);
                  }
                }
              }
              dp[idx][parts] = mini;
          }
        }

        return dp[n-1][K];
      }


public:
    int palindromePartition(string s, int k) {
        
        int n = s.size();

        // Recursion
        // return recur(n-1, k, s);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(k+1, -1));
        // return recurMemo(n-1, k, s, dp);

        // BottomUp
        return tabulation(s, k);
    }
};