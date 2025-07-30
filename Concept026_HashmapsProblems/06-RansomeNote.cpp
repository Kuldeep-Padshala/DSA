// LC: 383 e

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        vector<int> freq(26);

        for(char ch : magazine){
          freq[ch - 'a']++;
        }

        for(char ch : ransomNote){

          if(freq[ch - 'a']==0){    // if char in ransom note present in magazine
            return false;
          }
          freq[ch - 'a']--;
        }
        return true;
    }
};