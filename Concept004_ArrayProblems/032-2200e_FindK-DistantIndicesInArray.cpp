// LC: 2200 e 

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        

        int n = nums.size();
        int lastEnded = -1;
        vector<int> ans;

        for(int i=0; i<n; i++){
          if(nums[i] == key){
            for(int idx=max(lastEnded+1, i-k); idx<=min(n-1, i+k); idx++){
              ans.push_back(idx);
              // if(nums[idx] == k) 
            }
            lastEnded = min(n-1, i+k);
            if(lastEnded == n-1) return ans;
          }
        }

        return ans;
    }
};