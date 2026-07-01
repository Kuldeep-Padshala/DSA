// LC: 5 m 

class Solution {

        // LC: 1143. Longest Common Subsequence, but modified
        string tabulation(const string& s1, const string& s2) {

          int n = s1.length();
          int m = s2.length();

          vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

          int maxLen = 0;
          int endIdx = 0;   // ending index of substring in s1

          for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++) {

              if(s1[i-1] == s2[j-1]){

                dp[i][j] = 1 + dp[i-1][j-1];

                int len = dp[i][j];

                // 🔴 crucial palindrome index check
                int start1 = i - len;
                int start2 = n - j;

                if(len > maxLen && start1 == start2) {
                  maxLen = dp[i][j];
                  endIdx = i;
                }
              } 
              else {
                dp[i][j] = 0;
              }
            }
          }
          return s1.substr(endIdx - maxLen, maxLen);
        }

public:
    string longestPalindrome(string s) {
        
        string s2 = s;
        reverse(s.begin(), s.end());
        return tabulation(s, s2);
    }
};