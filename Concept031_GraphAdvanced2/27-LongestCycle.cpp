class Solution {

  void dfs1(int u, vector<int> adj[], vector<int>& vis, stack<int>& st) {
        
      vis[u] = 1;
      for(int v : adj[u]){
        if(!vis[v]){
          dfs1(v, adj, vis, st);
        }
      }
      st.push(u);
  }
    
  void dfs2(int u, vector<int> adjT[], vector<int>& vis, vector<int>& component) {
      
      vis[u] = 1;
      component.push_back(u);

      for(int v : adjT[u]) {
        if(!vis[v]){
          dfs2(v, adjT, vis, component);
        }
      }
  }

public:
    int longestCycle(vector<int>& edges) {
        
        // Aproach 1: TimeStamp + DFS
        // Aproach 2: SCC Kosaraju's Algo

        // Aproach 2

        // Each node has only one out edge at max
        int n = edges.size();
        vector<int> adj[n], adjT[n];
        
        // made both Adj and Transpose Adj
        for (int u = 0; u < n; u++) {
          int v = edges[u];
          if(v != -1){
            adj[u].push_back(v);
            adjT[v].push_back(u);
          }
        }
        
        // Step 1: DFS order
        vector<int> vis(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++) {
          if(!vis[i]){
            dfs1(i, adj, vis, st);
          }
        }
        
        // Step 2:Rev DFS
        fill(vis.begin(), vis.end(), 0);
        int ans = -1;
        while(!st.empty()) {
          
          int u = st.top(); 
          st.pop();

          if(!vis[u]){
            vector<int> comp;
            dfs2(u, adjT, vis, comp);
                
            // check if component has a cycle
            if (comp.size() != 1) {
              ans = max(ans, (int)comp.size());
            } 
            else{
              int node = comp[0];
              if(edges[node] == node){           // self-loop
                ans = max(ans, 1);
              }
            }
          }
        }
        
        return ans;
    }
};