#include <iostream>
#include <vector>
using namespace std;

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie(char ch) {
        root = new TrieNode(ch);
    }

    void insertWord(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';
            if (curr->children[index] != NULL) {
                curr = curr->children[index];
            } else {
                TrieNode* newNode = new TrieNode(ch);
                curr->children[index] = newNode;
                curr->childCount++;
                curr = newNode;
            }
        }
        curr->isTerminal = true;
    }

    string getLCP(string firstWord) {
        string ans = "";
        TrieNode* curr = root;

        for (char ch : firstWord) {
            int index = ch - 'a';
            if (curr->childCount == 1 && !curr->isTerminal) {
                ans += ch;
                curr = curr->children[index];
            } else {
                break;
            }
        }

        return ans;
    }
};

string longestCommonPrefix(vector<string> &arr, int n) {
    Trie *t = new Trie('\0');

    for (int i = 0; i < n; i++) {
        t->insertWord(arr[i]);
    }

    return t->getLCP(arr[0]);
}

// ------------------- Main with Test Cases ----------------------

int main() {
    vector<string> arr1 = {"flower", "flow", "flight"};
    vector<string> arr2 = {"dog", "racecar", "car"};
    vector<string> arr3 = {"apple", "applepie", "appletree"};
    vector<string> arr4 = {"interview", "internet", "internal", "interval"};

    cout << "Longest Common Prefix (Test 1): " << longestCommonPrefix(arr1, arr1.size()) << endl;
    cout << "Longest Common Prefix (Test 2): " << longestCommonPrefix(arr2, arr2.size()) << endl;
    cout << "Longest Common Prefix (Test 3): " << longestCommonPrefix(arr3, arr3.size()) << endl;
    cout << "Longest Common Prefix (Test 4): " << longestCommonPrefix(arr4, arr4.size()) << endl;

    return 0;
}
