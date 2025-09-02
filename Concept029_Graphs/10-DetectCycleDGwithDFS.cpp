class Solution {
    
  public:
  bool dfs(int i, vector<vector<int>> &edges, vector<int>& visited, vector<int>& path_visited){
        
        visited[i] = 1;
        path_visited[i] = 1;
        
        for(auto& adj : edges[i]){
            
            if(adj<0 || adj>=V) return false;
            
            if(!visited[adj]){
                if(dfs(adj, edges, visited, path_visited)){
                    return true;
                }
            }
            // repeated in same path
            else if(path_visited[adj]){
                return true;
            }
        }
        
        path_visited[i] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> visited(V, 0);
        vector<int> path_visited(V, 0);
        
        // vector<pair<bool,bool>> visited;
        
        for(int i=0; i<V; i++){
            
            if(!visited[i]){
                if(dfs(i, edges, visited, path_visited)){
                    return true;
                }
            }
        }
        return false;
    }
};