// LC: 1262 m

class Solution {

      int recur(int idx, int rem, vector<int>& nums){

        if(idx == -1){
          if(rem % 3 == 0){
            return rem;
          }
          else return 0;
        }

        int take = recur(idx-1, rem + nums[idx], nums);
        int skip = recur(idx-1, rem, nums);

        return max(take, skip);
      }

      int recurMemo(int idx, int rem, vector<int>& nums, vector<vector<int>>& dp){
        
        // base case
        if(idx == -1){
          if(rem == 0) return rem;
          else return INT_MIN;
        }

        // check dp
        if(dp[idx][rem] != -1){
          return dp[idx][rem];
        }

        int skip = recurMemo(idx-1, rem, nums, dp);
        
        int new_rem = (rem - nums[idx] % 3 + 3) % 3;
        int take = recurMemo(idx - 1, new_rem, nums, dp);

        if(take != INT_MIN){
          take = take + nums[idx];
        }

        return dp[idx][rem] = max(take, skip);
      }
public:
    int maxSumDivThree(vector<int>& nums) {
        
        int n = nums.size();

        // Recursion
        // return recur(n-1, 0, nums);

        // TopDown
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return recurMemo(n-1, 0, nums, dp);

    }
};