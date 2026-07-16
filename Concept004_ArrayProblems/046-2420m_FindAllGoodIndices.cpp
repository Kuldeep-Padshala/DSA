// LC: 2420 m 

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        
        // prefix sum
        
        int n = nums.size();
        vector<int> dec(n, 1), inc(n, 1);

        for(int i=1; i<n; i++){

            if(nums[i-1] >= nums[i]){
              dec[i] = 1 + dec[i-1];
            }
            
            int j = n-1-i;
            if(nums[j] <= nums[j+1]){
              inc[j] = 1 + inc[j+1];
            }
        }

        vector<int> ans;

        for(int i=k; i < n-k; i++){

          if(inc[i+1] >= k && dec[i-1] >= k){
            ans.push_back(i);
          }
        }

        return ans;
    }
};