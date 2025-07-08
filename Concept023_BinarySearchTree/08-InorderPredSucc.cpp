#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Function to find the predecessor and successor
// of a given key in BST and return them in a vector

vector<Node*> findPreSuc(Node* root, int key) {
    vector<Node*> result;  
    Node* pre = NULL;
    Node* suc = NULL;

    // If root is null, return empty vector
    if (!root)
        return result;

    // Traverse the tree
    while (root != NULL) {
        if (root->data < key) {
            // Current node is the predecessor
            pre = root;  
            // Move to right subtree to find a larger node
            root = root->right;  
        }
        else if (root->data > key) {
            // Current node is the successor
            suc = root;  
            // Move to left subtree to find a smaller node
            root = root->left;  
        } 
        else {
            // When we find the node with the key, we can exit
            if (root->left) {
                Node* temp = root->left;
                while (temp->right) temp = temp->right;
                // The largest node in the left subtree is the predecessor
                pre = temp;  
            }
            if (root->right) {
                Node* temp = root->right;
                while (temp->left) temp = temp->left;
                // The smallest node in the right subtree is the successor
                suc = temp;             
            }
            break;
        }
    }

    // Push the predecessor and successor into the result vector
    result.push_back(pre ? pre : NULL);
    result.push_back(suc ? suc : NULL);

    return result;
}


// Inorder: 1, 2, [3]p, 4key, [5]s, 6

// find key in tree, grestest value in its left sub tree is inorder predecessor
//                   smallest value in its right sub tree is inorder successor

int main() {
    int key = 70;   
  
    Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->right = new Node(80);
    root->right->left = new Node(60);

    // Find predecessor and successor
    vector<Node*> result = findPreSuc(root, key);

    // Output the result
    if (result[0] != NULL)
        cout << result[0]->data << " ";
    else
        cout << -1 << " ";

    if (result[1] != NULL)
        cout << result[1]->data << endl;
    else
        cout << -1 << endl;

    return 0;
}