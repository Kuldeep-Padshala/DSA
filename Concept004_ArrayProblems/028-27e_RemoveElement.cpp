// LC: 27 e

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        // two pointers
        
        int n = nums.size();
        int s = 0;
        int e = n-1;

        while(s<=e){

          if(nums[s] != val){
            s++;
          } 
          else{
            swap(nums[s], nums[e]);
            e--;
          }
          
        }
        return s;
    }
};