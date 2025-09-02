class Solution {
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        
        // Step 1: Build adjacency list
        vector<vector<pair<int,int>>> adj(V);
        vector<int> indegree(V, 0);

        for(auto &e : edges){
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            indegree[v]++;
        }

        // Step 2: Toposort using BFS (Kahn's algorithm)
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> topo;
        while(!q.empty()){
            int node = q.front(); q.pop();
            topo.push_back(node);

            for(auto &p : adj[node]){
                int v = p.first;
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        // if used dfs for topo sort, use that stack for shortest path

        // Step 3: Distance array
        vector<int> dist(V, 1e9);
        dist[0] = 0;

        // Step 4: Relax edges in topo order
        for(int node : topo){
            if(dist[node] != 1e9){  // only if reachable
                for(auto &neigh : adj[node]){

                    int v = neigh.first, wt = neigh.second;
                    dist[v] = min(dist[v], dist[node]+wt);
                }
            }
        }

        // Step 5: Convert unreachable (1e9) → -1
        for(int i = 0; i < V; i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }

        return dist;
    }
};
