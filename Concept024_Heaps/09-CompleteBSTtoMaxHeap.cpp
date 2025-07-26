// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        vector<int> ino;
        inorder(root, ino);
        
        int i=0;
        solve(root, ino, i);
    }
    
  private:
  
    void inorder(Node* root, vector<int> &s) {
    //base case
        if(root == NULL) {
            return ;
        }

        inorder(root->left, s);
   	
        //leaf node
        s.push_back(root->data);
    
        inorder(root->right, s);
    }
    
     void solve(Node* root, vector<int>& ino, int& index) {
         
        if (root == NULL) 
        return;
        
        solve(root->left, ino, index);
        solve(root->right, ino, index);
        root->data = ino[index++];  // Assign value during postorder traversal
        
    }
};
