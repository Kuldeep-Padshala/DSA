class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        // Two pointers
        int s = 0;
        int e = nums.size()-1;

        while(s<e){

          if(nums[s] % 2 == 0){
            s++;
          }
          else if(nums[e] % 2 == 1){
            e--;
          }
          else{
            swap(nums[s], nums[e]);
            s++;
            e--;
          }
        }
        return nums;
    }
};