#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

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

void printBT(const string& prefix, const Node* root, bool isLeft)
{
    if( root != NULL )
    {
        cout << prefix;

        cout << (isLeft ? "(const char [10])" : "(const char [10])" );

        // print the value of the node
        cout << root->data << endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "(const char [7])" : "    "), root->left, true);
        printBT( prefix + (isLeft ? "(const char [10])" : "    "), root->right, false);
    }
}

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

int main(){
    Node* root = NULL;
    cout << "Enter data:"<< endl;
    takeInput(root);
    printBT("", root, false);

    //to rotate 90deg clockwise
    int n = mat.size();

    for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {        
                
                swap(mat[i][j], mat[j][i]);             

            }
        }

    for (int i = 0; i < n/2; i++) {
            for (int j = 0; j < n; j++) {

               swap(mat[i][j], mat[n-1-i][j]); 
            }
        }

     //to rotate 90deg anticlockwise

     

    return 0;

}