/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Should return  right view of tree
class Solution {
  public:
    // Function to return list containing elements of right view of binary tree.
    void getRightView(Node* root, vector<int>* ans, int level) {
    //base case
    if(root == NULL)
        return ;
       
    //we entered into a new level    
    if(level == ans->size())
        ans->push_back(root->data);
        
    getRightView(root->right, ans, level+1);
    getRightView(root->left, ans, level+1);
}

    vector<int> rightView(Node *root) {
        // Your Code here
        vector<int> ans;
        
        getRightView(root, &ans,0);
        
        return ans;
    }
};