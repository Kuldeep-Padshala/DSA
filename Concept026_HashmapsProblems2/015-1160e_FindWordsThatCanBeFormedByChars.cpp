// LC: 1160 e 

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        int ans = 0;

        for(string& word : words){

            string tempChars = chars;
            bool valid = true;

            for(char ch : word){

              size_t pos = tempChars.find(ch);

              if(pos != string::npos) {
                tempChars.erase(pos, 1);
              } 
              else{
                valid = false;
                break;
              }
            }

            if(valid){
              ans += word.size();
            }
        }

        return ans;
    }
};