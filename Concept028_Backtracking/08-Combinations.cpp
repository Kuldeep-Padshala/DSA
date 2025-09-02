// LC: 77 m

class Solution {

  void solve(int start, int n, int k, vector<int>& path, vector<vector<int>>& ans){

    if(path.size()==k){
      ans.push_back(path);
      return;
    }

    for(int i = start; i<=n; i++){

      path.push_back(i);
      solve(i+1, n, k, path, ans);
      path.pop_back();
    }
  }
public:
    vector<vector<int>> combine(int n, int k) {
        
        // 1 to n mathi k elements
        vector<vector<int>> ans;
        vector<int> path;

        solve(1, n, k, path, ans);
        return ans;
    }
};