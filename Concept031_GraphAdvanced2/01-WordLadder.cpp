// LC: 127 h 

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());   // badhai words no set

        // invalid (base case)
        if(!wordSet.count(endWord)){
          return 0;
        }

        // create q and pelo word push
        //          word   dist
        queue<pair<string,int>> q;   // jo queue ma dist nai lai to ek for loop vadhare chalavu padse size count mate
        q.push({beginWord, 1});
        wordSet.erase(beginWord);
        
        while(!q.empty()){

            string curr_word = q.front().first;   //   "hit"
            int steps = q.front().second;
            q.pop();                        // empty
            if(curr_word == endWord){
              return steps;
            }

            for(int i = 0; i<curr_word.size(); i++){       // every single char of "hit"   'h' 'i' 't'

              char original = curr_word[i];     // just to keep record

              for(char ch = 'a'; ch<='z'; ch++){           // har ek char ni jagya e ch put

                if(original == ch) continue;  // skip if same as original

                curr_word[i] = ch;

                // if(curr_word == endWord){          // jo endWord hoi to return
                //   return steps+1;
                // }

                if(wordSet.count(curr_word)){
                  q.push({curr_word, steps+1});                            // "hot"
                  wordSet.erase(curr_word);  // Mark visited
                }

              }
              curr_word[i] = original;                // "hit"
            }

        }    // while over

        return 0;
    }
};