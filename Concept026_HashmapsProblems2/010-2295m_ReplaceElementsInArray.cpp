// LC: 2295 m 

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        
        // map<int, int> mp(operations.begin(), operations.end());    // works for vector of pair of int

        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
          mp[nums[i]] = i;
        }

        for(auto& op: operations){
          nums[mp[op[0]]] = op[1];

          mp[op[1]] = mp[op[0]];   // imp
          mp.erase(op[0]);
        }

        return nums;
    }
};