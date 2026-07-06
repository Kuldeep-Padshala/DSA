// LC:1691 h 

class Solution {

  bool check(vector<int> &base, vector<int> &upperBox){

    return (upperBox[0] <= base[0] && 
            upperBox[1] <= base[1] && 
            upperBox[2] <= base[2]);
  }

  // check LC: 300 for this 
  int spaceOpt(vector<vector<int>>& cuboids){
    
    int n = cuboids.size();
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    for(int curr=n-1; curr>=0; curr--){
      for(int prev=curr-1; prev>=-1; prev--){

        // include
        int take = 0;
        if(prev == -1 || check(cuboids[curr], cuboids[prev])){
          //         height
          take = cuboids[curr][2] + nextRow[curr+1];
        }

        // exclude
        int notTake = 0 + nextRow[prev+1];
        currRow[prev+1] = max(take, notTake); 
      }
      nextRow = currRow;
    }
    return nextRow[0];
  }

public:
    int maxHeight(vector<vector<int>>& cuboids) {

        //  l  b  h
        // [12,23,45]
        // [20,45,50]
        // [37,53,95]
        // sort cuboids internally, max is height and other two are base
        // then sort on the basis of thei l b
        
        for(auto& lbh: cuboids){
          sort(lbh.begin(), lbh.end());
        }

        sort(cuboids.begin(), cuboids.end());

        return spaceOpt(cuboids);    // longest integer substring



        

        // for (auto& a : cuboids){
        //   sort(begin(a), end(a));
        // }

        // cuboids.push_back({0, 0, 0});
        // sort(begin(cuboids), end(cuboids));

        // int n = cuboids.size(), ans = 0;

        // vector<int> dp(n);

        // for (int j = 1; j < n; ++j){
        //   for (int i = 0; i < j; ++i){
            
        //     if (cuboids[i][0] <= cuboids[j][0] && cuboids[i][1] <= cuboids[j][1] && cuboids[i][2] <= cuboids[j][2]) {
        //       dp[j] = max(dp[j], dp[i] + cuboids[j][2]);
        //       ans = max(ans, dp[j]);
        //     }
        //   }
        // }
        // return ans;
    }
};
