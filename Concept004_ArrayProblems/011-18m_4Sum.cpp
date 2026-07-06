LC: 18 m

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // 2 Loops and Two Pointers

        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end()); // Sort the array to apply two-pointer efficiently


        // Loop for the first number
        for(int i=0; i<n-3; i++){

            if(i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates

            // Loop for the second number
            for(int j=i+1; j<n-2; j++){

                if (j > i+1 && nums[j] == nums[j - 1]) continue; // Skip duplicates


                long long tgt2 = (long long)target - nums[i] - nums[j];
                int s = j + 1;
                int e = n - 1;


                // Two-pointer for the remaining two numbers
                while(s < e){
                    
                  int sum = nums[s] + nums[e];


                  if(sum < tgt2){
                    s++;                      // Need a bigger sum
                  } 
                  else if (sum > tgt2) {
                    e--;                      // Need a smaller sum
                  } 
                  else {
                    ans.push_back({nums[i], nums[j], nums[s], nums[e]});

                    // Skip duplicates for left and right
                    int prevS = nums[s], prevE = nums[e];
                    while (s<e && nums[s] == prevS){
                      s++;
                    }
                    while (s < e && nums[e] == prevE){
                      e--;
                    }
                  }
                }
            }
        }
        return ans;

        
        
        // 2 Loops, Two Pointers and HashSet 

        set<vector<int>> uniqueQuadruplets;
        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end()); // Sort the array to use two-pointer
   
        // pick the first number
        for(int i=0; i<n-3; i++){
            // pick the second number
            for (int j=i+1; j<n-2; j++){

              long long tgt2 = (long long)target - nums[i] - nums[j]; // Avoid overfs
              int s = j+1;
              int e = n-1;

              // Two-pointer approach
              while(s < e){
                
                int sum = nums[s] + nums[e];

                if(sum == tgt2){
                  uniqueQuadruplets.insert({nums[i], nums[j], nums[s], nums[e]});
                  s++;
                  e--;
                }
                else if (sum < tgt2) {
                  s++;
                }
                else {
                  e--;
                }
              }
            }
        }

        ans.assign(uniqueQuadruplets.begin(), uniqueQuadruplets.end()); // Convert to vector
        return ans;

    }
};