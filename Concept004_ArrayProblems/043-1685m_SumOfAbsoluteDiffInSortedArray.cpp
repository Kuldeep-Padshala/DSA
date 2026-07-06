// LC: 1685 m 

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {


        
        // prefix sum

        int n = nums.size();
        vector<int> prefixSum(n, 0), ans;

        prefixSum[0] = nums[0];

        for(int i=1; i<n; i++){
          prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        for(int i=0; i<n; i++){
          int leftSum = (i > 0) ? prefixSum[i-1] : 0;
          int rightSum = prefixSum[n-1] - prefixSum[i];
          ans.push_back(nums[i]*i - leftSum + rightSum - nums[i]*(n-1-i));
        }
        return ans;
        

        // prefix sum + math

        int n = nums.size();
        vector<int> ans;

        vector<int> prefixSum(n), suffixSum(n);
        prefixSum[0] = nums[0];
        suffixSum[n-1] = nums[n-1];
        
        for(int i=1; i<n; i++){
          prefixSum[i] = prefixSum[i-1] + nums[i];
          suffixSum[n-i-1] = suffixSum[n-i] + nums[n-i-1];
        }
        
        // Calculate absolute differences and update the ans array
        for(int i=0; i<n; i++){

          int currAbsDiff = ( (nums[i]*i)-prefixSum[i]) 
                              + (suffixSum[i] - (nums[i] * (n-i-1))
                            );
          
          ans.push_back(currAbsDiff);
        }
        
        return ans;

        // Brute force (TLE)

        // int n = nums.size();
        // vector<int> ans;

        // for(int i=0; i<n; i++){
        //   int sum = 0;
        //   for(int j=0; j<n; j++){
        //     sum += abs(nums[i]-nums[j]);
        //   }
        //   ans.push_back(sum);
        // }
        // return ans;
    }
};