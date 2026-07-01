// LC: 299 m 

class Solution {
public:
    string getHint(string secret, string guess) {
        
        int n = secret.size();
        unordered_map<char, int> mp;
        int bulls = 0;
        int cows = 0;

        for(int i=0; i<n; i++){
          if(secret[i] == guess[i]){
            bulls++;
          }
          if(mp.find(secret[i]) == mp.end()){
            mp[secret[i]] = 1;
          }
          else{
            mp[secret[i]]++;
          }
        }

        for(char ch: guess){
          if(mp[ch] >= 1){
            cows+=1;
            mp[ch]--;
          }
        }

        cows = cows - bulls;

        return to_string(bulls) + "A" + to_string(cows) + "B";

    }
};