// LC: 442 m imp 

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        int n = nums.size();
        vector<int>ans;
        
        for(int i=0; i<n; i++){

          int x = abs(nums[i]);
          
          if(nums[x-1]<0){
            ans.push_back(x);
          }

          nums[x-1] *= -1;     // curr number vada index ne -ve kari chhi
        }

        return ans;
    }
};