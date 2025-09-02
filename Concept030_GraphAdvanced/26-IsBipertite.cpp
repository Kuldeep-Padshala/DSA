// LC: 785 m 

class Solution {
public:

    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> color(graph.size(), -1);

        for(int start=0; start<graph.size(); start++){
          
          if(color[start] != -1) continue;

          queue<int> q;
          q.push(start);
          color[start] = 0;

          while(!q.empty()){
            
            int node = q.front();
            q.pop();

            for(int neigh: graph[node]){

              if(color[neigh] == -1){

                color[neigh] = !color[node];
                q.push(neigh);
              }

              else if(color[neigh] == color[node]){
                return false;
              }
            }
          }

        }
        return true;
    }
};