// LC: 752 m 

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        

        // only ond digit changes, same cost, so only bfs + queue ,  No - Dijkstra
        unordered_set<string> dead(deadends.begin(), deadends.end());

        if(dead.count("0000")){
          return -1;
        }
        if(target == "0000"){
          return 0;
        }

        //          code  steps
        queue<pair<string, int>> q;
        q.push({"0000", 0});

        unordered_set<string> visited;
        visited.insert("0000");

        while(!q.empty()){
          auto [code, steps] = q.front();
          q.pop();

          for(int i=0; i<4; i++){

            string curr = code;
            
            // move forward
            code[i] = (code[i]+1 - '0') % 10 + '0';

            if(code == target){
              return steps + 1;
            }

            if(!dead.count(code) && !visited.count(code)){
              visited.insert(code);
              q.push({code, steps+1 });
            }

            code = curr;

            // move backward
            code[i] = (code[i] - '0' - 1 + 10) % 10 + '0';

            if(code == target){
              return steps + 1;
            }
            if(!dead.count(code) && !visited.count(code)){
              visited.insert(code);
              q.push({code, steps + 1});
            }

            code = curr;
          }
        }
        return -1;
    }
};