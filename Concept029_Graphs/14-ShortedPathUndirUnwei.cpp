// Path distances of all nodes to src node 
// GfG

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        
        // code here
        
        int V = adj.size();
        
        // distance array, initialize with -1 (unreachable)
        vector<int> dist(V, -1);
        dist[src] = 0; // distance to source is 0

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto neigh : adj[node]) {
                if (dist[neigh] == -1) { // not visited yet
                    dist[neigh] = dist[node] + 1;
                    q.push(neigh);
                }
            }
        }
        return dist;    
        
    }
};


// Actual path from all nodes to source

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<vector<int>> shortestPaths(vector<vector<int>>& adj, int src) {
        
        // code here
        int V = adj.size();

        vector<bool> visited(V);
        vector<int> parent(V, -1);
        
        queue<int> q;
        q.push(src);
        visited[src] = true;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto neigh: adj[node]){
                if(!visited[neigh]){
                    visited[neigh] = true;
                    parent[neigh] = node;
                    q.push(neigh);
                }
            }
        } // parent vector ready

        
        vector<vector<int>> ans;
        
        for(int i=0; i<V; i++){
            
            if(!visited[i]){
                ans[i] = {-1};  // unreachable
                continue;
            }

            vector<int> path;
            int curr=i;

            while(curr != -1){
                path.push_back(curr);
                curr = parent[curr];
            }

            reverse(path.begin(), path.end());

            ans[i] = path;
        }

        return ans;       
    }
};