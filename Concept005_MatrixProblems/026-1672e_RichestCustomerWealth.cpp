class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int maxi = 0;

        for(auto& row : accounts){
          
          // accumulate -> sum from start to end, initially zero
          int sum = accumulate(row.begin(), row.end(), 0);

          maxi = max(maxi, sum); 
        }

        return maxi;
    }
};