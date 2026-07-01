// LC: 3137 m

class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        
        unordered_map<string, int> mp;

        int i=0;
        string temp = "";
        for(char ch: word){

          temp += ch;
          i++;
          if(i==k){
            mp[temp]++;
            i=0;
            temp = "";
          }
        }

        int maxi = 0;
        for(auto it=mp.begin(); it!=mp.end(); it++){
          maxi = max(maxi, it->second);
          cout << "word: " << it->first << " -> " << it->second << endl;
        }

        return (word.length()/k - maxi);

    }
};