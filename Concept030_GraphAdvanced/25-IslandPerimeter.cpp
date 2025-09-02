// LC: 463 e 

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int ans = 0;

        for(int i =0; i<grid.size(); i++){
          for(int j=0; j<grid[0].size(); j++){

            if(grid[i][j] == 1){
              
              ans += 4; // 4 per square
              if(i>0 && grid[i-1][j] == 1){                  // shared top
                ans -= 2;
              } 
              if(j>0 && grid[i][j-1] == 1){                 // shared left
                ans -= 2;
              }
            
            }

          }
        }
        return ans;
    }
};