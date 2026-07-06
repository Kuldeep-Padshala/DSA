// LC: 10 h 

class Solution {

      int m,n;

      bool recur(int i, int j, string& st, string& pat){

        // Base case
        if(j==n){
          return i == m;
        }
                                        // '.' Matches any single character.​​​​
        bool firstMatch = (i<m && (st[i] == pat[j] || pat[j] == '.'));
        
        bool ans;
        
        // '*' Matches zero or more of the preceding element.
        if(j+1<n && pat[j+1] == '*'){
            
          ans = recur(i, j+2, st, pat) ||   // skip (string mathi kai no lai)
                (firstMatch && recur(i+1, j, st, pat));  // take
        } 
        else {        
            ans = firstMatch && recur(i+1, j+1, st, pat);
        }
        
        return ans;

      }

      bool recurMemo(int i, int j, string& st, string& pat, vector<vector<int>>& dp){

        // Base case
        if(j==n){
          return i == m;
        }

        // check dp
        if(dp[i][j] != -1){
          return dp[i][j];
        }
                                        // '.' Matches any single character.​​​​
        bool firstMatch = (i<m && (st[i] == pat[j] || pat[j] == '.'));
        
        bool ans;
        
        // '*' Matches zero or more of the preceding element.
        if(j+1<n && pat[j+1] == '*'){
            
          ans = recurMemo(i, j+2, st, pat, dp) ||   // skip (string mathi kai no lai)
                (firstMatch && recurMemo(i+1, j, st, pat, dp));  // take
        } 
        else {        
            ans = firstMatch && recurMemo(i+1, j+1, st, pat, dp);
        }
        
        return dp[i][j] = ans;

      }

public:
    bool isMatch(string s, string p) {

        m = s.size();
        n = p.size();

        // Recursion
        // return recur(0, 0, s, p);

        // TopDown
        vector<vector<int>> dp(m+1, vector<int>(n, -1));
        return recurMemo(0, 0, s, p, dp);
    }
};