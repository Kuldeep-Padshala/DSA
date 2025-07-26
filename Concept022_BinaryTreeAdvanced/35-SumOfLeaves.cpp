// 404. Sum of Left Leaves

// Given the root of a binary tree, return the sum of all left leaves.
// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
          return 0;
        }
        // if(root->left == NULL){
        //   return sumOfLeftLeaves(root->right);
        // }
        int ans = 0;
        if(root->left!=NULL && root->left->left == NULL && root->left->right == NULL){
          ans += root->left->val;
        }
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right)+ans;
    }
};