#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

// BST no inorder traversal is Sorted

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* insertIntoBST(Node* &root,int x){

    if(root == NULL){
        root = new Node(x);
        return root;
    }

    if(x > root->data){
        root->right = insertIntoBST(root->right, x);
    }
    else{
        root->left = insertIntoBST(root->left, x);
    }
    return root;

}

void takeInput(Node* &root){

    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrderTraversal(Node* root) {

    if(root == NULL){
        cout << "Tree is empty."<<endl;
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    // 50 20 15 -1 -1 5 -1 -1 30 12 6 -1 -1 6 -1 -1 18 8 -1 -1 10 5 -1 -1 -1

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();                        //removes front

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left != NULL) {
                q.push(temp ->left);
            }

            if(temp ->right != NULL) {
                q.push(temp ->right);
            }
        }
    }

}

void inOrder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inOrder(root->left);
    cout << root-> data << " ";
    inOrder(root->right);

}

void preOrder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preOrder(root->left);
    preOrder(root->right);

}

void postOrder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root-> data << " ";
}


int main(){
    Node* root = NULL;
    cout << "Enter data:"<< endl;
    takeInput(root);

    cout << "Level order traversal of the BST is: " << endl;
    levelOrderTraversal(root);

    cout << endl << "Preorder:" << endl;
    preOrder(root);
    cout << endl <<"Inorder:" << endl;
    inOrder(root);
    cout << endl <<"Postorder: " << endl;
    postOrder(root);

    return 0;

}