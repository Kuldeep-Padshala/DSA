// LC: 1207 e 

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        unordered_map<int, int> mp2;

        for(int &num : arr){
          mp[num]++;
        }

        for(auto it=mp.begin(); it!=mp.end(); it++){

          if(mp2.count(it->second)){
            return false;
          }
          mp2[it->second]++;
        }
        return true;
    }
};