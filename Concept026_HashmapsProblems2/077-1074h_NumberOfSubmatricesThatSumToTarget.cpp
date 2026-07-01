// LC: 1074 h 

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int n = matrix[0].size();
        int m = matrix.size();

        int ans = 0;

        for(int i=0; i<m; i++){
          for(int j=1; j<n; j++){
            matrix[i][j] += matrix[i][j-1];
          }
        }

        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
          for(int j=i; j<n; j++){
            
            mp = {{0,1}};
            int curr = 0;

            for(int k=0; k<m; k++){

              if(i>0) curr += matrix[k][j] - matrix[k][i-1];
              else curr += matrix[k][j];

              if(mp.find(curr - target) != mp.end()){
                ans += mp[curr - target];
              }
              mp[curr]++;
            }
          }
        }
        return ans;
    }
};