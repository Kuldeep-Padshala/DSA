// LC: 494 m 

class Solution {
public:

    void solve(int index, int sum, int& count, int target, vector<int>& nums){

      // base case
      if(index == nums.size()){
        if(sum == target){
          count++;
        }
        return;
      }

      // ek var add kari ne try
      solve(index + 1, sum + nums[index], count, target, nums);

      // ek var subtract  
      solve(index + 1, sum - nums[index], count, target, nums);

    }

    int recur(int idx, int tgt, vector<int>& nums){

      // base case
      if(idx == 0){
        if(tgt == 0 && nums[idx]==0){
          return 2;
        }
        else if(abs(tgt) == abs(nums[idx])){
          return 1;
        }
        else{
          return 0;
        }
      }

      int add = recur(idx-1, tgt-nums[idx], nums);
      int minus = recur(idx-1, tgt+nums[idx], nums);

      return add + minus;
    }

    int recurMemo(int idx, int tgt, vector<int>& nums, vector<vector<int>>& dp, int offset){

      // base case
      if(idx == 0){
        if(tgt == 0 && nums[idx]==0){
          return 2;
        }
        else if(abs(tgt) == abs(nums[idx])){
          return 1;
        }
        else{
          return 0;
        }
      }

      // conver tgt to index
      int T = tgt + offset;
      if (T < 0 || T >= dp[0].size()) {
          return 0;  // impossible target
      }


      // check dp
      if(dp[idx][T] != -1){
        return dp[idx][T];
      }

      int add = recurMemo(idx-1, tgt-nums[idx], nums, dp, offset);
      int minus = recurMemo(idx-1, tgt+nums[idx], nums, dp, offset);

      return dp[idx][T] = add + minus;
    }

    // gfg paartition with given diff
    int tabulation(int k, vector<int>& arr){
            
      int n = arr.size();
      vector<vector<int>> dp(n, vector<int>(k+1, 0));
      
      for(int idx=0; idx<n; idx++){
          dp[idx][0] = 1;
      }
      
      if (arr[0] == 0)
          dp[0][0] = 2;
      else
          dp[0][0] = 1;
          
      if(arr[0] != 0 && arr[0] <= k){
          dp[0][arr[0]] = 1;
      }
      
      for(int idx=1; idx<n; idx++){
          for(int target=0; target<=k; target++){
              
              int noTake = dp[idx-1][target];
  
              // take
              int take = 0;
              if(target >= arr[idx]){
                  take = dp[idx-1][target-arr[idx]];
              }
              
              dp[idx][target] = take + noTake;
          }
      }
      return dp[n-1][k];
    }

    int countPartitions(vector<int>& arr, int diff) {
        
        // Code here
        // s1 - s2 = diff
        // s1 = total - s2
        // total - s2 - s2 = diff
        // 2 s2   = total - diff
        // s2 = (total - diff) / 2
        
        int total = 0;
        for(int num: arr){
            total += num;
        }
        int s2 = (total - diff);
        if(s2 % 2 != 0  || s2 < 0) return 0;
        s2 /= 2;
        
        return tabulation(s2, arr);
        
    }

    
    int findTargetSumWays(vector<int>& nums, int target) {
        
        // int count=0;
        // solve(0, 0, count, target, nums);

        int n = nums.size();
        
        // Recursion
        // return recur(n-1, target, nums);

        // TopDown
        // int total = accumulate(nums.begin(), nums.end(), 0);
        // int offset = total;

        // // Safety check: target out of possible range
        // if (abs(target) > total) return 0;

        // vector<vector<int>> dp(n, vector<int>((2*total)+3, -1));
        // return recurMemo(n-1, target, nums, dp, offset);

        // Bottom up  (different)
        return countPartitions(nums, target);

    }
};