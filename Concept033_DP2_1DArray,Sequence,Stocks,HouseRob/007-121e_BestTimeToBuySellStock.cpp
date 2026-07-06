// LC: 121 e 

// dp on stocks

class Solution {
public:

    int maxProfit(vector<int>& prices) {
  
        if(prices.size() == 0) {
            return 0;
        }
        int minValue= INT_MAX;
        int maxPro = 0;

        for(int i=0; i<prices.size(); i++) {

            if(prices[i]<minValue) {
              minValue = prices[i];
            }
            if((prices[i]-minValue)>maxPro) {
              maxPro = prices[i]-minValue;
            }
        }
        return maxPro;
    }
};