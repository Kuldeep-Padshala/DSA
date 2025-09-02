// LC:269 h Alien Dictionary

class Solution {
    
    vector<int> topoSort(int V, vector<vector<int>>& adjList, vector<int>& present) {
        
        // vector<vector<int>> adjList(V);
        // for(auto &e : edges) {
        //     adjList[e[0]].push_back(e[1]);  // directed edge u->v
        // }
        
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
            if(present[i] && indegree[i]==0){
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
    
  public:
    string findOrder(vector<string> &words) {
        
        // code here
        vector<vector<int>> adjList(26);
        
        vector<int> present(26, 0);

        // mark present chars
        for(auto& w : words){
            for(char c : w){
                present[c-'a'] = 1;
            }
        }

        
        for(int i=0; i<words.size()-1; i++){
            
            string s1 = words[i];
            string s2 = words[i+1];
            
            if(s1.size() > s2.size() && s1.substr(0, s2.size()) == s2){
                return "";
            }
            
            for(int it=0; it<min(s1.size(),s2.size()); it++){
                if(s1[it] != s2[it]){
                    int u = s1[it] - 'a';
                    int v = s2[it] - 'a';
                    adjList[u].push_back(v);
                    break;
                }
            }
        }
        
        vector<int> topo = topoSort(26, adjList, present);
        
        // if cycle -> invalid
        if(topo.size() < count(present.begin(), present.end(), 1)) return "";

        string ans;
        for(auto it: topo){
            // cout<< (char)(it+'a');
            ans.push_back(char(it+'a'));
        }
        return ans;
        
        
    }
};