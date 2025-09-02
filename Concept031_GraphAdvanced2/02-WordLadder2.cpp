// LC: 126 h 

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        // not accetable in leetcode
        unordered_set<string> wordSet(wordList.begin(), wordList.end());   // badhai words no set

        // invalid (base case)
        if(!wordSet.count(endWord)){
          return {};
        }

        queue<vector<string>> q;
        q.push({beginWord});

        vector<vector<string>> ans;
        bool found = false;
        // int level=0;   memmory limit exceeded

        while(!q.empty()){

          int size = q.size();
          unordered_set<string> usedThisLevel;   // words of this BFS level

          for(int it=0; it<size; it++){
            
            vector<string> vec = q.front();
            // string curr_word = vec[level];
            string curr_word = vec.back();

            q.pop();

            if(vec.back() == endWord){
              ans.push_back(vec);
              found = true;
            }

            for(int i = 0; i<curr_word.size(); i++){

              char original = curr_word[i];

              for(char ch = 'a'; ch<='z'; ch++){

                if(original == ch) continue;

                curr_word[i] = ch;

                if(wordSet.count(curr_word)){
                  
                  vector<string> newPath = vec;
                  newPath.push_back(curr_word);
                  q.push(newPath);

                  usedThisLevel.insert(curr_word);
                }

              }
              curr_word[i] = original;
            }
          }
          if(found) break;   // stop BFS once shortest paths found

          // after finishing one level, erase all words used in this level
          for(auto &w : usedThisLevel){
            wordSet.erase(w);
          }
          usedThisLevel.clear();
          // level++;
        }

        return ans;
    }
};