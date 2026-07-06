// LC: 121 e 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        // Single pass approach

        int n = prices.size();
        int buy = prices[0];
        int maxi = 0;

        for(int i=1; i<n; i++){

          if(prices[i] < buy){                    // If we find a lower price, update the buy value
            buy = prices[i];
          }

          else if(prices[i] - buy > maxi){         // If selling today gives a better profit, update the maxi
            maxi = prices[i] - buy;
          }
        }

        return maxi;
    }
};