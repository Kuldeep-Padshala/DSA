// LC: 1370 e 

class Solution {
public:
    string sortString(string s) {
        
        unordered_map<char, int> freq;

        for(char ch: s){
          freq[ch]++;
        }

        string ans = "";
        int n = s.size();

        while(ans.size() < n){

            // smallest to largest ----
            for(char ch='a'; ch<='z'; ch++){

              if(freq[ch] > 0){

                ans += ch;
                freq[ch]--;
              }
            }

            // largest to smallest ----
            for(char ch='z'; ch>='a'; ch--){

              if(freq[ch] > 0){
                
                ans += ch;
                freq[ch]--;
              }
            }
        }

        return ans;
    }
};