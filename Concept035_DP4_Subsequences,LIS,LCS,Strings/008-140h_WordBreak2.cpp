// LC: 140h 

class Solution {

  void solve(unordered_set<string>& wordSet, string s, string curr, vector<string>& ans){

    // base case
    if(s.empty()){

      // last ma space add kairi ti e remove
      curr.pop_back();
      // and then ans ma push
      ans.push_back(curr);
      return;
    }


    for(int len=1; len<=s.length(); len++){

      // pelo word 0 to 1, 0 to 2, 0 to lenght 3...  leto javanp
      string prefix = s.substr(0,len);

      if(wordSet.count(prefix)){          // jo e prefix, set ma hoi to curr ma prefix ane space add,
        solve(wordSet, s.substr(len), curr + prefix + " ", ans);  // and e word pachhi ni string mokalvani
      }

    }


  }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        string path = "";
        vector<string> ans;

        solve(wordSet, s, path, ans);
        
        return ans;
    }
};