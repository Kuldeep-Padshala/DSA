// LC: 377 m 

class Solution {

      int recur(int target, vector<int>& nums){

        // Base cases
        if(target<0){
          return 0;
        }
        if(target == 0){
          return 1;
        }
        int ans = 0;
        for(int num: nums){
          ans += recur(target-num, nums);
        }
        return ans;
      }

      int recurMemo(int target, vector<int>& nums, vector<int>& dp){

        // Base cases
        if(target<0){
          return 0;
        }
        if(target == 0){
          return dp[target] = 1;
        }

        // check dp
        if(dp[target] != -1){
          return dp[target];
        }

        int ans = 0;
        for(int num: nums){
          ans += recurMemo(target-num, nums, dp);
        }
        return dp[target] = ans;
      }

      int tabulation(int target, vector<int>& nums){

        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for(int tar=1; tar<=target; tar++){
          for(int num : nums){
            if(tar - num >= 0){
              long long temp = (long long)dp[tar] + dp[tar-num];
              if(temp <= INT_MAX){
                dp[tar] += dp[tar - num];
              }
            }
          }
        }
        return dp[target];
      }
      
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        // Recursion (TLE)
        // return recur(target, nums);

        // TopDown
        // ek j parameter change thai chhe
        // vector<int> dp(target+1, -1);
        // return  recurMemo(target, nums, dp);

        // BottomUp
        return tabulation(target, nums);
    }
};