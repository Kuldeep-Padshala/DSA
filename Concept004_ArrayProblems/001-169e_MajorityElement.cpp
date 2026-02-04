// LC: 169 e 

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // Boyer-Moore Voting Algorithm

        int n = nums.size();
        int count = 1;
        int majority = nums[0];  // Assume the first element as majority candidate

        for(int i=1; i<n; i++){
            
          if(nums[i] ==majority){
            count++;
          }

          else{
            count--;

            // if count 0, atyar sudhi ma koi majority nathi
            if(count == 0){
              majority= nums[i];
              count = 1;
            }
          }
        }

        return majority;
    }
};