// LC: 1584 m 

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int n = points.size();

        // {wt, {node, parent}}
        priority_queue<pair<int, pair<int,int>>, 
                       vector<pair<int, pair<int,int>>>, 
                       greater<pair<int, pair<int,int>>>> pq;

        vector<bool> visited(n, false);
        int sum = 0;

        // start from node 0
        pq.push({0, {0, -1}});

        while (!pq.empty()) {
          auto it = pq.top(); pq.pop();
          int wt = it.first;
          int node = it.second.first;
          int parent = it.second.second;

          if (visited[node]) continue;

          // take this edge into MST
          visited[node] = true;
          sum += wt;

          // now push all edges from this node to others
          for(int neigh_node=0; neigh_node<n; neigh_node++){
            
            if(!visited[neigh_node]){
              
              int neigh_wt = abs(points[node][0] - points[neigh_node][0]) + 
                             abs(points[node][1] - points[neigh_node][1]);
              pq.push({neigh_wt, {neigh_node, node}});
            }
          }
        }
        return sum;
    }
};