// LC: 91 m 

class Solution {

      int solve(int n, string &s, vector<int>& dp) {
        
        // base case
        if(n < 0) return 1;
        if(s[n] == '0') return 0;          // Invalid, starting with 0   

        
        if(dp[n] != -1){
          return dp[n];
        }

        // Case 1: take one digit
        int ways = solve(n-1, s, dp);

        // Case 2: take two digits (must be <= 26)
        if(n > 0) {

          int num = (s[n-1]-'0') * 10 + (s[n]-'0');

          if(num >= 10 && num <= 26) {
            ways += solve(n-2, s, dp);
          }
        }

        return dp[n] = ways;
    }
public:
    int numDecodings(string s) {

        int n = s.size();

        // ------------------ TopDown: Recursion + Memoization ------------------
        vector<int> dp(n, -1);           // sizes
        return solve(n-1, s, dp);


        // ------------------  BottomUp: Tabulation  ---------------------
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        if(s[0]!= '0') dp[1] = 1;
        else dp[1] = 0;

        for(int i = 2; i <= n; i++) {

          if(s[i-1] != '0') {
            dp[i] += dp[i-1]; // single digit
          }
          int num = (s[i-2]-'0')*10 + (s[i-1]-'0');
          if(num >= 10 && num <= 26) {
            dp[i] += dp[i-2]; // two digits
          }
        }
        return dp[n];

        // ------------------ BottomUp Space Optimization  ---------------------
        int prev2 = 1;                  // dp[0] i-2
        int prev1 = (s[0] != '0');      // dp[1] i-1

        for(int i=2; i<=n; i++){
          int curr = 0;
          if(s[i-1] != '0'){
            curr += prev1;
          }
          int num = (s[i-2]-'0')*10 + (s[i-1]-'0');
          if(num >= 10 && num <= 26) {
            curr += prev2; // two digits
          }
          prev2 = prev1;
          prev1 = curr;
        }
        return prev1;
    }
};