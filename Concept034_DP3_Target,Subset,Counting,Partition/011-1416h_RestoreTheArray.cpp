// LC: 1416 h 

class Solution {
public:

    const int MOD = 1e9 + 7;

    int recur(int idx, int k, string& s){

      // base case
      int n = s.size();
      if(idx == n) return 1;

      long long num = 0, ans = 0;

      for(int i=idx; i<n; i++){
        
        int digit = s[i] - '0';
        num = (num*10) + digit;

        if(num<1 || num>k) break;

        ans = (ans + recur(i+1, k, s)) % MOD;
      }

      return (int) ans;
    }

    int recurMemo(int idx, int k, string& s, vector<int>& dp){

      // base case
      int n = s.size();
      if(idx == n) return 1;

      // check dp
      if(dp[idx] != -1){
        return dp[idx];
      }

      long long num = 0, ans = 0;

      for(int i=idx; i<n; i++){
        
        int digit = s[i] - '0';
        num = (num*10) + digit;

        if(num<1 || num>k) break;

        ans = (ans + recurMemo(i+1, k, s, dp)) % MOD;
      }

      return dp[idx] = (int) ans;
    }

    int tabulation(int k, string& s){
      
      int n = s.size();
      vector<int> dp(n+1, 0);

      // base case
      dp[n] = 1;
      
      for(int idx=n-1; idx>=0; idx--){
        
        long long num = 0, ans = 0;

        for(int i=idx; i<n; i++){
          
          int digit = s[i] - '0';
          num = (num*10) + digit;

          if(num<1 || num>k) break;

          ans = (ans + dp[i+1]) % MOD;
        }

        dp[idx] = (int) ans;
      }

      return dp[0];
    }
    int numberOfArrays(string s, int k) {
        
        int n = s.size();

        // Recursion
        // return recur(0, k, s);

        // TopDown
        // vector<int> dp(n, -1);
        // return recurMemo(0, k, s, dp);

        // BottomUp
        return tabulation(k, s);
    }
};