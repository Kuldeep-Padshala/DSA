// LC: 2161 m 

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        // Two pointers

        int n = nums.size();
        vector<int> ans(n, pivot);

        int s = 0;
        int e = n-1;

        for(int i=0; i<n && s<e; i++){

          if(nums[i] < pivot) ans[s++] = nums[i];
          if(nums[n-1-i] > pivot) ans[e--] = nums[n-1-i];
          
        }
        return ans;

    }
};