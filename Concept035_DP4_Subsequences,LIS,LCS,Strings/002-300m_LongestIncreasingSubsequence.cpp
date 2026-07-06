// LC: 300 m 

class Solution {

      int recur(int prev, int curr, vector<int>& nums){

        // Base case
        if(curr == nums.size()){
          return 0;
        }

        int include=0;
        if(prev == -1 || nums[prev] < nums[curr]){
          include = 1 + recur(curr, curr+1, nums);         // included, so next mate prev is curr
        }

        int exclude = recur(prev, curr+1, nums);             // not included, so next mate prev is prev

        return max(include, exclude);
      }

      // one common mistake, our prev is starting from index -1 in dp
      // so whenever we use prev in dp, we add 1

      int recurMemo(int prev, int curr, vector<int>& nums, vector<vector<int>>& dp){

        // Base case
        if(curr == nums.size()){
          return 0;
        }

        // check dp
        if(dp[prev+1][curr] != -1){
          return dp[prev+1][curr];
        }

        int include=0;
        if(prev == -1 || nums[prev] < nums[curr]){
          include = 1 + recurMemo(curr, curr+1, nums, dp);         // included, so next mate prev is curr
        }

        int exclude = recurMemo(prev, curr+1, nums, dp);             // not included, so next mate prev is prev

        return dp[prev+1][curr] = max(include, exclude);
      }

      int tabulation(vector<int>& nums){

        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        for(int curr=n-1; curr>=0; curr--){
          for(int prev=curr-1; prev>=-1; prev--){
            
            int include=0;
            if(prev == -1 || nums[prev] < nums[curr]){
              include = 1 + dp[curr+1][curr+1];         // included, so next mate prev is curr
            }

            int exclude = dp[prev+1][curr+1];             // not included, so next mate prev is prev

            dp[prev+1][curr] = max(include, exclude);
          }
        }
        return dp[0][0];
      }

      int spaceOpt(vector<int>& nums){

        int n = nums.size();
        vector<int> nextRow(n+1, 0);

        for(int curr=n-1; curr>=0; curr--){

          vector<int> currRow(n+1, 0);
          for(int prev = curr - 1; prev >= -1; prev--){
            
            int include=0;
            if(prev == -1 || nums[prev] < nums[curr]){
              include = 1 + nextRow[curr+1];         // included, so next mate prev is curr
            }

            int exclude = nextRow[prev+1];             // not included, so next mate prev is prev

            currRow[prev+1] = max(include, exclude);
          }
          nextRow = currRow;
        }
        return nextRow[0];
      }

      int optimalDp(vector<int>& nums){

        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++){

          if(nums[i] > ans.back()){
            ans.push_back(nums[i]);
          }
          else{                  // find elem just bigger than curr
            int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[idx] = nums[i];
          }
        }
        return ans.size();
      }
      

public:
    int lengthOfLIS(vector<int>& nums) {
        
        // int n = nums.size();
        // Recursion
        // return recur(-1, 0, nums);

        // TopDown
        // vector<vector<int>> dp(n+1, vector<int>(n, -1));
        // return recurMemo(-1, 0, nums, dp);

        // BottomUp
        // return tabulation(nums);

        // space optimization
        // return spaceOpt(nums);

        // DP with binary search
        return optimalDp(nums);

    }
};