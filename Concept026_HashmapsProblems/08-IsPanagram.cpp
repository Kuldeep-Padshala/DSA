// LC:1832 e

class Solution {
public:
    bool checkIfPangram(string sentence) {

      if (unordered_set<char> (sentence.begin(), sentence.end()).size() == 26){
        return true;
      }
      else{
        return false;
      }
    }
};