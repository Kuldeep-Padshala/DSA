// 563. Binary Tree Tilt

// Given the root of a binary tree, return the sum of every tree node's tilt.

// The tilt of a tree node is the absolute difference between the sum of all left subtree node values and all right subtree node values. 
// If a node does not have a left child, then the sum of the left subtree node values is treated as 0. 
// The rule is similar if the node does not have a right child

class Solution {
public:
    int findTilt(TreeNode* root) {

        int tilt = 0;
        postOrderTraverse(root, &tilt);
        return tilt;
    }

private:
    int postOrderTraverse(TreeNode* root, int *tilt) {
        if (!root) {
            return 0;
        }
        auto left = postOrderTraverse(root->left, tilt);
        auto right = postOrderTraverse(root->right, tilt);
        *tilt += abs(left - right);
        return left + right + root->val;
    }
};