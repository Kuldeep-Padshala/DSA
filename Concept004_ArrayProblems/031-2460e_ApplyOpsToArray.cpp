// LC: 2460 e 

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {

        // Two Pointers
        int n = nums.size();

        // Apply operations
        for(int i=0;i<n-1; i++){
            
          if(nums[i] == nums[i+1]){
            nums[i] *= 2;
            nums[i+1] = 0;
          }
        }

        // Move zeros to end
        int k = 0;
        for(int i=0; i<n; i++){
            
          if(nums[i] != 0) {
            nums[k++] = nums[i];
          }
        }

        while(k < n) {
          nums[k++] = 0;
        }

        return nums;
    }
};