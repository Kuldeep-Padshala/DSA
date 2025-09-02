// LC:733 e 

class Solution {

  void dfs(int row, int col, vector<vector<int>>& grid, int oldColor, int newColor){

    int m=grid.size();
    int n=grid[0].size();

    // base case: for invalid condition or 
    if(row<0 || col<0 || row>=m || col>=n || grid[row][col] != oldColor){
      return;
    }

    grid[row][col] = newColor;

    dfs(row-1, col, grid, oldColor, newColor);  //up
    dfs(row, col-1, grid, oldColor, newColor);  //left
    dfs(row+1, col, grid, oldColor, newColor);  //down
    dfs(row, col+1, grid, oldColor, newColor);  //right

  }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int oldColor = image[sr][sc];

        if (oldColor == color){
          return image; // avoid infinite loop
        }

        // vector<vector<int>> grid = image;     // we should no modify given data, not a good practice
        dfs(sr, sc, image, oldColor, color);
        return image;
    }
};