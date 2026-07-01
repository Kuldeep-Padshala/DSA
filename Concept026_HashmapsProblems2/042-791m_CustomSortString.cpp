// LC: 791 m 

class Solution {
public:
    string customSortString(string order, string s) {
        
        int n = order.size();
        unordered_map<char, int> mp;

        for(int i=0; i<n; i++){
          mp[order[i]] = i;
        }

        sort(s.begin(), s.end(), [&](char a, char b){
          return mp[a] < mp[b];
        });

        return s;
    }
};