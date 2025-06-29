/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* newNode(int val) {
    return new Node(val);
}
*/

class Solution {
  public:
  
  pair<int,int> diameterFast(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            //pelo int -> diameter, bijo int->height
            return p;
        }
        
        // lengthy approach, TC:o(n*n)
        
        // int op1 = diameter(root->left);
        // int op2 = diameter(root->right);
        // int op3 = height(root->left) + height(root->right) + 1;
        
        // int ans = max( max(op1,op2), op3 );
        // return ans;

        
        // TC:O(n)
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;                      // left side nu diameter
        int op2 = right.first;                     // right side nu diameter
        int op3 = left.second + right.second + 1;  // bey side ni height no sum + 1 
        
        
        pair<int,int> ans;
        
        ans.first = max( max(op1,op2), op3 );
        
        ans.second = max(left.second , right.second) + 1;

        return ans;
    }

    
    int diameter(Node* root) {
        // Your code here
        return diameterFast(root).first - 1;      //edges no count gane chhe
    }
};