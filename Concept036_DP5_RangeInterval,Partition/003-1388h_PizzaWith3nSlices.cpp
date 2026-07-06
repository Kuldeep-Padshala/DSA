// LC:1388 h 

class Solution {

      int recur(int idx, int end, int n, vector<int>& slices){

          // Base case
          if(n==0 ||  idx>end){
            return 0;
          }

          int take = slices[idx] + recur(idx+2, end, n-1, slices);
          int notTake = recur(idx+1, end, n, slices);

          return max(take, notTake);
      }

      int recurMemo(int idx, int end, int n, vector<int>& slices, vector<vector<int>>& dp){

          // Base case
          if(n==0 ||  idx>end){
            return 0;
          }

          // check dp
          if(dp[idx][n] != -1){
            return dp[idx][n];
          }

          int take = slices[idx] + recurMemo(idx+2, end, n-1, slices, dp);
          int notTake = recurMemo(idx+1, end, n, slices, dp);

          return dp[idx][n] = max(take, notTake);
      }

      int tabulation(vector<int>& slices){

          int k = slices.size();

          vector<vector<int>> dp1(k+1, vector<int>(k+1, 0));
          vector<vector<int>> dp2(k+2, vector<int>(k+2, 0));

          for(int idx=k-2; idx>=0; idx--){
            for(int n=1; n<=k/3; n++){

              int take = slices[idx] + dp1[idx+2][n-1];
              int notTake = dp1[idx+1][n];

              dp1[idx][n] = max(take, notTake);
            }
          }
          int case1 = dp1[0][k/3];

          for(int idx=k-1; idx>=1; idx--){
            for(int n=1; n<=k/3; n++){

              int take = slices[idx] + dp2[idx+2][n-1];
              int notTake = dp2[idx+1][n];

              dp2[idx][n] = max(take, notTake);
            }
          }
          int case2 = dp2[1][k/3];

          return max(case1, case2);

      }

      int spaceOpt(vector<int>& slices){

          int k = slices.size();

          // vector<vector<int>> dp1(k+1, vector<int>(k+1, 0));
          // vector<vector<int>> dp2(k+2, vector<int>(k+2, 0));

          vector<int> prev1(k, 0);        //  idx
          vector<int> curr1(k, 0);        // idx+1
          vector<int> next1(k+1, 0);        // idx+2

          vector<int> prev2(k, 0);
          vector<int> curr2(k+1, 0);
          vector<int> next2(k+2, 0);

          for(int idx=k-2; idx>=0; idx--){
            for(int n=1; n<=k/3; n++){

              int take = slices[idx] + next1[n-1];
              int notTake = curr1[n];

              prev1[n] = max(take, notTake);
            }
            next1 = curr1;
            curr1 = prev1;
          }
          // int case1 = curr1[k/3];

          for(int idx=k-1; idx>=1; idx--){
            for(int n=1; n<=k/3; n++){

              int take = slices[idx] + next2[n-1];
              int notTake = curr2[n];

              prev2[n] = max(take, notTake);
            }
            next2 = curr2;
            curr2 = prev2;
          }
          // int case2 = curr2[k/3];

          return max(curr1[k/3], curr2[k/3]);

      }

public:
    int maxSizeSlices(vector<int>& slices) {
        
        // just like house robber 2 

        // int k = slices.size();

        // Recursion
        // int case1 = recur(0, k-2, k/3, slices);
        // int case2 = recur(1, k-1, k/3, slices);
        // return max(case1, case2);

        // TopDown
        // vector<vector<int>> dp1(k, vector<int>(k, -1));
        // int case1 = recurMemo(0, k-2, k/3, slices, dp1);

        // vector<vector<int>> dp2(k, vector<int>(k, -1));
        // int case2 = recurMemo(1, k-1, k/3, slices, dp2);
        // return max(case1, case2);

        // BottomUp
        // return tabulation(slices);

        // Space optimization
        return spaceOpt(slices);
    }
};