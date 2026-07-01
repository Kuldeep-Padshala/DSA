// LC: 2423 e 

class Solution {
public:
    bool equalFrequency(string word) {

        vector<int> mp(26);

        for(char ch: word){
          mp[ch-'a']++;
        }

        // For each letter (0-25):
        // Skip if frequency is 0
        // Decrease frequency by 1
        // Collect all non-zero frequencies in set
        // If set has size 1 → all equal → return true
        // Restore frequency

        
        for(int i=0; i<26; i++){

          if(!mp[i]) continue;
            
          mp[i]--;
          unordered_set<int> st;
          
          for(int freq: mp){
            if(freq) st.insert(freq);
          }
            
          if(st.size() == 1) return true;
            
          mp[i]++;
        }
        
        return false;
        
        // unordered_map<char, int> mp;

        // for(char ch: word){
        //   mp[ch]++;
        // }

        // vector<int> flag(2, -1), count(2, 0);

        // for(auto it = mp.begin(); it != mp.end(); it++){

        //   int curr = it->second;

        //   if(flag[0] == -1){
        //     flag[0] = curr;
        //     count[0]++;
        //   }
        //   else if(flag[1] == -1 && curr != flag[0]){
        //     flag[1] = curr;
        //     count[1]++;
        //     // if(abs(flag[0]-flag[1]) != 1) return false;
        //   }
        //   else{
        //     if(curr == flag[0]) count[0]++;
        //     else if(curr == flag[1]) count[1]++;
        //     else return false;
        //   }
        // }

        // // only one frequency group
        // if(flag[1] == -1){
          
        //   if(flag[0] == 1 || count[0] == 1){
        //     return true;
        //   }
        //   return false;
        // }

        // if((flag[0] == 1 && count[0] == 1) || (flag[1] == 1 && count[1] == 1)){
        //   return true;
        // }

        // if(abs(flag[0] - flag[1]) == 1){
          
        //   if((flag[0] > flag[1] && count[0] == 1) ||(flag[1] > flag[0] && count[1] == 1)){
        //     return true;
        //   }
        // }
        // return false;
    }
};