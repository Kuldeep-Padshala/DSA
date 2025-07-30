// LC:1207 e

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
        unordered_map<int, int> freq;
        unordered_map<int, int> cnt_freq;

        for(int &num : arr){      // badha elements ni frequency store
          freq[num]++;
        }

        // unordered_map <int, int> :: iterator it = freq.begin()
        for(auto it=freq.begin(); it!=freq.end(); it++){

          if(cnt_freq.count(it->second)){        // jo count of freq already (it->second) is already present
            return false;
          }                                      // freq na count ne store kairo
          cnt_freq[it->second]++;
          
        }
        return true;
    }
};