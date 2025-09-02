// LC: 1976 m 

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        // here we don't just have to tell from how many diff ways we get shortest path
        // we also needed to calculate the no of ways each node of path has been reached.

        long long INF = 1e18;           // infinity
        int MOD = 1'000'000'007;        // given

        vector<vector<pair<int,int>>> adjList(n);
        for (auto &r : roads) {
            int u = r[0];
            int v = r[1];
            int wt = r[2];
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }

        vector<long long> dist(n, INF);
        dist[0] = 0;

        // num of ways to reach each node
        vector<long long> ways(n, 0);
        ways[0] = 1;

        //                    dist,  node
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {

          auto it = pq.top(); 
          long long node_dist = it.first;
          int node = it.second;
          pq.pop();

          if(node_dist > dist[node]) continue;             // already reached in better way

          for(auto neigh : adjList[node]){
                
            long long neigh_dist = neigh.second;
            long long neigh_node = neigh.first;

            if(neigh_dist + node_dist < dist[neigh_node]) {          // found shorter path 1st time

              dist[neigh_node] = neigh_dist + node_dist;
              ways[neigh_node] = ways[node];              // neigh_node sudhi pochvana ways is equal to ways to reach node
              pq.push({neigh_dist + node_dist, neigh_node});
            }

            else if(neigh_dist + node_dist == dist[neigh_node]) {                         // already have shorter path

              ways[neigh_node] += ways[node];       // already shortst path, so plus this one
              ways[neigh_node] %= MOD;
            }
          }
        }

        return (int)(ways[n-1] % MOD);
    }
};