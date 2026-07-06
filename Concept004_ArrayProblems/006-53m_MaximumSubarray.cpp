// LC: 53 m 

class Solution {

    int tabulation(vector<int>& nums){

      int n = nums.size();

      // dp[i] stores the maximum subarray sum ending at index i
      vector<int> dp(n);

      // base case
      dp[0] = nums[0];
      
      int maxSum = nums[0];

      for(int i=1; i<n; i++){

        dp[i] = max(nums[i], nums[i] + dp[i-1]);        // start a new subarray at index i or extend the previous one
        maxSum = max(maxSum, dp[i]);
      }
      return maxSum;
    }

public:
    int maxSubArray(vector<int>& nums) {

        // Kadane’s Algorithm

        int currSum = nums[0];
        int maxSum = nums[0];
        
        for(int i=1; i<nums.size(); i++){

          currSum = max(currSum + nums[i], nums[i]);
          maxSum = max(maxSum, currSum);
        }
        
        return maxSum;  // Return the maximum subarray sum found
        
        // BottomUp
        // return tabulation(nums);

        // TLE
        // int n = nums.size();
        // int max_sum = INT_MIN;

        // for(int s=0; s<n; s++){
          
        //   int currSum = 0; 
        //   for(int e=s; e<n; e++){
              
        //     currSum += nums[e];    
        //     max_sum = max(max_sum, currSum);        
        //   }
        // }
        // return max_sum;
    }
};