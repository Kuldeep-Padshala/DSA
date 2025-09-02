// Node structure for Trie
class TrieNode {
public:
    char data;
    TrieNode* children[26];  // 26 lowercase English letters
    bool isTerminal;         // Marks end of a valid word

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode('\0');  // Root is empty character
    }

    // Insert word into Trie
    void insertHelper(TrieNode* node, string word) {
        if (word.length() == 0) {
            node->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        // If child already exists
        if (node->children[index] != NULL) {
            child = node->children[index];
        } else {
            // Create new node
            child = new TrieNode(word[0]);
            node->children[index] = child;
        }

        // Recur for remaining string
        insertHelper(child, word.substr(1));
    }

    void insert(string word) {
        insertHelper(root, word);
    }

    // Check if node has children
    bool hasChildren(TrieNode* node) {
        for (int i = 0; i < 26; i++) {
            if (node->children[i] != NULL)
                return true;
        }
        return false;
    }

    // Remove word from Trie
    void removeHelper(TrieNode* node, string word) {
        if (word.length() == 0) {
            node->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child = node->children[index];
        if (child == NULL) return;

        removeHelper(child, word.substr(1));

        // If child is no longer needed
        if (!child->isTerminal && !hasChildren(child)) {
            delete child;
            node->children[index] = NULL;
        }
    }

    void remove(string word) {
        removeHelper(root, word);
    }

    // DFS to collect all words from current TrieNode with given prefix
    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal)
            temp.push_back(prefix);

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back(); // backtrack
            }
        }
    }

    // For each prefix of search string, collect matching suggestions
    vector<vector<string>> getSuggestions(string str) {
        
        TrieNode* prev = root;
        vector<vector<string>> ans;
        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char lastchar = str[i];
            prefix.push_back(lastchar);

            TrieNode* curr = prev->children[lastchar - 'a'];

            // If not found, break and fill remaining with "0"
            if (curr == NULL) {
                break;
            }

            // Found a node; gather suggestions from here
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            ans.push_back(temp);

            prev = curr;
        }

        // If fewer answers than length of input, pad rest with "0"
        while (ans.size() < str.length()) {
            ans.push_back({"0"});
        }

        return ans;
    }

    TrieNode* getRoot() {
        return root;
    }
};

// Main function to solve the problem
class Solution {
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s) {
        Trie* t = new Trie();

        // Insert all contacts into the Trie
        for (int i = 0; i < n; i++) {
            t->insert(contact[i]);
        }

        // Get suggestions for all prefixes of 's'
        return t->getSuggestions(s);
    }
};
