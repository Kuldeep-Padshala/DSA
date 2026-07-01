// LC: 3661 h 

class Solution {

    // Simple binary search to count walls in [L, R]
    int countWalls(long long L, long long R, const vector<int>& walls) {
        
        if (L > R){
          return 0;
        }

        int l = lower_bound(walls.begin(), walls.end(), L) - walls.begin();
        int r = upper_bound(walls.begin(), walls.end(), R) - walls.begin() - 1;

        if (l > r) return 0;
        return (r - l + 1);
    }

    int recurMemo(int idx, int prevFiredRight, vector<pair<int,int>>& robos, vector<int>& walls, auto& dp){

        int n = robos.size();

        // Base case
        if(idx == n){
          return 0;
        }

        // check dp
        if(dp[idx][prevFiredRight] != -1){
          return dp[idx][prevFiredRight];
        }

        long long pos = robos[idx].first;
        long long dist = robos[idx].second;

        long long covered_until = -3000000000LL; // Safe -infinity
        if(idx > 0){
          
          if(prevFiredRight == 1){
            // If prev fired right, walls are destroyed up to its bullet reach (or our current pos)
            covered_until = min(0LL + robos[idx-1].first + robos[idx-1].second, pos);
          } 
          else{
            // If prev fired left, it only destroyed walls up to its own position
            covered_until = robos[idx-1].first;
          }
        }

        // LEFT
        long long leftLimit = pos - dist;
        if(idx > 0){
          leftLimit = max(leftLimit, (long long)robos[idx-1].first);
        }

        // Apply your boundary check: avoid double counting what is already covered
        long long actualLeftLimit = max(leftLimit, covered_until + 1);
        
        int left = countWalls(actualLeftLimit, pos, walls) + recurMemo(idx+1, 0, robos, walls, dp);


        // RIGHT
        long long rightLimit = pos + dist;
        if(idx < n-1){
          rightLimit = min(rightLimit, (long long)robos[idx+1].first);
        }

        // Apply your boundary check: avoid double counting what is already covered
        long long actualRightLimit = max(pos, covered_until + 1);
        
        int right = countWalls(actualRightLimit, rightLimit, walls) + recurMemo(idx + 1, 1, robos, walls, dp);


        return dp[idx][prevFiredRight] = max(left, right);
    }

public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        
        int n = robots.size();
        int m = walls.size();

        vector<pair<int,int>> robos;
        for(int i=0; i<n; i++){
          robos.push_back({robots[i], distance[i]});
        }

        sort(robos.begin(), robos.end());
        sort(walls.begin(), walls.end());

        // TopDown
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return recurMemo(0, 0, robos, walls, dp);
    }
};