class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if(root == NULL){
          return NULL;
        }
        if(root->val == val){
          return root;
        }
        TreeNode* node;

        if(val < root->val ){
          root = searchBST(root->left, val);
        }
        else{
          root = searchBST(root->right, val);
        }
        return root;
    }
};