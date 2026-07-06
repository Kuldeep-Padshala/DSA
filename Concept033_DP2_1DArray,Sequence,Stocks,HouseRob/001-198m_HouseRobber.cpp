// LC: 198 m 

class Solution {
    
    int solve(int n, vector<int>& dp, vector<int>& nums){
        
        // Base case
        if (n < 0) return 0;         // no house
        if (n == 0) return nums[0];  // only one house

        if(dp[n] != -1){
          return dp[n];
        }

        int robThis = nums[n] + solve(n-2, dp, nums); // rob current house
        int robAdj = solve(n-1, dp, nums);          // skip current house

        return dp[n] = max(robThis, robAdj);
    }
public:
    int rob(vector<int>& nums) {
        
        int n = nums.size();

        // ------------------ TopDown: Recursion + Memoization ------------------
        vector<int> dp(n, -1);
        return solve(n - 1, dp, nums);

        // ------------------  BottomUp: Tabulation  ---------------------
        // if(n == 1){
        //   return nums[0];
        // }
        // vector<int> dp(n, 0);
        // dp[0] = nums[0];
        // dp[1] = max(nums[0], nums[1]);

        // for (int i = 2; i < n; i++) {
        //   dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        // }
        // return dp[n - 1];

        // ------------------ BottomUp Space Optimization  ---------------------
        if(n == 1){
          return nums[0];
        }
        int prev2 = 0;        // dp[i-2]
        int prev1 = nums[0];  // dp[i-1]

        for(int i = 1; i < n; i++) {
          int take = nums[i] + prev2;
          int skip = prev1;
          int curr = max(take, skip);
          prev2 = prev1;
          prev1 = curr;
        }
        return prev1;
    }
};