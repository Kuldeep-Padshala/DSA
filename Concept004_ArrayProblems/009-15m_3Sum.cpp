// LC: 15 m 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // Two Pointers

        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());


        for (int i=0; i<n-2; i++){

            // skip duplicate
            if(i > 0 && nums[i] == nums[i-1]) continue;


            int target = -nums[i];            // We need two numbers that sum to -nums[i]

            int s = i+1;
            int e = n-1;

            while(s < e){

                int sum = nums[s] + nums[e];

                if(sum == target){
                    
                  ans.push_back({nums[i], nums[s], nums[e]});


                  // Step 4: Skip duplicates for s and e pointers
                  while(s<e && nums[s] == nums[s+1]){
                    s++;
                  } 
                  while(s<e && nums[e] == nums[e-1]){
                    e--;
                  }

                  s++;
                  e--;
                }
                else if(sum<target){
                  s++;                  // Need a larger sum
                } else {
                  e--;                  // Need a smaller sum
                }
            }
        }


        return ans;
    }
};