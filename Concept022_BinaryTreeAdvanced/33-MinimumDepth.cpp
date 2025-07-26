// 111. Minimum Depth of Binary Tree

// premium lock icon
// Companies
// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

// Note: A leaf is a node with no children.


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL){
          return 0;
        }
        if(root->left!=NULL && root->right!=NULL){
          return min(minDepth(root->left), minDepth(root->right))+1;
        }
        else{
          return max(minDepth(root->left), minDepth(root->right))+1;
        }
    }
};