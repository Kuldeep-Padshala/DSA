// LC: 354 h 

class Solution {

      // LC: 300 to understand this, longest integer subsequence
      int optimalDp(vector<int>& nums){

        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i=1; i<nums.size(); i++){

          if(nums[i] > ans.back()){
            ans.push_back(nums[i]);
          }
          else{                  // find elem just bigger than curr
            int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[idx] = nums[i];
          }
        }
        return ans.size();
      }

public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        
        // sort by width asc, height desc
        // karan ke for same width, pela vadhare height vada ne lese
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
          
          if(a[0] == b[0]){
            return a[1] > b[1];
          }
          else{
            return a[0] < b[0];
          }
        });

        // extract heights
        vector<int> heights;
        for (auto &env : envelopes) {
          heights.push_back(env[1]);
        }

        // find LIS on heights  (strictly increasing)
        return optimalDp(heights);
    }
};