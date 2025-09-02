// LC: 78 m

class Solution {
private:
    void solve(vector<int> nums, vector<int> output, int i, vector<vector<int> >& ans) {      //reference addres important
        //base case
        if(i >= nums.size()) {
            ans.push_back(output);
            return ;
        }
        
        //exclude
        solve(nums, output, i+1, ans);
        
        //include
        int element = nums[i];          //nums[0]
        output.push_back(element);
        solve(nums, output, i+1, ans);
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int> > ans;
        vector<int> output;
        int index = 0;
        solve(nums, output, index, ans);
        return ans;
        
    }
};