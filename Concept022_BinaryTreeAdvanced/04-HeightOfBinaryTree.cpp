/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// TC: O(n)
// SC: O(n)

class Solution {
  public:
    int height(Node* node) {
        // code here
        if(node == NULL){
            return -1;    // here height is equal to no. of edges not nodes

            // return 0;          if we consider no. of nodes as height
        }
        
        int left = height(node->left);
        int right = height(node->right);
        
        return max(left, right)+1;
    }
};