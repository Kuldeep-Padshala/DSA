// LC: 47 m

class Solution {

  void solve(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& ans){

    // base case
    if(path.size() == nums.size()){

      ans.push_back(path);
      return;
    }

    // logic

    for(int i=0; i<nums.size(); i++){

      //base cases:
      if(used[i]){     // current path ma nums[i] used thai gyo chhe
        continue;
      }
      if (i>=1 && nums[i]==nums[i - 1] && !used[i - 1]){      // skip duplicates
        continue;
      }

      // curr elem push kairo
      path.push_back(nums[i]);
      used[i] = true;

      // fun call kairu
      solve(nums, used, path, ans);

      // backtracking kairu
      path.pop_back();
      used[i] = false;
    }
  }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> path;
        vector<bool> used (nums.size(), false);

        sort(nums.begin(), nums.end());   // duplicates handling

        solve(nums, used, path, ans);
        return ans;
    }
};