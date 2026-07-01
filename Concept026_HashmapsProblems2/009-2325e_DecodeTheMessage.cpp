// LC: 2325 e 

class Solution {
public:
    string decodeMessage(string key, string message) {
        
        int n = message.size();

        string ans = "";
        vector<int> mp(26, -1);
        int cnt = 0;

        for(char ch: key){

          if(ch==' ') continue;

          if(mp[ch-'a'] == -1){
            mp[ch-'a'] = cnt++;
          }
        }

        for(int i=0; i<n; i++){

          if(message[i] == ' '){
            ans += ' ';
            continue;
          }

          int idx = mp[message[i]- 'a'] + 'a';
          ans += (char) idx;
        }

        return ans;
    }
};