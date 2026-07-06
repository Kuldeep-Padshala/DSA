class Solution {

    apply gravity row-wise
    void applyGravity(vector<char>& row){
        
        int n = row.size();
        int s = n-1;
        int e = n-1;

        while(s>=0){
            
            if(row[s]=='.'){
              s--;
            }

            else if(row[s]=='#'){

              if(row[e]=='.'){
                swap(row[e], row[s]);
              }
              s--;
              e--;
            }
            else if(row[s]=='*'){
              s--;
              e=s;
            }            
        }
    }
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        

        //
        
        int m = box.size();
        int n = box[0].size();

        for(int row=0; row<m; row++){
          applyGravity(box[row]);
        }

        // rotate the data
        vector<vector<char>> ans(n, vector<char>(m));

        for(int row=0; row<m; row++){
          for(int col=0; col<n; col++){
            ans[col][m-row-1] = box[row][col];
          }
        }

        return ans;

        //

        int m = box.size();
        int n = box[0].size();
        
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        
        for(int row=0; row<m; row++){
            
          int i = n-1;
          for(int col=n-1; col>=0; col--){
              
            if(box[row][col] == '#'){
              
              ans[i][m-row-1] = '#';
              i--;
            }

            if(box[row][col] == '*') {
              
              ans[col][m-row-1] = '*';
              i = col-1;
            }

          }
        }
        
        return ans;
    }
};