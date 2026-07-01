// LC: 1410 m 

class Solution {
public:
    string entityParser(string text) {
        
        int n = text.size();
        unordered_map<string, string> mp;

        mp["&quot;"] = "\"";
        mp["&apos;"] = "'";
        mp["&amp;"] = "&";
        mp["&gt;"] = ">";
        mp["&lt;"] = "<";
        mp["&frasl;"] = "/";

        string ans;

        int idx=0;

        while(idx<n){
            
          bool found = false;

          // &frasl; to &gt;
          for(int len=4; len<=7 && idx+len<=n; len++){
              
              string curr = text.substr(idx, len);
              if(mp.count(curr)) {
                ans += mp[curr];
                idx += len;
                found = true;
                break;
              }
          }

          if(!found) {
            ans += text[idx++];
            // idx++;
          }
        }

        return ans;
    }
};