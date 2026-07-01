// LC: 312 h 

class Solution {

      int recur(int s, int e, vector<int>& nums){

        // Base case
        if(s>e) return 0;

        int maxi = INT_MIN;

        for(int idx=s; idx<=e; idx++){
          int coins = nums[s-1] * nums[idx] * nums[e+1]
                      + recur(s, idx-1, nums)
                      + recur(idx+1, e, nums);
          maxi = max(maxi, coins);
        }
        return maxi;

      }

      int recurMemo(int s, int e, vector<int>& nums, vector<vector<int>>& dp){

        // Base case
        if(s>e) return 0;

        // check dp
        if(dp[s][e] != -1){
          return dp[s][e];
        }

        int maxi = INT_MIN;

        for(int idx=s; idx<=e; idx++){
          int coins = nums[s-1] * nums[idx] * nums[e+1]
                      + recurMemo(s, idx-1, nums, dp)
                      + recurMemo(idx+1, e, nums, dp);
          maxi = max(maxi, coins);
        }
        return dp[s][e] = maxi;

      }

      int tabulation(vector<int>& nums){

        int n = nums.size() - 2;
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int s=n; s>=1; s--){
          for(int e=s; e<=n; e++){

            int maxi = INT_MIN;

            for(int idx=s; idx<=e; idx++){
              int coins = nums[s-1] * nums[idx] * nums[e+1]
                          + dp[s][idx-1]
                          + dp[idx+1][e];
              maxi = max(maxi, coins);
            }
            dp[s][e] = maxi;
          }
        }

        return dp[1][n];

      }
      
public:
    int maxCoins(vector<int>& nums) {
        
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);

        //   0   1 2 3 4 5
        // ['1', 3,1,5,8,'1']
        //       s     e

        // Recursion
        // return recur(1, n, nums);

        // TopDown
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return recurMemo(1, n, nums, dp);

        // BottomUp
        return tabulation(nums);

    }
};