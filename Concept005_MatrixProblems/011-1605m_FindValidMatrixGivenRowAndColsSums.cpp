// LC: 1605 m 

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        
        int m = rowSum.size();
        int n = colSum.size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        int row = 0, col = 0;

        while(row < m && col < n){
            
            int val = min(rowSum[row], colSum[col]);
            ans[row][col] = val;

            rowSum[row] -= val;
            colSum[col] -= val;

            if(rowSum[row] == 0){
              row++;
            }
            if(colSum[col] == 0){
              col++;
            }
        }
        return ans;
    }
};