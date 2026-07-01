// LC: 451 m 

class Solution {
public:
    string frequencySort(string s) {
        
        unordered_map<char, int> freq;
        vector<char> temp;

        for(char ch: s){
          freq[ch]++;
          temp.push_back(ch);
        }

        sort(temp.begin(), temp.end(), [&](char a, char b){

            if(freq[a] == freq[b]){ return a < b;  }
            return freq[a] > freq[b];
        });

        string ans = "";

        for(char ch: temp){
          ans += ch;
        }

        return ans;

        // vector<int>freq(128,0);
        // for(char ch: s){
        //   freq[ch]++;
        // }

        // vector<pair<char,int>> v;
        // for(int i=0; i<128; i++){
          
        //   if(freq[i]>0){
        //     v.push_back({char(i),freq[i]});
        //   }
        // }
        // sort(v.begin(),v.end(),[](auto &a,auto &b){
        //    return a.second>b.second;
        // });

        // string ans="";
        // for(auto &p:v){
        //   ans += string(p.second,p.first);
        // }

        // return ans;
    }
};