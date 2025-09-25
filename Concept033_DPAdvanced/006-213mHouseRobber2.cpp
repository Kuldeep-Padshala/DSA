// LC: 213 m 

class Solution {

    int topDown(int start, int n, vector<int>& dp, vector<int>& nums) {

        // Base case
        if (n < start) return 0;
        if (n == start) return nums[start];

        if (dp[n] != -1){
          return dp[n];
        }

        int robThis = topDown(start, n-2, dp, nums) + nums[n];
        int robAdj = topDown(start, n-1, dp, nums);

        return dp[n] = max(robThis, robAdj);
    }

    int bottomUp(vector<int>& nums, int s, int e) {

        int n = e - s + 1;
        if (n == 1) return nums[s];

        vector<int> dp(e+1, 0);
        dp[s] = nums[s];
        dp[s+1] = max(nums[s], nums[s+1]);

        for (int i = s+2; i<=e; i++) {
          dp[i] = max( dp[i-1], dp[i-2]+nums[i] );
        }
        return dp[e];
    }

    int spaceOpt(vector<int>& nums, int s, int e) {
        
        int n = s-e +1;
        if (n == 1) return nums[s];

        int prev2 = 0;
        int prev1 = nums[s];
        for (int i= s+1; i <= e; i++) {
          
          int take = nums[i] + prev2;
          int skip = prev1;
          int curr = max(take, skip);
          prev2 = prev1;
          prev1 = curr;
        }
        return prev1;
    }

public:
    int rob(vector<int>& nums) {

        // Here we need 2 ranges, 0 to n-2  &  1 to n-1
        int n = nums.size();
        if(n==1) return nums[0];

        // ------------------ TopDown: Recursion + Memoization ------------------

        // vector<int> dp(n, -1);
        // int case1 = topDown(0, n-2, dp, nums);
        // int case2 = topDown(1, n-1, dp, nums);
        // return max(case1, case2);

        // ------------------  BottomUp: Tabulation  ---------------------

        // int case1 = bottomUp(nums, 0, n-2);
        // int case2 = bottomUp(nums, 1, n-1);
        // return max(case1, case2);

        // ------------------ BottomUp Space Optimization  ---------------------

         return max( spaceOpt(nums, 0, n-2), spaceOpt(nums, 1, n-1) );
    }
};