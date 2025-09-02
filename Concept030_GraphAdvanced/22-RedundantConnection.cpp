// LC: 624 m 

class Solution {

  bool bfs(int u, int v, vector<vector<int>>& adjList, vector<bool>& visited){

        queue<int> q;
        q.push(u);
        visited[u] = true;    // 1-true, 2-true , 3-true, 

        while (!q.empty()) {
          
          int curr = q.front();
          q.pop();

          if(curr == v){              // path exists
            return true;
          }

          for(int nei : adjList[curr]){
            if(!visited[nei]){
              visited[nei] = true;
              q.push(nei);
            }
          }
          // [[1,2],[2,3],[3,4],[1,4],[1,5]], pela 3 skip bfs
          // Check if 1 → 4 is connected → run BFS
          // Queue = [1], visited = {1}
          // Pop 1: neighbors = [2] → enqueue 2, visited = {1,2}
          // Pop 2: neighbors = [1,3] → 1 visited, enqueue 3, visited = {1,2,3}
          // Pop 3: neighbors = [2,4] → 2 visited, enqueue 4, visited = {1,2,3,4}
          // Pop 4: reached target 4 → cycle detected

        }
        return false;
   }

    // bool dfs(int curr, int target, vector<vector<int>>& adjList, vector<bool>& visited){

    //       if (curr == target){
    //         return true;
    //       }
    //       visited[curr] = true;

    //       for(int nei : adjList[curr]){
    //         if(!visited[nei]){
    //           if(dfs(nei, target, adjList, visited)){
    //             return true;
    //           }
    //         }
    //       }
    //       return false;
    // }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<vector<int>> adjList(n + 1);

        for(auto& e : edges){
          
          int u = e[0], v = e[1];
          vector<bool> visited(n + 1, false);

          if(!adjList[u].empty() && !adjList[v].empty()){
            
            if(bfs(u, v, adjList, visited)){
              return e;  // redundant edge
            }
            // if(dfs(u, v, adjList, visited)){
            //   return e;  // redundant edge
            // }
          }

          adjList[u].push_back(v);   // 1 -> 2, 
          adjList[v].push_back(u);   // 2 -> 1
        }
        return {};
    }
};