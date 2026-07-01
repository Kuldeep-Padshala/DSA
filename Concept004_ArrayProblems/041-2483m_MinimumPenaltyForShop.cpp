// LC: 2843 m 

class Solution {
public:
    int bestClosingTime(string customers) {

        // prefix sum

        // 3 2 1 2 1

        int n = customers.size();

        vector<int> prefixSum(n+1, 0);    // prefixSum[i] = number of 'Y' in [0, i-1]
        prefixSum.push_back(0);

        for(int i = 0; i < n; i++){
          prefixSum[i+1] = prefixSum[i] + (customers[i] == 'Y');
        }
        
        int mini = INT_MAX;
        int idx = 0;

        for(int i=0; i<=n; i++){

          // Y after closing
          int yesAfter = prefixSum[n] - prefixSum[i];

          // N before closing (0 to i-1)
          int noBefore = i - prefixSum[i];

          int penalty = yesAfter + noBefore;

          if(penalty < mini){
            mini = penalty;
            idx = i;
          }
        }
        return idx;
        
    }
};