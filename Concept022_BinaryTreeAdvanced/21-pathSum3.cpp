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
// TC: ?    can be done using nmap

class Solution {
public:

void solve(TreeNode* root, int k, int &count, vector<int> path) {
        //base case
        if(root == NULL)
            return ;
        
        path.push_back(root->val);
        
        //left
        solve(root->left, k, count, path);
        //right
        solve(root->right, k, count, path);
        
        //check for K Sum
        
        int size = path.size();
        long long sum = 0;
        for(int i = size-1; i>=0; i--)  {    // vector ma key ketli rite present chhe e count
            sum += path[i];
            if(sum == k)
                count++;
        }
        
        path.pop_back();       //fun pachu jai atle value kadhi nakhvani
    }

    int pathSum(TreeNode* root, int targetSum) {

        vector<int> path;
        int count = 0;
        solve(root, targetSum, count, path);
        return count;
    }
};