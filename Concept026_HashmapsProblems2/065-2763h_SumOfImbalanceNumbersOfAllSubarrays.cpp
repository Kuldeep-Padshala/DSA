// LC: 2763 h 

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++){

          unordered_set<int> s;
          int curr = 0;

          for(int j=i; j<n; j++){
            
            int num = nums[j];
            if(s.count(num)){
              // do nothing
            } 
            else if(s.count(num-1) && s.count(num+1)){       // not satisfying sarr[i+1] - sarr[i] > 1 
              curr--;
            } 
            else if (!s.count(num-1) && !s.count(num+1) && !s.empty()) {     // unique
              curr++;
            }
            s.insert(num);
            ans += curr;
          }
        }
        return ans;
    }
};