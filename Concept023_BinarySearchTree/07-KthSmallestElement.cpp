class Solution {
public:

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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, &ans);
        return ans[k-1];
    }
};