/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
  // 7 + 
  
  pair<int,int> longestPathSum(Node* node,int height,int sum) {
      
        // code here
        
        if (node == NULL) {
            // Return {height, sum} at the leaf
            return {height, sum};
        }

        // Add current node's data to sum
        sum += node->data;

        // Explore left and right
        pair<int,int> left = longestPathSum(node->left, height + 1, sum);
        pair<int,int> right = longestPathSum(node->right, height + 1, sum);

        // Choose path with greater height or greater sum if heights are equal
        if (left.first > right.first) {
            
            return left;
        } 
        else if (right.first > left.first) {
            
            return right;
        } 
        else {
            // Heights equal, choose max sum
            return {left.first, max(left.second, right.second)};
        }
        
    
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        return longestPathSum(root, 0, 0).second;
    }
};