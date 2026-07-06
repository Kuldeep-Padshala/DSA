// LC: 1975 m

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        long long sum = 0;
        int neg = 0;
        int nano = INT_MAX;

        for(int i=0; i<n; i++){
          for(int j=0; j<n; j++){

            int x = matrix[i][j];

            if(x < 0){
              neg++;
            }
            sum += abs(x);
            nano = min(nano, abs(x));
          }
        }

        if(neg % 2 == 1){
          sum -= 2LL * nano;
        }

        return sum;
    }
};