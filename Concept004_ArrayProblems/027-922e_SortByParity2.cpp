class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        // Two pointers
        int s = 0;
        int e = nums.size()-1;

        while(s<e){

          if(s%2 == nums[s] % 2){
            s++;
          }
          else if(e % 2 == nums[e]%2){
            e--;
          }
          else if(s % 2 != e % 2){
            swap(nums[s], nums[e]);
            s++;
            e--;
          }
          
          else{ // s and e both are odd or both are even and values are opposite

            // Move e until we find one where parity index != value parity
            int k = e-2;

            while(k>s){ 

              if(k % 2 == nums[k] % 2){
                break;
              }
              else{
                k -= 2;
              }
            }

            if(k > s){
              swap(nums[s],nums[k]);
              s++;
            }
            else{
              e--;
            }
          }
        }
        return nums;
    }
};