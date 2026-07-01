// LC: 1807 

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        
        int n = s.size();
        unordered_map<string, string> mp;

        for(auto& pair: knowledge){
          mp[pair[0]] = pair[1];
        }

        string ans;

        for(int i=0; i<n; i++){

          if(s[i] != '('){
            ans += s[i];
            continue;
          }
          string key = "";
          i++;

          while(s[i] != ')'){
            key+=s[i];
            i++;
          }
          // i++;
          if(mp.find(key) == mp.end()) ans += '?';
          else ans += mp[key];

        }

        return ans;

    }
};