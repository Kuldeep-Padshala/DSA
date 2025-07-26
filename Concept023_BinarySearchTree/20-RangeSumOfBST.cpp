// 938. Range Sum of BST

// Given the root node of a binary search tree and two integers low and high, 
// return the sum of values of all nodes with a value in the inclusive range [low, high].

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL){
          return 0;
        }

        return (low <= root->val && high>=root->val) * root->val +
                ( (low <= root->val) ? rangeSumBST(root->left, low, high) : 0) +
                ( (high >= root->val) ? rangeSumBST(root->right, low, high) : 0);
    }
};