// LC: 1748 e 

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        
        unordered_map<int, int> mp;

        for(int num: nums){
          mp[num]++;
        }

        int sum = 0;
        
        for(auto element : mp){
          if(element.second == 1){
            sum += element.first;
          }
        }

        return sum;
    }
};