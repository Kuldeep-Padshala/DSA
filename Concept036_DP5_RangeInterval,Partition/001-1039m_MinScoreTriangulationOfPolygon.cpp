// LC: 1039 m 

class Solution {

//                                           # __ m  __ #
//                                         /      /\    |  
//                                        #      /  \   # 
//                                        \     /    \ /
//                                         # _ s ____ e

      int recur(int s, int e, vector<int>& val){

        // Base case
        if(e-s == 1){
          return 0;
        }

        int ans = INT_MAX;
        for(int mid=s+1; mid<e; mid++){
          // s and e are adjacent, making triangles s m e, 
          ans = min(ans, val[s]*val[mid]*val[e] + recur(s, mid, val) + recur(mid, e, val));
        }
        return ans;
      }

      int recurMemo(int s, int e, vector<int>& val, vector<vector<int>>& dp){

        // Base case
        if(e-s == 1){
          return 0;
        }

        // Check dp
        if(dp[s][e] != -1){
          return dp[s][e];
        }

        int ans = INT_MAX;
        for(int mid=s+1; mid<e; mid++){
          // s and e are adjacent, making triangles s m e, 
          ans = min(ans, val[s]*val[mid]*val[e] + recurMemo(s, mid, val, dp) + recurMemo(mid, e, val, dp));
        }
        return dp[s][e] = ans;
      }

      int tabulation(vector<int>& val){

        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // as it is as bottom up
        for(int s=n-1; s>=0; s--){
          for(int e=s+2; e<n; e++){

            int ans = INT_MAX;
            for(int mid=s+1; mid<e; mid++){
              ans = min(ans, val[s]*val[mid]*val[e] + dp[s][mid] + dp[mid][e]);
            }
            dp[s][e] = ans;
          }
        }

        return dp[0][n-1];
      }


public:
    int minScoreTriangulation(vector<int>& values) {
        
        // int n = values.size();

        // Recursion
        // return recur(0, n-1, values);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return recurMemo(0, n-1, values, dp);

        // BottomUp
        return tabulation(values);
    }
};