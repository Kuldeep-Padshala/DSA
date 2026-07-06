// LC: 3197 h 

class Solution {

    // Function to calculate the minimum area of rectangle enclosing all ones in a submatrix 
    int minArea(vector<vector<int>>& grid, int st_i, int en_i, int st_j, int en_j) {
        
        int i, j, found = 0;

        int start_row = 1e9;
        int end_row = -1;
        int start_col = 1e9;
        int end_col = -1;

        for(i = st_i; i <= en_i; i++){
          for(j = st_j; j <= en_j; j++){

            if(grid[i][j]){
                start_row = min(start_row, i);
                end_row = max(end_row, i);
                start_col = min(start_col, j);
                end_col = max(end_col, j);
                found = 1;
            }
          }
        }

        if(found){
          return (end_row - start_row+1) * (end_col - start_col+1);
        }
        else return 0;
    }
public:
    int minimumSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int ans = 1e9;
        int one, two, three;

        /*
        -------------
        |    (1)    |
        |           |
        -------------
        | (2) | (3) |
        |     |     |
        -------------
        */
        for(int i=0; i<m; i++){

          one = minArea(grid, 0, i, 0, n-1);
          for(int j=0;j<n;j++){

            two = minArea(grid, i+1, m-1, 0, j);
            three = minArea(grid, i+1, m-1, j+1, n-1);
            ans = min(ans, one+two+three);
          }
        }
        
        /*
        -------------
        |     | (2) |
        |     |     |
          (1) -------
        |     |     |
        |     | (3) |
        -------------
        */
        for(int j=0; j<n; j++){
          
          one = minArea(grid, 0, m-1, 0, j);
          for(int i=0; i<m; i++){
            
            two = minArea(grid, 0, i, j+1, n-1);
            three = minArea(grid, i+1, m-1, j+1, n-1);
            ans = min(ans, one+two+three);
          }
        }
        
        /*
        -------------
        |     |     |
        | (2) |     |
        ------- (1) |
        |     |     |
        | (3) |     |
        -------------
        */
        for(int j=n-1; j>=0; j--){

          one = minArea(grid, 0, m-1, j+1, n-1);
          for(int i=0; i<m; i++){
              
            two = minArea(grid, 0, i, 0, j);
            three = minArea(grid, i+1, m-1, 0, j);
            ans = min(ans, one+two+three);
          }
        }
                           
        /*
        -------------
        | (2) | (3) |
        |     |     |
        ------------
        |           |
        |    (1)    |
        -------------
        */
        for(int i=m-1; i>=0; i--){

          one = minArea(grid, i+1, m-1, 0, n-1);
          for(int j=0; j<n; j++){
            
            two = minArea(grid, 0, i, 0, j);
            three = minArea(grid, 0, i, j+1, n-1);
            ans = min(ans, one+two+three);
          }
        }
        
        /*
        -------------
        |    (1)    |
        -------------
        |    (2)    |
        -------------
        |    (3)    |
        -------------
        */
        for(int i=0; i<m; i++){
          for(int j=i+1;j<m;j++){
              
            one = minArea(grid, 0, i, 0, n-1);
            two = minArea(grid, i+1, j, 0, n-1);
            three = minArea(grid, j+1, m-1, 0, n-1);
            ans = min(ans, one+two+three);
          }
        }
        
         /*
        -------------
        |   |   |   |
        |   |   |   |
        |(1)|(2)|(3)|
        |   |   |   |
        |   |   |   |
        -------------
        */        
        for(int i=0; i<n; i++){
          for(int j=i+1; j<n; j++){
              
            one = minArea(grid, 0, m-1, 0, i);
            two = minArea(grid, 0, m-1, i+1, j);
            three = minArea(grid, 0, m-1, j+1, n-1);
            ans = min(ans, one+two+three);
          }
        }
        
        return ans;
    }
};