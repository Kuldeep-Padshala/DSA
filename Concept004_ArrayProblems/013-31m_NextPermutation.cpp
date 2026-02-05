// LC: 31 m 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        // Efficient In-Place Next Permutation Algorithm

        int n = nums.size();

        int pivotIdx = -1;   // right side thi pelo elem i, which is nums[i] < nums[i+1]

        // Step 1: Find the first decreasing element from the right
        for(int i=n-2; i>=0; i--){
            
          if(nums[i]<nums[i+1]){
            pivotIdx = i;  // Found the pivotIdx
            break;
          }
        }

        // Step 2: akho array is non-increasing (no next permutation)
        if (pivotIdx == -1) {
          // reverse(begin(nums), end(nums));
          sort(nums.begin(), nums.end());
          cout << "rev";
          return;
        }

        // Step 3: Find the next larger element (successor) to swap with pivotIdx
        for(int i=n-1; i>pivotIdx; i--){
          
          if(nums[i] > nums[pivotIdx]){
            swap(nums[pivotIdx], nums[i]);  // Swap pivotIdx with successor
            break;
          }
        }
        reverse(nums.begin() + pivotIdx + 1, nums.end());
    }
};