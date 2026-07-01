// LC: 1745 h 

class Solution {

      bool isValid(int l, int r, string &s){

          while(l<r){

            if(s[l] != s[r]){
              return false;
            }
            l++; r--;
          }
          return true;
      }

      bool recur(int idx, int parts, string& s) {

        // Base case: exactly used all characters and parts
        if(idx == -1 && parts == 0){
          return true;
        }

        // Invalid cases
        if(idx == -1 || parts == 0){
          return false;
        }

        // Try last cut from k to idx
        for (int k=idx; k>=0; k--) {

          if (isValid(k, idx, s)) {
            if (recur(k - 1, parts - 1, s)){
              return true;   // early exit
            }
          }
        }

        return false;
      }

      int recurMemo(int idx, int parts, string& s, vector<vector<int>>& dp) {

        // Base case: exactly used all characters and parts
        if(idx == -1 && parts == 0){
          return 1;
        }

        // Invalid cases
        if(idx == -1 || parts == 0){
          return 0;
        }

        // check dp
        if(dp[idx][parts] != -1){
          return dp[idx][parts];
        }

        // Try last cut from k to idx
        for (int k=idx; k>=0; k--) {

          if (isValid(k, idx, s)) {
            if(recurMemo(k-1, parts - 1, s, dp)){
              return dp[idx][parts] = 1;   // early exit
            }
          }
        }

        return dp[idx][parts] = 0;
      }

      bool tabulation(string& s){
        
        int n = s.size();

        /* ---------- Palindrome Precompute ---------- */
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for(int i=0; i<n; i++){
          pal[i][i] = true;
        }

        for(int len=2; len<=n; len++){
          for(int i=0; i+len-1 < n; i++) {
              
            int j = i + len - 1;
            if(s[i] == s[j]) {
              if(len == 2 || pal[i+1][j-1]){
                pal[i][j] = true;
              }
            }
          }
        }

        /* ---------- DP ---------- */
        vector<vector<bool>> dp(n, vector<bool>(4, false));

        for (int i=0; i<n; i++){
          for (int p=1; p<=3; p++){

            for(int k=i; k>=0; k--){

              if(pal[k][i]) {

                if(k==0 && p==1) {
                  dp[i][p] = true;
                }
                else if(k>0 && dp[k-1][p-1]){
                  dp[i][p] = true;
                }

                if(dp[i][p]) break; // early exit
              }
            }
          }
        }

        return dp[n-1][3];
      }

public:
    bool checkPartitioning(string s) {
        
        int n = s.size();
        // Recursion
        // return recur(n-1, 3, s);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(3+1, -1));
        // if(recurMemo(n-1, 3, s, dp)){
        //   return true;
        // }
        // else return false;

        // BottomUP
        return tabulation(s);
    }
};