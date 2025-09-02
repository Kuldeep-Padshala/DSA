// LC: 802 m 

class Solution {

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& path_visited, vector<int>& safe) {
        
        visited[node] = 1;
        path_visited[node] = 1;
        
        for(int neigh : graph[node]){
          
          if(!visited[neigh]){
            if(dfs(neigh, graph, visited, path_visited, safe)){
              return true; // cycle found
            }
          }
          // repeated in same path, cycle
          else if(path_visited[neigh]){
            return true;
          }
        }
        
        path_visited[node] = 0;   // backtrack
        safe[node] = 1;           // no cycle downstream → safe node
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();
        vector<int> visited(n, 0);
        vector<int> path_visited(n, 0);
        vector<int> safe(n, 0);  // 1 = safe node
        
        for(int i = 0; i < n; i++){
          if(!visited[i]){
            dfs(i, graph, visited, path_visited, safe);
          }
        }
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
          if(safe[i]){
            ans.push_back(i);
          }
        }
        return ans;
    }
};
