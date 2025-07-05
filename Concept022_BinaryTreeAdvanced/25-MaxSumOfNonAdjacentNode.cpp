// Node Structure
/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
  
     pair<int,int> solve(Node* root) { // <int, int. ma badhai node mate 2 answers lidha
        //base case                    // cur node ne gani ne sum, ane curr node ne exclude kari ne sum
        if(root == NULL) {              // evu jaruri nathi ke ek node ne exclude kairi hoi to eni adjacent ne include karvi pade
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> res;
        
        res.first = root->data + left.second + right.second;
        
        res.second = max(left.first, left.second) + max(right.first, right.second);
        
        return res;
        
    }
    
    int getMaxSum(Node *root) {
        // code here
        pair<int,int> ans = solve(root);
        return max(ans.first, ans.second);
    }
};