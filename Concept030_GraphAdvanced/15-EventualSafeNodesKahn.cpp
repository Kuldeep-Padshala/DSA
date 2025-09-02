// LC: 802 m 

class Solution {
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        // Reversing the graph and then, Using Kahn's Algo

        
        int V = graph.size();
        vector<int> inDegree(V);
        vector<vector<int>> adjList(V);
        
        // storing inDegree of each vertex
        for(int node=0; node<V; node++){
            
          // inDegree[node] += graph[node].size();
          for(auto& adj: graph[node]){
            adjList[adj].push_back(node);    // reversed adjList
            inDegree[node]++;
          }
        }
        
        queue<int>q;
        priority_queue<int, vector<int>, greater<int>> pq;   // we want sorted
        vector<int> ans;
        
        // pushing zero inDegree vertices in queue
        for(int i=0; i<V; i++){
          if(inDegree[i]==0){
            q.push(i);
            // ans.push_back(i);
          }
        }
        
        
        while(!q.empty()){
            
          int node = q.front();
          // int node = q.top();            // for priority queue
          pq.push(node);
          q.pop();
            
          for(auto& neigh: adjList[node]){
            inDegree[neigh]--;
            if(inDegree[neigh] == 0){
              q.push(neigh);
            }
          }
        }
        // sort(ans.begin(), ans.end());
        while(!pq.empty()){
          ans.push_back(pq.top());
          pq.pop();
        }
        return ans;
    }
};
