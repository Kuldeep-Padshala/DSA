// 226. Invert Binary Tree

// premium lock icon
// Companies
// Given the root of a binary tree, invert the tree, and return its root.

class Solution {
public:


    TreeNode* invertTree(TreeNode* root) {

      if (root != NULL) {
            swap(root->left, root->right);
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};