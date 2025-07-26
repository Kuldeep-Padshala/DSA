// 530. Minimum Absolute Difference in BST

// Companies
// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
       int result = INT_MAX;
        TreeNode *prev = nullptr;
        
        inorderTraversal(root, &prev, &result);

        return result; 
    }
private:
    void inorderTraversal(TreeNode *root, TreeNode **prev, int *result) {
        if (!root) {
            return;
        }
        
        inorderTraversal(root->left, prev, result);
        
        if (*prev) {
            *result = min(*result, root->val - (*prev)->val);
        }
        *prev = root;
        
        inorderTraversal(root->right, prev, result);
    }
};