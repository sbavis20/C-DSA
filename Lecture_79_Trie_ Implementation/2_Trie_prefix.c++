#include <iostream>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');  // Root doesn't hold any meaningful character
    }

    void insertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word) {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0] - 'a';  // corrected from 'A'
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root, word);
    }

    bool startsWithUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            return true;
        }

        int index = word[0] - 'a';  // corrected from 'A'
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return startsWithUtil(child, word.substr(1));
    }

    bool startsWith(string prefix) {
        return startsWithUtil(root, prefix);  // added missing return
    }
};

// Main function with test cases
int main() {
    Trie* obj = new Trie();

    obj->insert("apple");
    obj->insert("app");
    obj->insert("bat");
    obj->insert("batman");

    cout << boolalpha;
    cout << "Search 'apple': " << obj->search("apple") << endl;
    cout << "Search 'app': " << obj->search("app") << endl;
    cout << "Search 'batman': " << obj->search("batman") << endl;
    cout << "Search 'bat': " << obj->search("bat") << endl;
    cout << "Search 'batwoman': " << obj->search("batwoman") << endl;
    cout << "StartsWith 'app': " << obj->startsWith("app") << endl;
    cout << "StartsWith 'bat': " << obj->startsWith("bat") << endl;
    cout << "StartsWith 'bad': " << obj->startsWith("bad") << endl;

    return 0;
}
