// LC: 287 m 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // Cycle Detection Using Floyd’s Tortoise and Hare Algorithm :

        int slow = nums[0];
        int fast = nums[0];
        
        do{
          slow = nums[slow];
          fast = nums[nums[fast]];
        }while (slow != fast);
        
        // Phase 2: Find entrance to cycle
        slow = nums[0];
        
        while(slow != fast){
          slow = nums[slow];
          fast = nums[fast];
        }
        
        return slow;


        // Binary Search

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int s=0, e=n-1;

        while(s<e){

          int mid = s+(e-s)/2;

          if(mid>0 && nums[mid] == nums[mid-1]){
            return nums[mid];
          }

          if(mid<n-1 && nums[mid]==nums[mid+1]){
            return nums[mid];
          }

          else if(nums[mid]<mid+1){
            e=mid-1;
          }
          else{
            s=mid+1;
          }
        }
        return s;
    }
};