/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        map<int,int> topNode;             //HD, and value of node
        queue< pair<Node*, int> > q;        // node, HD
        
        q.push(make_pair(root,0));      // starting q
        
        while (!q.empty()){
            
            pair<Node*, int> temp = q.front();     // temp -> q no pelo
            q.pop();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            // only one valye should present for HD
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = frontNode->data;
            }
            if(frontNode->left){
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        
        for(auto i:topNode){
            
            ans.push_back(i.second);
        }
        return ans;
    }
};