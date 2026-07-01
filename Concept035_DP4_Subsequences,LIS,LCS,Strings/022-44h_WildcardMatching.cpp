// LC: 44 h 

class Solution {

      bool recur(int strIdx, int patIdx, string &s, string &p) {
        
        // Base cases
        if (strIdx<0 && patIdx<0){       // bey string puri
          return true;
        }
        if (patIdx<0 && strIdx>=0){      // pattern puri but string is not over yet
          return false;
        }
        if (strIdx < 0 && patIdx >= 0) {       // string is over, but not the pattern

          for (int i = 0; i <= patIdx; i++) {              // remaining chars in pattern must all be '*'
            if (p[i] != '*'){
              return false;
            } 
          }
          return true;
        }

        if (s[strIdx] == p[patIdx] || p[patIdx] == '?'){          // ready chhe
          return recur(strIdx-1, patIdx-1, s, p);
        }
        else if (p[patIdx] == '*'){
          //   '*' also includes empty sequence
          return recur(strIdx, patIdx-1, s, p) || recur(strIdx-1, patIdx, s, p);
        }
        else{
          return false;
        }
      }

      bool recurMemo(int strIdx, int patIdx, string &s, string &p, vector<vector<int>>& dp) {
        
        // Base cases
        if (strIdx<0 && patIdx<0){       // bey sring puri
          return true;
        }
        if (patIdx<0 && strIdx>=0){      // pattern puri but string is not over yet
          return false;
        }
        if (strIdx < 0 && patIdx >= 0) {       // string is over, but not the pattern

          for (int i = 0; i <= patIdx; i++) {              // remaining chars in p must all be '*'
            if (p[i] != '*'){
              return false;
            }
          }
          return true;
        }

        // Check dp
        if (dp[strIdx][patIdx] != -1){
          return dp[strIdx][patIdx];
        }

        // logic for calling
        if (s[strIdx] == p[patIdx] || p[patIdx] == '?'){                 // ready chhe
          return dp[strIdx][patIdx] = recurMemo(strIdx-1, patIdx-1, s, p, dp);
        }

        else if (p[patIdx] == '*'){
          return dp[strIdx][patIdx] = recurMemo(strIdx, patIdx-1, s, p, dp) || recurMemo(strIdx-1, patIdx, s, p, dp);
        }

        else{
          return dp[strIdx][patIdx] = false;
        }
      }

      bool tabulation(string &s, string &p){
        
          int m = s.size(), n = p.size(); 
          vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

          dp[0][0] = true;

          // base case: s empty
          for (int j = 1; j <= n; j++) {

            bool allStar = true;
            for (int k = 1; k <= j; k++) {
              if (p[k-1] != '*') { allStar = false; break; }
            }
            dp[0][j] = allStar;
          }

          for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
              
              if (s[i-1] == p[j-1] || p[j-1] == '?') {
                  dp[i][j] = dp[i-1][j-1];
              }
              else if (p[j-1] == '*') {
                  dp[i][j] = (dp[i][j-1] || dp[i-1][j]);
              }
              else dp[i][j] = false;
            }
          }
          return dp[m][n];
      }

      bool spaceOpt(string &s, string &p){
        
          int m = s.size();
          int n = p.size(); 
          vector<bool> prev(n+1, false);
          // vector<bool> curr(n+1, false);   // we can also do this

          prev[0] = true;

          // base case: s empty
          for (int j = 1; j <= n; j++) {

            bool allStar = true;
            for (int k = 1; k <= j; k++) {
              if (p[k-1] != '*') { allStar = false; break; }
            }
            prev[j] = allStar;
          }

          for (int i = 1; i <= m; i++) {

            vector<bool> curr(n+1, false);

            for (int j = 1; j <= n; j++) {
              
              if (s[i-1] == p[j-1] || p[j-1] == '?') {
                  curr[j] = prev[j-1];
              }
              else if (p[j-1] == '*') {
                  curr[j] = (curr[j-1] || prev[j]);
              }
              else curr[j] = false;
            }
            prev = curr;
          }
          return prev[n];
      }

public:
    bool isMatch(string s, string p) {
        
        int m = s.size();
        int n = p.size();

        // recursion
        // return recur(m-1, n-1, s, p);

        // TopDown
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return recurMemo(m-1, n-1, s, p, dp);

        // Tabulation
        // return tabulation(s, p);

        // Space Optimization  (Two rows: prev curr)
        return spaceOpt(s,p);
    }
};