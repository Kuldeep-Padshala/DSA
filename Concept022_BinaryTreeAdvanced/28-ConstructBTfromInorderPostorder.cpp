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

int findPos(vector<int>& inorder, int elem, int inStart, int inEnd) {
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == elem)
            return i;
    }
    return -1;
}

TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& index, int inStart, int inEnd, int n) {
    if (index < 0 || inStart > inEnd)
        return NULL;

    int element = postorder[index--]; // Root from postorder
    TreeNode* root = new TreeNode(element);

    if (inStart == inEnd)
        return root;

    int pos = findPos(inorder, element, inStart, inEnd);

    // Important: Build right subtree first, then left
    root->right = solve(inorder, postorder, index, pos + 1, inEnd, n);
    root->left = solve(inorder, postorder, index, inStart, pos - 1, n);

    return root;
}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postIndex = postorder.size() - 1;
        int n = inorder.size();
        return solve(inorder, postorder, postIndex, 0, n - 1, n);
    }
};