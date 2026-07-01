// LC: 2363 e 

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        
        int n = items1.size();
        map<int, int> mp;

        for(auto& item: items1){
          mp[item[0]] += item[1];
        }

        for(auto& item: items2){
          mp[item[0]] += item[1];
        }

        vector<vector<int>> ret;

        for(auto it = mp.begin(); it != mp.end(); it++){
          ret.push_back({it->first, it->second});
        }

        return ret;
        
    }
};