void inorder(TreeNode* root, vector<int>* s) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, s);
   	
    //leaf node
    s->push_back(root->val);
    
    inorder(root->right, s);
}