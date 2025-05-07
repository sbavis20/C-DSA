#include <iostream>
#include <map>
using namespace std;

// Definition of a Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    void createMapping(int in[], map<int, int> &nodeToIndex, int n) {
        for (int i = 0; i < n; i++) {
            nodeToIndex[in[i]] = i;
        }
    }

    Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex) {
        if (index < 0 || inorderStart > inorderEnd) {
            return NULL;
        }

        int element = post[index--];
        Node* root = new Node(element);

        int position = nodeToIndex[element];

        // Important: Build right subtree first
        root->right = solve(in, post, index, position + 1, inorderEnd, n, nodeToIndex);
        root->left = solve(in, post, index, inorderStart, position - 1, n, nodeToIndex);

        return root;
    }

    Node* buildTree(int in[], int post[], int n) {
        int postOrderIndex = n - 1;
        map<int, int> nodeToIndex;
        createMapping(in, nodeToIndex, n);
        return solve(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex);
    }
};

// Inorder traversal to verify result
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Main function with test case
int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int postorder[] = {9, 15, 7, 20, 3};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Solution obj;
    Node* root = obj.buildTree(inorder, postorder, n);

    cout << "Inorder of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
