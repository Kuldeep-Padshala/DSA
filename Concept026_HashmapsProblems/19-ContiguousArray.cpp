// LC: 525 m 

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int> firstIndex; // stores earliest index of a sum
        firstIndex[0] = -1; // sum = 0 before we start

        int sum=0, ans=0;

        for(int i=0; i<nums.size(); i++){

          if(nums[i]==0){
            sum += -1;
          }
          else{
            sum += 1;
          }

          if(firstIndex.count(sum)){          // equal 0s and 1s
            ans = max(ans, i - firstIndex[sum]);
          } 
          else{                           // first time seen this sum
            firstIndex[sum] = i;
          }
        }
        return ans;
    }
};