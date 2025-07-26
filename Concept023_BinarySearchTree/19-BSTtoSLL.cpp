// 897. Increasing Order Search Tree

// Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the 
// root of the tree, and every node has no left child and only one right child.

class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
      return BSTtoList(root, NULL);
    }

private:
    TreeNode* BSTtoList(TreeNode* root, TreeNode* tail) {
        
        if(root==NULL) {
            return tail;
        }

        TreeNode* node = BSTtoList(root->left, root);
        
        root->left = NULL;
        root->right = BSTtoList(root->right, tail);
        return node;
    }

};