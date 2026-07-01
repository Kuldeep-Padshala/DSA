// LC: 2352 m 

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        
        int n = grid.size();
        map<vector<int>, int> rows;
        
        for(auto &row : grid){
          rows[row]++;
        }

        int ans = 0;

        for(int c=0; c<n; c++){

          vector<int> col;
          for(int r=0; r<n; r++){
            col.push_back(grid[r][c]);
          }
          
          if(rows.count(col)){
            ans += rows[col];
          }
        }
        return ans;
    }
};