// Dijkstra's Algorithm using Set
// Dijkstra's algorithm is a greedy algorithm that finds the shortest path from a source node to all other nodes in a 
// Directed/Undirected graph with non-negative weights.

// Find the shortest weight path between the vertex 1 and the vertex n,
// TC: O((V+E) log V)  SC: O(V) for dist, parent, set

// Using Set
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        // using set, if same node appears again with shorter distance,
        // we can find it and remove it (log n) but save extra iteration
        
        // using pq, we have to iterate the longer path too
        // which is better, depends on the size, degree of that node
        
        
        //                node weight
        vector<vector<pair<int,int>>> adjList(n+1);
        for(auto &e : edges){
            int u = e[0], v = e[1], w = e[2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});  // undirected
        }
        
        int src = 1, target=n;
        //      dist node
        set<pair<int,int>> st;
        vector<int> dist(n+1, 1e9);
        vector<int> parent(n+1);
        
        for(int i=1; i<=n; i++) parent[i] = i;  // each node is its own parent initially
        
        st.insert({0, src});
        dist[src] = 0;
        
        while(!st.empty()){
            
            //               smallest dist
            auto set_top = *(st.begin());
            
            int node_dist = set_top.first;
            int node = set_top.second;
            st.erase(set_top);
            
            for(auto& neigh: adjList[node]){
                
                int neigh_node = neigh.first;      // v
                int neigh_dist = neigh.second;     // w
                
                if(node_dist + neigh_dist < dist[neigh_node]){
                    
                    if(dist[neigh_node] != 1e9){   // if already have greater dist pair, remove it
                        st.erase({dist[neigh_node], neigh_node});
                    }
                    
                    // auto record = st.find({dist[neigh_node], neigh_node});
                    // if (record != st.end()) st.erase(record);
                    
                    // update dist
                    dist[neigh_node] = node_dist + neigh_dist;
                    st.insert({dist[neigh_node], neigh_node});
                    parent[neigh_node] = node;
                }
            }
        }
        // return dist;
        
        // Step 3: Build path
        if(dist[target] == 1e9) return {-1};  // unreachable
        
        // Output format: {totalWeight, path...}
        
        vector<int> ans;
        int node = target;
        
        while(parent[node] != node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(src);
        ans.push_back(dist[target]);
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};