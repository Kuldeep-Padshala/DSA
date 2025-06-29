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

void levelOrderTraversal(TreeNode* root, vector<int>* v,vector<vector<int>>* ans) {

    if(root == NULL){
        cout << "Tree is empty."<<endl;
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL);
    v->push_back(root->val);
    ans -> push_back(*v);
    v -> clear();

    while(!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();                        //removes front

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
                ans -> push_back(*v);
                v -> clear();
            }  
        }
        else{
            if(temp -> left != NULL) {
                q.push(temp ->left);
                v->push_back(temp -> left -> val);
            }

            if(temp ->right != NULL) {
                q.push(temp ->right);
                v->push_back(temp -> right -> val);
            }
        }
    }
}

    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<int> ino;
        vector<vector<int>> ans;

        levelOrderTraversal(root, &ino, &ans);

        return ans;
    }
};