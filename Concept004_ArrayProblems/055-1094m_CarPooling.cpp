// LC: 1094 m 

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        vector<int> diff(1001, 0); // max location = 1000

        for(auto &t : trips){
          diff[t[1]] += t[0]; // pickup
          diff[t[2]] -= t[0]; // drop
        }

        int curr = 0;
        for(int x : diff){
          curr += x;
          if (curr > capacity) return false;
        }

        return true;
    }
};