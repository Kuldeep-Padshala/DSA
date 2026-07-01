// LC: 1027 m 

// DP + hashing

class Solution {

      int recur(int i, int d, vector<int>& nums){

        // Base case
        if(i<0){
          return 0;
        }

        int ans = 0;
        for(int left = i-1; left>=0; left--){
          if(nums[i]-nums[left] == d){
            // plus 1 for counting current, left
            ans = max(ans, 1 + recur(left, d, nums));
          }
        }
        return ans;
      }

      int recurMemo(int i, int d, vector<int>& nums, vector<unordered_map<int, int>>& dp){

        // Base case
        if(i<0){
          return 0;
        }

        // Check dp
        if(dp[i].count(d)){
          return dp[i][d];
        }

        int ans = 0;
        for(int left = i-1; left>=0; left--){
          if(nums[i]-nums[left] == d){
            // plus 1 for counting current, left
            ans = max(ans, 1 + recurMemo(left, d, nums, dp));
          }
        }
        return dp[i][d] = ans;
      }

      int tabulation(vector<int>& nums){

        int n = nums.size();

        if(n<=2){
          return n;
        }

        int ans = 0;
        vector<unordered_map<int, int>> dp(n+1);

        for(int i=1; i<n; i++){
          for(int j=0; j<i; j++){
            int d = nums[i] - nums[j];
            int count = 1;

            if(dp[j].count(d)){
              count = dp[j][d];
            }
            dp[i][d] = 1 + count;
            ans = max(ans, dp[i][d]);
          }
        }
        return ans;
      }

      int optimized(vector<int>& nums){
        
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(1001,0));     // max nums[i] is 500

        int ans = 0;
        for(int i=1;i<n;i++){
          for(int j=0;j<i;j++){
            
            int diff = nums[i] - nums[j] + 500;

            dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2;
            ans = max(ans, dp[i][diff]);
          }
        }
        return ans;
      }

public:
    int longestArithSeqLength(vector<int>& nums) {
        
        // int n = nums.size();
        // if(n<=2){
        //   return n;
        // }

        // Recursion

        // int ans = 0;

        // // apde nums[i] nums [j ne last 2 elem of AP consider karsu.
        // // so for every i and j we will go left of i to check
        // for(int i=0; i<n; i++){
        //   for(int j=i+1; j<n; j++){
        //     int d = nums[j] - nums[i];
        //     ans = max(ans, 2 + recur(i, d, nums));    // plus 2 for i and j, recur will give the left elements
        //   }
        // }
        // return ans;



        // TopDown 
        // 2D dp (index, diff)
        // dp[i][d] -> length of longest AP till ith idx with diff d.
        // but at every idx, there exist multiple differences with their answers
        // so at evry idx i, there is unordered_map of diff->ans;

        // int ans = 0;
        // vector<unordered_map<int, int>> dp(n+1);

        // for(int i=0; i<n; i++){
        //   for(int j=i+1; j<n; j++){
        //     int d = nums[j] - nums[i];
        //     ans = max(ans, 2 + recurMemo(i, d, nums, dp));
        //   }
        // }
        // return ans;

        // BottomUp
        // return tabulation(nums);

        // Optimization
        return optimized(nums);

    }
};