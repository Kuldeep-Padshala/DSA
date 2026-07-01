// LC: 48 m 

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<n-1; i++){
          for(int j=i+1; j<m; j++){
            // cout << matrix[i][j] << " " << matrix[j][i] << endl;
            swap(matrix[i][j],matrix[j][i]);
          }
        }

        for(int i=0;i<n;i++){
          for(int j=0;j<m/2;j++){
            swap(matrix[i][j],matrix[i][m-1-j]);
          }
        }
    }
};