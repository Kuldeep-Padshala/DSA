// LC: 409 e

class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> freq;

        for(char &ch: s){
          freq[ch]++;
        }

        int ans = 0;
        bool hasOdd = false;

        for(auto& [ch, count] : freq){   // also written as     pair<const char, int> &temp : freq

          if(count % 2 == 0){         // jetla even hoi e badhai add karvana
            ans += count;
          }
          else{                       // badhai odds minus one add karvana longest palindrome ma
            ans += count-1;
            hasOdd = true;
          }
        }
        
        return (hasOdd) ? ans+1 : ans;                 // ek odd character add karvano vach ma
    }
};