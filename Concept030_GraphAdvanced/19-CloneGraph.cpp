// LC: 133 m 

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
  unordered_map<Node*, Node*> visited2;
public:
    Node* cloneGraph(Node* node) {
        
        if(node == NULL){
          return NULL;
        }

        // DFS
        // if(visited2.count(node)){
        //   return visited2[node];
        // }

        // Node* copy2 = new Node(node->val);
        // visited2[node] = copy2;

        // for(auto neigh : node->neighbors){
        //     copy2->neighbors.push_back(cloneGraph(neigh));
        // }

        // return copy2;

        // BFS    
        // map original -> cloned
        unordered_map<Node*, Node*> visited;

        // create first clone
        Node* copy = new Node(node->val);
        visited[node] = copy;

        queue<Node*> q;
        q.push(node);

        while(!q.empty()){

            Node* curr = q.front();
            q.pop();

            // check all neighbors
            for(auto neigh : curr->neighbors){

                if(!visited.count(neigh)){   // not cloned yet
                    visited[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }

                // connect in cloned graph
                visited[curr]->neighbors.push_back(visited[neigh]);
            }

        }

        return copy;

    }
};