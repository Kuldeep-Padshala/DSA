// LC: 2965 e 

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        // Math-based

        long long n = grid.size();
        long long N = n*n;

        // expected
        long long expectedSum = (N*(N+1)) / 2;
        long long expectedSquareSum = (N*(N+1) * (2*N+1)) / 6;

        // actual
        long long actualSum = 0, actualSquareSum = 0;

        for(int i=0; i<n; i++){           // Computing the actual sum and sum of squares
          for(int j=0; j<n; j++){
              
            int num = grid[i][j];
            actualSum += num;
            actualSquareSum += (int)num * num;
          }
        }

        // a - b
        long long sumDifference = actualSum - expectedSum;


        // a^2 - b^2 = (a - b)(a + b)
        long long squareSumDifference = actualSquareSum - expectedSquareSum;


        // (a + b) = squareSumDifference / (a - b)
        int sum_ab = squareSumDifference / sumDifference;


        int repeated = (sum_ab + sumDifference) / 2;
        int missing = (sum_ab - sumDifference) / 2;

        return {repeated, missing};
    }
};