// LC: 40 m

class Solution {

  void solve(int index, vector<int>& arr, int target, vector<int>& path, vector<vector<int>>& ans){

    // base cases

    if(target == 0){                // target 0 thia gyo, path valid chhe
      ans.push_back(path);
      return;
    }

    if(index == arr.size() || target < 0) {      // invalid
      return;
    }

    // logic: 
    for(int i=index; i<arr.size(); i++){

      // dupicates remove karse
      if(i > index && arr[i] == arr[i - 1]) {
        continue;
      }

      // wrong case
      if (arr[i] > target) {
        break;
      }

      path.push_back(arr[i]);

      // next index mate call kairu
      solve(i+1, arr, target - arr[i], path, ans);

      // backtracing
      path.pop_back();           // curr index je add kairo to e kadhi naikho

    }
  }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> path;

        sort(candidates.begin(), candidates.end());

        //   index    arr
        solve(0, candidates, target, path, ans);
        return ans; 
    }
};

  
