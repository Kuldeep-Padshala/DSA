// LC: 743 m 

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // not DAG, so no topo sort

        // Dijkstra
        vector<vector<pair<int,int>>> adj(n+1);

        for(auto &e : times){
          //    u               v      w
          adj[e[0]].push_back({e[1], e[2]});
        }
        

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        // min-heap {time, node}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto [d, node] = pq.top(); pq.pop();
            if(d > dist[node]) continue;

            for(auto& neigh : adj[node]){

                int v = neigh.first;
                int wt = neigh.second;
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = *max_element(dist.begin()+1, dist.end());
        return ans == 1e9 ? -1 : ans;
    }
};