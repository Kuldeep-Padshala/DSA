class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
           
        vector<vector<int>> adjList(V);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1]
            adjList[u].push_back(v);  // directed edge u->v
        }
        
        // code here
        
        vector<int> indegree(V);
        
        // storing indegree of each vertex
        for(int node=0; node<V; node++){
            
            for(auto& adj: adjList[node]){
                indegree[adj]++;
            }
        }
        
        queue<int>q;
        vector<int> ans;
        
        // pushing zero indegree vertices in queue
        for(int i=0; i<V; i++){
            if(indegree[i]==0){
                q.push(i);
                // ans.push_back(i);
            }
        }
        
        
        while(!q.empty()){
            
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto& neigh: adjList[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 0){
                    q.push(neigh);
                    // ans.push_back(neigh);
                }
            }
        }
        return ans; 
    }
};