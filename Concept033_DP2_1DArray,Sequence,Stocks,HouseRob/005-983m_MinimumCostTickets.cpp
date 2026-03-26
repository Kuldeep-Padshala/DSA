// LC: 983 m 

class Solution {

      int recur(int idx, int n, vector<int>& days, vector<int>& costs){

        // base case
        if(idx >= n){
          return 0;
        }

        // one day pass
        int one = costs[0] + recur(idx+1, n, days, costs);
        
        // 7 day pass
        int i = idx;                               // i will give the idx after the completion of seven day pass
        while(i<n && days[i] < days[idx]+7){
          i++;
        }
        int seven = costs[1] + recur(i, n, days, costs);
        
        i = idx;                                  // i will give the idx after the completion of thirty day pass
        while(i<n && days[i] < days[idx]+30){
          i++;
        }
        int thirty = costs[2] + recur(i, n, days, costs);

        return min(one, min(seven, thirty));

      }

      int recurMemo(int idx, int n, vector<int>& days, vector<int>& costs, vector<int>& dp){

        // base case
        if(idx >= n){
          return 0;
        }

        if(dp[idx] != -1){
          return dp[idx];
        }

        // one day pass
        int one = costs[0] + recurMemo(idx+1, n, days, costs, dp);
        
        // 7 day pass
        int i = idx;                               // i will give the idx after the completion of seven day pass
        while(i<n && days[i] < days[idx]+7){
          i++;
        }
        int seven = costs[1] + recurMemo(i, n, days, costs, dp);
        
        // 30 day pass
        i = idx;                                  // i will give the idx after the completion of thirty day pass
        while(i<n && days[i] < days[idx]+30){
          i++;
        }
        int thirty = costs[2] + recurMemo(i, n, days, costs, dp);

        return dp[idx] = min(one, min(seven, thirty));

      }

      int tabulation(vector<int>& days, vector<int>& costs){

        int n = days.size();
        vector<int> dp(n+1, INT_MAX);

        dp[n] = 0;

        for(int idx=n-1; idx>=0; idx--){
          
          // one day pass
          int one = costs[0] + dp[idx+1];
          
          // 7 day pass
          int i = idx;                               // i will give the idx after the completion of seven day pass
          while(i<n && days[i] < days[idx]+7){
            i++;
          }
          int seven = costs[1] + dp[i];
          
          // 30 day pass
          i = idx;                                  // i will give the idx after the completion of thirty day pass
          while(i<n && days[i] < days[idx]+30){
            i++;
          }
          int thirty = costs[2] + dp[i];

          dp[idx] = min(one, min(seven, thirty));

        }
        return dp[0];
      }

      int spaceOpt(vector<int>& days, vector<int>& costs){

        int ans = 0;
        
        //        day,  cost till now
        queue<pair<int,int>> week;
        queue<pair<int,int>> month;

        for(int day: days){
          
          while(!week.empty() && week.front().first + 7 <= day){
            week.pop();
          }
          while(!month.empty() && month.front().first + 30 <= day){
            month.pop();
          }
          week.push({day, ans+costs[1]});
          month.push({day, ans+costs[2]});

          ans = min(ans+costs[0], min(week.front().second, month.front().second));
        }
        return ans;
      }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();

        // Recuresion
        // return recur(0, n, days, costs);

        // TopDown
        // vector<int> dp(n, -1);
        // return recurMemo(0, n, days, costs, dp);

        // BottomUp
        // minimum hoi tyare bottom up ma initially INT_MAX
        // return tabulation(days, costs);

        // Space optimization
        // using queue
        // why? it is making a scycle of 7 days or 30 days
        // for eg. if we are at 34th day, then we we will remove entries of first 4 days
        return spaceOpt(days, costs);
    }
};