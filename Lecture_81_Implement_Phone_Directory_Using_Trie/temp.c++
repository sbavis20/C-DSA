#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (curr->children[index] == NULL) {
                curr->children[index] = new TrieNode(ch);
            }
            curr = curr->children[index];
        }
        curr->isTerminal = true;
    }

    void printSuggestions(TrieNode* curr, vector<string>& temp, string prefix) {
        if (curr->isTerminal) {
            temp.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            TrieNode* next = curr->children[ch - 'a'];
            if (next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();  // backtrack
            }
        }
    }

    vector<vector<string>> getSuggestions(string str) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for (int i = 0; i < str.length(); i++) {
            char lastch = str[i];
            prefix.push_back(lastch);
            TrieNode* curr = prev->children[lastch - 'a'];

            if (curr == NULL) {
                // Fill remaining with "0"
                while (i++ < str.length())
                    output.push_back({"0"});
                break;
            }

            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            if (temp.empty())
                output.push_back({"0"});
            else {
                sort(temp.begin(), temp.end());
                output.push_back(temp);
            }

            prev = curr;
        }

        return output;
    }
};
vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    Trie *t = new Trie();

    for(int i=0;i<contactList.size();i++){
        string str = contactList[i];
        t->insert(str);
    }

    return getSuggestions(queryStr);
}
