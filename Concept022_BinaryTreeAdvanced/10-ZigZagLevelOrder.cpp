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

void levelOrderTraversal(TreeNode* root, vector<vector<int>>* ans) {


    if (root == NULL) {
        cout << "Tree is empty." << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; ++i) {
            TreeNode* temp = q.front();
            q.pop();


            int index = leftToRight ? i : (size - i - 1);
            level[index] = temp->val;

            if (temp->left){
              q.push(temp->left);
            }
            if (temp->right){
              q.push(temp->right);
            }
        }

        ans->push_back(level);
        leftToRight = !leftToRight;
    }
}

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        levelOrderTraversal(root, &ans);

        return ans;
    }
};