// LC: 547 m

// SC: O(n)+O(n)
// TC: O(n) + O(v+2e)

class Solution {

  void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited){

    visited[node] = true;

    for(int it : adjList[node]){
      if(!visited[it]){
        dfs(it, adjList, visited);
      }
    }

  }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int V = isConnected.size();
        vector<vector<int>> adjList(V);

        for(int i=0; i<V; i++){
          for(int j=0; j<V; j++){
            if(isConnected[i][j]==1 && i!=j){
              adjList[i].push_back(j);
              adjList[j].push_back(i);
            }
          }
        }

        vector<bool> visited(V, false);
        int ans=0;

        for(int i=0; i<V; i++){
          if (!visited[i]) {             // aa node na connected jetla hase e visited mark thai jase with dfs
            dfs(i, adjList, visited);
              ans++;
          }
        }
        return ans;
    }
};