// LC: 1001 h 

class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        
        // vector<vector<bool>> mp(n, vector<bool>(n, false));

        unordered_set<long long> lampSet;
        unordered_map<int, int> rows, cols, diag, anti;

        for(auto& lamp: lamps){
          
          int row = lamp[0];
          int col = lamp[1];

          long long idx = (long long) row * n + col;

          if(lampSet.find(idx) != lampSet.end()){
            continue;
          }

          lampSet.insert(idx);
          rows[row]++;
          cols[col]++;
          diag[row - col]++;
          anti[row + col]++;
        }

        vector<int> ans;

        for(auto& query: queries){

          int row = query[0];
          int col = query[1];

          // check illumination
          if(rows[row] > 0 || cols[col] > 0 || diag[row-col] > 0 || anti[row+col] > 0){
            ans.push_back(1);
          }
          else{
            ans.push_back(0);
          }

          for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
              
              int nrow = row + i;
              int ncol = col + j;

              if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= n) continue;

              long long idx = (long long)nrow * n + ncol;
              if(lampSet.count(idx)){
                lampSet.erase(idx);
                rows[nrow]--;
                cols[ncol]--;
                diag[nrow - ncol]--;
                anti[nrow + ncol]--;
              }
            }
          }

          // mp[row][col] = false;

          // if(row>0) mp[row-1][col] = false;
          // if(row>0 && col>0) mp[row-1][col-1] = false;
          // if(row>0 && col<n-1) mp[row-1][col+1] = false;
          // if(row<n-1) mp[row+1][col] = false;
          // if(row<n-1 && col>0) mp[row+1][col-1] = false;
          // if(row<n-1 && col<n-1) mp[row+1][col+1] = false;
          // if(col>0) mp[row][col-1] = false;
          // if(col<n-1) mp[row][col+1] = false;
        }

        return ans;
    }
};


// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 1 1
// 1 1 1 1 1