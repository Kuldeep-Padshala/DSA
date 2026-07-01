// LC: 2418 e 

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        int n = names.size();
        unordered_map<int, string> mp;

        for(int i=0; i<n; i++){
          mp[heights[i]] = names[i];
        }

        sort(heights.rbegin(), heights.rend());   // desc

        for(int i=0; i<n; i++) {
          names[i] = mp[heights[i]];
        }

        return names;
    }
};