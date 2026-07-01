// LC: 2536 m

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        
        // prefix sum
        
        vector<vector<int>>  prefixSum(n+1, vector<int>(n, 0));

        for(auto& q: queries){

          const int r1=q[0], c1=q[1], r2=q[2], c2=q[3];

          prefixSum[r1][c1]++;
          prefixSum[r2+1][c1]--;

          if (c2+1<n){
            prefixSum[r1][c2+1]--;
            prefixSum[r2+1][c2+1]++;
          }
        }

        for(int i=0; i<n; i++){
          for(int j=1; j<n; j++){
            prefixSum[i][j] += prefixSum[i][j-1];
          }
        }

        for(int j=0; j<n; j++){
          for(int i=1; i<n; i++){
            prefixSum[i][j] += prefixSum[i-1][j];
          }
        }

        prefixSum.resize(n);
        return prefixSum;
    }
};