// gfg 

class Solution {
        
        int recur(int idx, int capacity, vector<int> &val, vector<int> &wt){
            
            // Base case
            if(idx == 0){
                
                if(wt[0] <= capacity) return val[0];
                else return 0;
            }
            
            int include, exclude;
            
            if(wt[idx] <= capacity)                               // iclude only if possible
            include = val[idx] + recur(idx-1, capacity - wt[idx], val, wt);        // minus own weight from cap
            
            exclude =     0   +  recur(idx-1, capacity, val, wt);
            
            int ans = max(include, exclude);
            return ans;
            
        }
        
        int recurMemo(int idx, int capacity, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp){
            
            // Base case
            if(idx == 0){
                
                if(wt[idx] <= capacity){
                    dp[idx][capacity] = val[idx];
                }
                else return 0;
            }
            
            // step 3
            if(dp[idx][capacity] != -1){
                return dp[idx][capacity];
            }
            
            int include, exclude;
            
            if(wt[idx] <= capacity)                               // iclude only if possible
            include = val[idx] + recurMemo(idx-1, capacity - wt[idx], val, wt, dp);        // minus own weight from cap
            
            exclude =   0  +  recurMemo(idx-1, capacity, val, wt, dp);
            
            dp[idx][capacity] = max(include, exclude);
            return dp[idx][capacity];
            
        }
        
        int tabulation(int n, int capacity, vector<int> &val, vector<int> &wt){
            
            // step 1
            vector<vector<int>> dp(n, vector<int>(capacity+1, 0));
            
            // step 2: Base case
            for(int w=wt[0]; w<=capacity; w++){
                if(wt[0] <= w){
                    dp[0][w] = val[0];
                }
                else{
                    dp[0][w] = 0;
                }
            }
            
            for(int idx = 1; idx<n; idx++){
                for(int w=0; w<=capacity; w++){
                    
                    int include = 0;
                    if(wt[idx] <= w){
                        include = val[idx] + dp[idx-1][w-wt[idx]];
                    }
                    int exclude = dp[idx-1][w];
                    
                    dp[idx][w] = max(include, exclude);
                }
            }
            return dp[n-1][capacity];
            
        }
        
        int spaceOpt(int n, int capacity, vector<int> &val, vector<int> &wt){
            
            // step 1
            vector<int> prev(capacity+1, 0);
            vector<int> curr(capacity+1, 0);
            
            // step 2: Base case
            for(int w=wt[0]; w<=capacity; w++){
                if(wt[0] <= w){
                    prev[w] = val[0];
                }
                else{
                    prev[w] = 0;
                }
            }
            
            for(int idx = 1; idx<n; idx++){
                for(int w=0; w<=capacity; w++){
                    
                    int include = 0;
                    if(wt[idx] <= w){
                        include = val[idx] + prev[w-wt[idx]];
                    }
                    int exclude = prev[w];
                    
                    curr[w] = max(include, exclude);
                }
                prev = curr;
            }
            return prev[capacity];
            
        }
        
        int spaceOpt2(int n, int capacity, vector<int> &val, vector<int> &wt){
            
            
            // Here we are depended on 2 things prev[w] or anything prev[w-wt[idx]]
            // So we do it in a single array curr
            // one problem for left to right, as we change curr[4] then if curr[7] depends on curr[4] which is new value not old
            
            // step 1
            // vector<int> prev(capacity+1, 0);
            vector<int> curr(capacity+1, 0);
            
            // step 2: Base case
            for(int w=wt[0]; w<=capacity; w++){
                if(wt[0] <= w){
                    curr[w] = val[0];
                }
                else{
                    curr[w] = 0;
                }
            }
            
            for(int idx = 1; idx<n; idx++){
                for(int w=capacity; w>=0; w--){
                    
                    int include = 0;
                    if(wt[idx] <= w){
                        include = val[idx] + curr[w-wt[idx]];
                    }
                    int exclude = curr[w];
                    
                    curr[w] = max(include, exclude);
                }
                // prev = curr;
            }
            return curr[capacity];
            
        }
  
public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
        int n = val.size();
        
        // recursion
        // return recur(n-1, W, val, wt);
        
        // DP topDown 
        // Value of 2 parameters are changing idx and capacity
        // vector<vector<int>> dp(n, vector<int>(W+1, -1));
        // return recurMemo(n-1, W, val, wt, dp);
        
        // DP bottomUp
        // return tabulation(n, W, val, wt);
        
        // Space optimization
        // return spaceOpt(n, W, val, wt);
        
        // Space optimization 2
        return spaceOpt2(n, W, val, wt);
    }
};