// LC: 2033 m

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> all;
        int mod = grid[0][0] % x;

        for(auto& row : grid){
          for(int num : row){

            if(num % x != mod){
              return -1;
            }
            all.push_back(num);
          }
        }

        sort(all.begin(), all.end());

        int median = all[all.size() / 2];
        int ans = 0;

        for (int num : all) {
          ans += abs(num - median) / x;
        }

        return ans;
    }
};