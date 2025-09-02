// LC: 433 m 

class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        
        unordered_set<string> dict(bank.begin(), bank.end());

        if(!dict.count(endGene)){   // endGene must be in bank
          return -1;
        }
        
        queue<pair<string,int>> q;
        unordered_set<string> visited;

        q.push({startGene, 0});
        visited.insert(startGene);

        string genes = "ACGT";

        while(!q.empty()) {
          
          auto [curr, steps] = q.front();
          q.pop();

          if(curr==endGene){
            return steps;
          }

          for(int i = 0; i<curr.size(); i++){
            char actual = curr[i];
            
            for(char g : genes) {
              
              if(g == actual){        // skip same letter
                continue;
              }

              string next = curr;
              next[i] = g;

              if(dict.count(next) && !visited.count(next)){
                visited.insert(next);
                q.push({next, steps + 1});
              }
            }
          }
        }
        return -1;
    }
};