// LC: 16m 3Sum Closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        // Two Pointers

        int n = nums.size();
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;

        for(int i=0; i<n-2; i++){

            // skip duplicate
            // if(i > 0 && nums[i] == nums[i-1]) continue;


            int tgt = target - nums[i];            // We need two numbers that sum to -nums[i]

            int s = i+1;
            int e = n-1;

            while(s < e){

                int sum = nums[s] + nums[e];

                if(sum == tgt){                    
                  return target;
                }
                else if(sum<tgt){
                  s++;                  // Need a larger sum
                } 
                else {
                  e--;                  // Need a smaller sum
                }
                if(abs(sum-tgt) < abs(diff)){
                  diff = sum - tgt;
                }
            }
        }

        return target + diff;
    }
};