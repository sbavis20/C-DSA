#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findPosition(int in[], int element, int n) {
        for (int i = 0; i < n; i++) {
            if (in[i] == element)
                return i;
        }
        return -1; // element not found
    }

    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n) {
        if (index >= n || inorderStart > inorderEnd)
            return NULL;

        int element = pre[index++];
        Node* root = new Node(element);

        int position = findPosition(in, element, n);

        root->left = solve(in, pre, index, inorderStart, position - 1, n);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n);

        return root;
    }

    Node* buildTree(int in[], int pre[], int n) {
        int preOrderIndex = 0;
        return solve(in, pre, preOrderIndex, 0, n - 1, n);
    }
};

// Print Inorder traversal
void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int inorder[] = {9, 3, 15, 20, 7};
    int preorder[] = {3, 9, 20, 15, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    Solution obj;
    Node* root = obj.buildTree(inorder, preorder, n);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
