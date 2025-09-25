// gfg

// Geek's Training
// Geek is going for n days training program. He can perform any of these activities: Running, Fighting, Learning, Practice.
// Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity 
// on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent 
// the points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve.

class Solution {
    
        int recur(int day, int last, vector<vector<int>>& arr){
            
            
            // Base case, we will just find max(not last) as there's no future dependency
            if(day == 0){
                int maxi = 0;
                for(int task=0; task<3; task++){
                    if(task!=last){
                        maxi = max(maxi, arr[0][task]);
                    }
                }
                return maxi;
            }
            
            int maxi = 0;
            for(int task = 0; task<3; task++){
                if(task != last){
                    int points = arr[day][task] + recur(day-1, task, arr);
                    maxi = max(maxi, points);
                }
            }
            return maxi;
        }
        
        int recurMemo(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp){
            
            // Base case, we will just find max(not last) as there's no future dependency
            if(day == 0){
                int maxi = 0;
                for(int task=0; task<3; task++){
                    if(task!=last){
                        maxi = max(maxi, arr[0][task]);
                    }
                }
                dp[day][last] = maxi;
                return dp[day][last];
            }
            
            if(dp[day][last] != -1){
                return dp[day][last];
            }
            
            int maxi = 0;
            for(int task = 0; task<3; task++){
                if(task != last){
                    int points = arr[day][task] + recurMemo(day-1, task, arr, dp);
                    maxi = max(maxi, points);
                }
            }
            
            dp[day][last] = maxi;
            return dp[day][last];
        }
        
        int tabulation(vector<vector<int>>& arr){
            
            int n = arr.size();
            vector<vector<int>> dp(n, vector<int>(4, 0));
            
            // Base case
            dp[0][0] = max(arr[0][1], arr[0][2]);
            dp[0][1] = max(arr[0][0], arr[0][2]);
            dp[0][2] = max(arr[0][0], arr[0][1]);
            dp[0][3] = max(arr[0][0], max(arr[0][1], arr[0][2]));   // case for only one day
            
            for(int day=1; day<n; day++){
                for(int last=0; last<4; last++){
                    
                    dp[day][last] = 0;
                    for(int task = 0; task<3; task++){
                        if(task != last){
                            int points = arr[day][task] + dp[day-1][task];
                            dp[day][last] = max(dp[day][last], points);
                        }
                    }
                }
            }
            
            return dp[n-1][3];
            
        }
        
        int spaceOpt(vector<vector<int>>& arr){
            
            int n = arr.size();
            vector<int> prev(4, 0);
            
            // Base case
            prev[0] = max(arr[0][1], arr[0][2]);
            prev[1] = max(arr[0][0], arr[0][2]);
            prev[2] = max(arr[0][0], arr[0][1]);
            prev[3] = max(arr[0][0], max(arr[0][1], arr[0][2]));   // case for only one day
            
            for(int day=1; day<n; day++){
                
                vector<int> curr(4,0);
                for(int last=0; last<4; last++){
                    
                    curr[last] = 0;
                    for(int task = 0; task<3; task++){
                        if(task != last){
                            int points = arr[day][task] + prev[task];
                            curr[last] = max(curr[last], points);
                        }
                    }
                }
                prev = curr;
            }
            
            return prev[3];
            
        }
  public:
    int maximumPoints(vector<vector<int>>& arr) {
        
        
        // Greedy approach fails here
        // eg. 10  50  1
        //     15  90  5
        // max of day 0,  50
        //     of day 1,  15 (as cannot pick same type on next day)
        
        // Now try all possible ways
        // Recursion
        // 1) make it in terms of indices
        // 2) do stuffs with index{
        //       I should know what i did on last day
        //       second parameter: last
        //    }
        // 3) find max
        
        int n = arr.size();
        
        // Recursion
        // return recur(n-1, -1, arr);
        
        // DP TopDown
        // vector<vector<int>> dp(n, vector<int>(4, -1));
        // return recurMemo(n-1, 3, arr, dp);
        
        // DP BottomUp
        // return tabulation(arr);
        
        // Space Optimization
        // As we are just depending on day-1. so all we need is just previous day's data, array of 4
        return spaceOpt(arr);
    }
};