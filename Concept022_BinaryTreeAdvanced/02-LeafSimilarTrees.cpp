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

void inorder(TreeNode* root, stack<int>* s) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left, s);
   	
    //leaf node
    if(root->left == NULL && root->right == NULL) {
        s->push(root->val);
    }
    
    inorder(root->right, s);

}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<int> s1;
        stack<int> s2;
        inorder(root1, &s1);
        inorder(root2, &s2);

        if(s1 == s2){
          return true;
        }
        return false;
    }
};