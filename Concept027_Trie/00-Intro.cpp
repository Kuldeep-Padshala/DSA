// Trie is a data structure that is used to store a dynamic set of strings, 
// where the keys are usually strings. It is particularly useful for tasks like 
// autocomplete, spell checking, and IP routing.

// if word 'timer' is already present, and if we want to add word 'time' 
// then we can just add 'time' as a child of 'timer' node,


#include<iostream>

using namespace std;

class TrieNode {

    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    // Constructor for memmory allocation
    

    TrieNode(char ch) {
        this->data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{

    TrieNode* root;

    public:

    Trie() {
        root = new TrieNode('\0');
    }

    void insertHelper(TrieNode* root, string word){

        // base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){   // present
            
            child = root->children[index];   // go ahead
        }

        else{                               // not present
            
            child = new TrieNode(word[0]);   // create a new node
            root->children[index] = child;   // and go ahead
        }

        // recursive call
        insertHelper(child, word.substr(1));  // passing the remaining string
    }

    void insert(string word) {

        insertHelper(root, word);
    }

    bool searchHelper(TrieNode* root, string word){

        // base case
        if(word.length()==0){      // we found, last char is terminal or not
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){     // present
            
            child = root->children[index];   // go ahead
        }

        else{                                 // not present
            return false;
        }
        return searchHelper(child, word.substr(1));
    }
    
    bool search(string word) {
        
        return searchHelper(root, word);
    }

    bool hasChildren(TrieNode* node) {
        
        for(int i = 0; i < 26; i++) {
            
           if (node->children[i] != NULL)
           return true;
        }

        return false;
    }

    void removeHelper(TrieNode* root, string word){

        // base case
        if(word.length()==0){
            root->isTerminal = false;  // mark the last char as not terminal
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if(root->children[index] != NULL){   // present
            
            child = root->children[index];   // go ahead
        }

        else{                               // not present
            return;  // nothing to remove
        }

        removeHelper(child, word.substr(1));  // recursive call

        // after removing the word, we can check if we can delete the node or not
        if(child->isTerminal == false && !hasChildren(child)){  // if it is not terminal, then we can delete it
            delete child;
            root->children[index] = NULL;  // mark it as NULL
        }

    }

    void remove(string word){

        removeHelper(root, word);
    }

};

int main(){

    Trie* t = new Trie();

    t->insert("abcd");
    t->insert("xyz");
    t->insert("apple");
    t->insert("app");

    cout << "apple is present: " << t->search("apple") << endl;
    cout << "app is present: " << t->search("app") << endl;

    t->remove("apple");
    cout << "apple is present: " << t->search("apple") << endl;
    cout << "app is present: " << t->search("app") << endl;

    return 0;
}