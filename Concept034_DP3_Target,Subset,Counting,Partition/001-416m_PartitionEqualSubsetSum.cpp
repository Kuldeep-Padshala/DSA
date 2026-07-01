// LC: 416 m 

class Solution {

      bool recur(int idx, int target, vector<int>& nums){

        // Base cases
        if(idx==nums.size()){
          return false;
        }
        if(target == 0){
          return true;
        }
        if(target<0){
          return false;
        }

        int include = recur(idx+1, target-nums[idx], nums);
        int exclude = recur(idx+1, target, nums);

        return (include || exclude);
      }

      int recurMemo(int idx, int target, vector<int>& nums, vector<vector<int>>& dp){

        // Base cases
        if(idx==nums.size()){
          return 0;
        }
        if(target == 0){
          return dp[idx][target] = 1;
        }
        if(target<0){
          return 0;
        }

        // Check dp
        if(dp[idx][target] != -1){
          return dp[idx][target];
        }
        
        int include = recurMemo(idx+1, target-nums[idx], nums, dp);
        int exclude = recurMemo(idx+1, target, nums, dp);

        return dp[idx][target] = (include || exclude);
      }

      bool tabulation(int total, vector<int>& nums){
        
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(total/2+1, false));

        // Base case
        for(int i=0; i<=n; i++){
          dp[i][0] = true;
        }

        for(int idx=n-1; idx>=0; idx--){
          for(int target = 0; target<=total/2; target++){
            
            bool include = false;
            if(target-nums[idx] >= 0) include = dp[idx+1][target-nums[idx]];          
            
            bool exclude = dp[idx+1][target];

            dp[idx][target] = (include || exclude);
          }
        }
        return dp[0][total/2];
      }

      bool spaceOpt(int total, vector<int>& nums){
        
        int n = nums.size();
        vector<bool> next(total/2+1, false);

        // Base case
        next[0] = true;

        for(int idx=n-1; idx>=0; idx--){

          vector<bool> curr(total/2+1, false);

          for(int target = 0; target<=total/2; target++){
            
            bool include = false;
            if(target-nums[idx] >= 0) include = next[target-nums[idx]];          
            
            bool exclude = next[target];

            curr[target] = (include || exclude);
          }
          next = curr;
        }
        return next[total/2];
      }
      
public:
    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int total = 0;
        for(int num: nums){
          total += num;
        }
        if(total % 2 != 0) return false;

        // Recursion
        // return recur(0, total/2, nums);

        // TopDown
        // vector<vector<int>> dp(n, vector<int>(total/2 + 1, -1));
        // return recurMemo(0, total/2, nums, dp);

        // BottomUp
        // return tabulation(total, nums);

        // Space Optimization
        return spaceOpt(total, nums);
    }
};