//                                              INT_MIN   INT_MAX
Node* preToBST(vector<int>& preorder, int& idx, int low, int high) {

    if(i == preorder.size() || preorder[i] > high || preorder[i] < low){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    idx++;

    root->left = preToBST(preorder, idx, low, root->val);

    root->right = preToBST(preorder, idx, root->val, high);
    
    return root;
}