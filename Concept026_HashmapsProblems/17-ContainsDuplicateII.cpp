// LC: 219 e

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        unordered_map<int, int> last_seen;

        for(int i=0; i<nums.size(); i++){

          if(last_seen.count(nums[i]) && i - last_seen[nums[i]] <= k ){  // nums[i] present chhe ane i - j <=k
            return true;
          }
          last_seen[nums[i]] = i;
        }
        return false;
    }
};