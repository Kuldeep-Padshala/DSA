// LC: 2448 h

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        
        // binary search + prefix sum
        
        int n = nums.size();
        int s = INT_MAX;
        int e = INT_MIN;
        int mid;

        for(int i=0; i<n; i++){
          s = min(s,nums[i]);
          e = max(e,nums[i]);
        }

        long long totalCost = LLONG_MAX;

        long long midCost = 0;
        long long midCost1 = 0;

        while(s<=e){

            mid = s+(e-s)/2;

            midCost=0;
            midCost1=0;

            for(int i=0; i<n; i++){

              midCost += (abs(mid-nums[i]) * 1LL * cost[i]);
              midCost1 += (abs(mid+1-nums[i]) *1LL * cost[i]);
            }

            totalCost = min({totalCost, midCost, midCost1});

            if(midCost1 < midCost){
              s = mid+1;
            }
            else {
              e = mid-1;
            }
        }
        return totalCost;
    }
};