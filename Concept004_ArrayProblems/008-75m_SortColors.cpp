// LC: 75 m 

class Solution {
public:
    void sortColors(vector<int>& nums) {

        // Dutch national flag Algorithm

        int start=0, end=nums.size()-1, mid=0;

        while(mid<=end){

          if(nums[mid]==0){
            swap(nums[mid++], nums[start++]);
          }

          else if(nums[mid]==1){
            mid++;
          }

          else{
            swap(nums[mid], nums[end--]);   // after swap, checking the nums[mid] again
          }
        }

        // int red=0, white=0;
        // for(int num: nums){
        //   if(num==0) red++;
        //   else if(num==1) white++;
        // }

        // for(int i=0; i<nums.size(); i++){

        //   if(red-- > 0) nums[i] = 0;
        //   else if(white-- > 0) nums[i] = 1;
        //   else nums[i] = 2;
        // }

    }
};