// LC: 39 m

class Solution {

  void solve(int idx, vector<int>& arr, int target, vector<int>& path, vector<vector<int>>& ans){

    // base cases

    if(target == 0){                // target 0 thia gyo, path valid chhe
      ans.push_back(path);
      return;
    }

    if(idx == arr.size() || target < 0) {      // invalid
      return;
    }


    // logic: path ma curr elem add kari ne backtracking kari ne joi lidhu

    path.push_back(arr[idx]);     // curr no. path ma add kairo

    // target mathi current elem ni value minus kari didhi
    solve(idx, arr, target-arr[idx], path, ans);   // same idx mate function call, cause we can use it multiple times 
    
    // backtracking
    path.pop_back(); 


    // logic: have next index mate call kari didhu

    solve(idx+1, arr, target, path, ans);

  }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> path;

        //   idx    arr
        solve(0, candidates, target, path, ans);
        return ans;
    }
};