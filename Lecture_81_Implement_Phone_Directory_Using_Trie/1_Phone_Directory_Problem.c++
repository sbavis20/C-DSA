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
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void insertWord(string word) {
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

    void getSuggestionsFromNode(TrieNode* curr, string prefix, vector<string>& suggestions) {
        if (curr->isTerminal) {
            suggestions.push_back(prefix);
        }

        for (char ch = 'a'; ch <= 'z'; ch++) {
            int index = ch - 'a';
            if (curr->children[index] != NULL) {
                getSuggestionsFromNode(curr->children[index], prefix + ch, suggestions);
            }
        }
    }

    vector<string> getSuggestions(string prefix) {
        TrieNode* curr = root;
        vector<string> result;

        for (char ch : prefix) {
            int index = ch - 'a';
            if (curr->children[index] == NULL) {
                return {}; // No match found
            }
            curr = curr->children[index];
        }

        getSuggestionsFromNode(curr, prefix, result);
        return result;
    }
};

// Main function to process the full query and return list of suggestions for each prefix
vector<vector<string>> phoneDirectory(vector<string>& contactList, string& queryStr) {
    Trie* t = new Trie();

    // Insert all contacts into Trie
    for (string contact : contactList) {
        t->insertWord(contact);
    }

    vector<vector<string>> ans;
    string prefix = "";

    for (char ch : queryStr) {
        prefix += ch;
        vector<string> suggestions = t->getSuggestions(prefix);
        if (suggestions.empty()) {
            // Fill remaining prefixes with "0" if no results
            while (ans.size() < queryStr.size()) {
                ans.push_back({"0"});
            }
            break;
        }
        sort(suggestions.begin(), suggestions.end()); // Optional: sort lexicographically
        ans.push_back(suggestions);
    }

    return ans;
}

// ------------------------ Test Cases --------------------------
int main() {
    vector<string> contacts = {"alice", "bob", "alex", "allen", "albert", "batman"};
    string query = "al";

    vector<vector<string>> results = phoneDirectory(contacts, query);

    cout << "Suggestions for each prefix of \"" << query << "\":" << endl;
    for (int i = 0; i < results.size(); ++i) {
        cout << "Prefix \"" << query.substr(0, i + 1) << "\": ";
        for (const string& suggestion : results[i]) {
            cout << suggestion << " ";
        }
        cout << endl;
    }

    return 0;
}
