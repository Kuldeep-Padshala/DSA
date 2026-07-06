// LC: 132 h 

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

      int recur(int idx, string& s){
        
        int n = s.size();

        // Base case
        if(idx==-1){
          return 0;
        }

        int mini = INT_MAX;
        for(int k=idx; k>=0; k--){

          if(isValid(k, idx, s)){
            int cost = 1 + recur(k-1, s);
            mini = min(mini, cost);
          }
        }
        return mini;
      }

      int recurMemo(int idx, string& s, vector<int>& dp){
        
        int n = s.size();

        // Base case
        if(idx==-1){
          return 0;
        }

        // check dp
        if(dp[idx] != -1){
          return dp[idx];
        }

        int mini = INT_MAX;
        for(int k=idx; k>=0; k--){

          if(isValid(k, idx, s)){
            int cost = 1 + recurMemo(k-1, s, dp);
            mini = min(mini, cost);
          }
        }
        return dp[idx] = mini;
      }

      int tabulation(string& s){
        
        int n = s.size();
        vector<int> dp(n, 0);

        for(int idx=0; idx<n; idx++){

          int mini = INT_MAX;
          for(int k=idx; k>=0; k--){

            if(isValid(k, idx, s)){
              int cost;
                if(k == 0)
                  cost = 1;           // whole prefix is palindrome
                else
                  cost = 1 + dp[k-1];
              mini = min(mini, cost);
            }
          }
          dp[idx] = mini;
        }
        return dp[n-1] - 1;
      }

public:
    int minCut(string s) {
        
        int n = s.size();

        // Recursion
        // return recur(n-1, s) - 1;

        // TopDown
        // vector<int> dp(n, -1);
        // return recurMemo(n-1, s, dp) - 1;

        // BottomUp
        return tabulation(s);
    }
};