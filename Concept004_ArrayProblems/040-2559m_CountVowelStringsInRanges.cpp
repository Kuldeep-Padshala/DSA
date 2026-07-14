// LC: 2559 m 

class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        // prefix sum

        int n = words.size();
        vector<int> prefixSum;
        prefixSum.push_back(0);

        for(string word: words){

          char s = word[0];
          char e = word[word.length()-1];

          if((s=='a' || s=='e' || s=='i' || s=='o' || s=='u') && (e=='a'||e=='i'||e=='o'||e=='e'||e=='u')){
            prefixSum.push_back(prefixSum.back() + 1);
          }
          else{
            prefixSum.push_back(prefixSum.back());
          }
        }

        int m = queries.size();
        vector<int> ans;
        
        for(auto &query: queries){
          int s=query[0], e=query[1];
          ans.push_back(prefixSum[e+1]-prefixSum[s]);
        }
        return ans;

    }
};