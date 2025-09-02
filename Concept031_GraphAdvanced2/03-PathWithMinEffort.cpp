class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int m = heights.size();
        int n = heights[0].size();

        // Min-heap:      {effort, {row, col}}     Here effort should be max
        priority_queue<pair<int, pair<int,int>>, 
                       vector<pair<int, pair<int,int>>>, 
                       greater<pair<int, pair<int,int>>>> pq;

        vector<vector<int>> dist(m, vector<int>(n, 1e9));        // minimum of all the max efforts
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<int> del_row = {-1, 0, 1, 0};
        vector<int> del_col = {0, 1, 0, -1};

        while(!pq.empty()){

          auto it = pq.top();
          int effort = it.first;
          int row = it.second.first;
          int col = it.second.second;
          pq.pop();

          // Whenever pq's top is m-1,n-1  it means it has miminum of all the max efforts
          // There no possible value for m-1 n-1 smaller than effort
          if(row == m-1 && col == n-1){            // reached target
            return effort;
          }

          for(int i=0; i<4; i++){
            
            int nrow = row + del_row[i];
            int ncol = col + del_col[i];
            
            if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n){
              
              int diff = abs(heights[nrow][ncol] - heights[row][col]);
              int maxEffort = max(diff, effort);                         // max effort, will be pushed in queue

              if(maxEffort < dist[nrow][ncol]) {           // min of all efforts
                dist[nrow][ncol] = maxEffort;
                pq.push({maxEffort, {nrow, ncol}});     // if nro ncol can be reached by lesser effort, no need to push in pq
              }
            }
          }

        }
        return 0; // unreachable
    }
};