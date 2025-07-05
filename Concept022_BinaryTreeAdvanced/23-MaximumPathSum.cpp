/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

int maxSum = INT_MIN;

    int PathSum(TreeNode* node) {
      
        if (node == NULL) return 0;

        int left = max(0, PathSum(node->left));   // negative ne ignore karse
        int right = max(0, PathSum(node->right));


        int sum = node->val + left + right;
        maxSum = max(maxSum, sum);

        // Return the max sum path going downward (only one side allowed)
        return node->val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
      
      PathSum(root);
      return maxSum;
    }
};