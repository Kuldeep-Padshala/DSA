// LC: 1906 m 

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        
        int n = nums.size();

        vector<vector<int>> hash(n+1,vector<int>(101,0));

        for(int i=0; i<n; i++){
          hash[i+1] = hash[i];
          hash[i+1][nums[i]]++;
        }

        vector<int> ans;

        for(auto q : queries){
          int s=q[0];
          int e=q[1];

          vector<int> val;
          for(int i=1; i<101; i++){
            if(hash[e+1][i]-hash[s][i] > 0){
              val.push_back(i);
            }
          }

          int mini = INT_MAX;
          for(int i=1; i<val.size(); i++){
            mini = min(mini,val[i]-val[i-1]);
          }
          
          if(mini==INT_MAX) ans.push_back(-1);
          else ans.push_back(mini);
        }
        
        return ans;
    }
};