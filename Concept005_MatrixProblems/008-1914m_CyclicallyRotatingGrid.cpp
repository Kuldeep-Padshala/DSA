// LC: 1914 m 

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        int m = grid.size();
        int n = grid[0].size();

        int bottom = m-1;
        int right = n-1;
        int top = 0;
        int left = 0;

        while(bottom > top && right > left){

            int total_layer_elements = 2*(bottom-top) + 2*(right-left);
            int K = k % total_layer_elements;
            
            while(K--){

                int temp = grid[top][left];

                // left to right
                for(int j=left; j<right; j++){
                  grid[top][j] = grid[top][j+1];
                }

                // top to bottom
                for(int i=top; i<bottom; i++){
                  grid[i][right] = grid[i+1][right];
                }

                // right to left
                for(int j=right; j>left; j--){
                  grid[bottom][j] = grid[bottom][j-1]; 
                }

                // bottom to top
                for(int i=bottom; i>top; i--){
                  grid[i][left] = grid[i-1][left];
                }

                grid[top+1][left] = temp;
            }
            top++, left++, bottom--, right--;
        }
        return grid;
        
    }
};