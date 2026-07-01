// LC: 1143 m 

// dp on strings - 01

class Solution {
public:

    int lcs(const string& s1, const string& s2, int n, int m, vector<vector<int>>& dp) {
        
        if (n == 0 || m == 0) {
            return 0;
        }
        if (dp[n][m] != -1) {
            return dp[n][m];
        }
        if (s1[n - 1] == s2[m - 1]) {
            return dp[n][m] = 1 + lcs(s1, s2, n - 1, m - 1, dp);
        } 
        else {
            int ans1 = lcs(s1, s2, n - 1, m, dp);
            int ans2 = lcs(s1, s2, n, m - 1, dp);
            return dp[n][m] = max(ans1, ans2);
        }
    }

    int recur(const string& s1, const string& s2, int idx1, int idx2){

      // base case
      if(idx1<0 || idx2<0){
        return 0;
      }

      // logic
      if(s1[idx1] == s2[idx2]){
        return 1 + recur(s1, s2, idx1-1, idx2-1);
      }
      else{
        int case1 = recur(s1, s2, idx1-1, idx2);
        int case2 = recur(s1, s2, idx1, idx2-1);
        return max(case1, case2);
      }
    }

    int recurMemo(const string& s1, const string& s2, int idx1, int idx2, vector<vector<int>>& dp){

      // base case
      if(idx1<0 || idx2<0){
        return 0;
      }

      // check dp
      if(dp[idx1][idx2] != -1){
        return dp[idx1][idx2];
      }

      // logic
      if(s1[idx1] == s2[idx2]){
        return dp[idx1][idx2] = 1 + recurMemo(s1, s2, idx1-1, idx2-1, dp);
      }
      else{
        int case1 = recurMemo(s1, s2, idx1-1, idx2, dp);
        int case2 = recurMemo(s1, s2, idx1, idx2-1, dp);
        return dp[idx1][idx2] = max(case1, case2);
      }
    }

    int tabulation(const string& s1, const string& s2){

      int n = s1.length();
      int m = s2.length();
      vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

      for(int idx1=1; idx1<=n; idx1++){
        for(int idx2=1; idx2<=m; idx2++){

          if(s1[idx1-1] == s2[idx2-1]){
            dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
          }
          else{
            int case1 = dp[idx1-1][idx2];
            int case2 = dp[idx1][idx2-1];
            dp[idx1][idx2] = max(case1, case2);
          }
        }
      }
      return dp[n][m];
    }

    int tabulation2(const string& s1, const string& s2){

      int n = s1.length();
      int m = s2.length();
      vector<vector<int>> dp(n, vector<int>(m, 0));

      for(int idx1=0; idx1<n; idx1++){
        for(int idx2=0; idx2<m; idx2++){

          if(s1[idx1] == s2[idx2]){
            if(idx1 == 0 || idx2 == 0){
              dp[idx1][idx2] = 1;
            }
            else{
              dp[idx1][idx2] = 1 + dp[idx1-1][idx2-1];
            }
          }
          else{
            int case1 = (idx1!=0) ? dp[idx1-1][idx2] : 0;
            int case2 = (idx2!=0) ? dp[idx1][idx2-1] : 0;
            dp[idx1][idx2] = max(case1, case2);
          }
        }
      }
      return dp[n-1][m-1];
    }

    int spaceOpt(const string& s1, const string& s2){

      int n = s1.length();
      int m = s2.length();
      
      vector<int> prev(m+1, 0);

      for(int idx1=1; idx1<=n; idx1++){
        
        vector<int> curr(m+1, 0);
        for(int idx2=1; idx2<=m; idx2++){

          if(s1[idx1-1] == s2[idx2-1]){
            curr[idx2] = 1 + prev[idx2-1];
          }
          else{
            int case1 = prev[idx2];
            int case2 = curr[idx2-1];
            curr[idx2] = max(case1, case2);
          }
        }
        prev = curr;
      }
      return prev[m];
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.length();
        int m = text2.length();

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return lcs(text1, text2, n, m, dp);

        // Recursion
        // return recur(text1, text2, n-1, m-1);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return recurMemo(text1, text2, n-1, m-1, dp);

        // BottomUP
        // return tabulation(text1, text2);

        // Space optimization
        return spaceOpt(text1, text2);

    }
};