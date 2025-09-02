// LC: 787 m 

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // Bellman-Ford DP or Dijkstra

        if(src == dst) return 0;

        vector<vector<pair<int,int>>> adjList(n);
        for(auto &f : flights) {
          //         u               v    pri
          adjList[f[0]].push_back({f[1],f[2]});
        }

        // Min-heap:     {price, node, stops}
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push({0, src, 0});

        // vector<int> prices(n, 1e9);        // minimum of all the max efforts
        // prices[src] = 0;

        // prices[node][stops] means price to reach a this node within this much stops 
        vector<vector<int>> prices(n, vector<int>(k+2, 1e9));
        prices[src][0] = 0;

        while(!pq.empty()){
          auto [price, node, stops] = pq.top();
          pq.pop();

          // pq no top node = dst, it is with the lowest price
          if(node == dst) return price;

          // if stopst is k+1 and its not dst, its wrong route
          if(stops == k+1) continue;     

          for(auto& neigh: adjList[node]){

            int neigh_node = neigh.first;
            int neigh_price = neigh.second;

            if(price + neigh_price < prices[neigh_node][stops+1]){
              prices[neigh_node][stops+1] = price + neigh_price;
              pq.push({prices[neigh_node][stops+1], neigh_node, stops+1});
            }
          }

        }
        return -1;       
    }
};