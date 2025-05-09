#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to insert nodes into a BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

// Function to find the Lowest Common Ancestor in a BST
TreeNode* LCAinaBST(TreeNode* root, TreeNode* P, TreeNode* Q) {
    if (!root) return nullptr;

    if (root->data > P->data && root->data > Q->data)
        return LCAinaBST(root->left, P, Q);

    if (root->data < P->data && root->data < Q->data)
        return LCAinaBST(root->right, P, Q);

    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root || root->data == val) return root;
    if (val < root->data) return findNode(root->left, val);
    return findNode(root->right, val);
}

int main() {
    TreeNode* root = nullptr;
    int keys[] = {20, 8, 22, 4, 12, 10, 14};

    // Build BST
    for (int key : keys)
        root = insert(root, key);

    // Find nodes
    TreeNode* P = findNode(root, 10);
    TreeNode* Q = findNode(root, 14);

    TreeNode* lca = LCAinaBST(root, P, Q);

    if (lca)
        cout << "LCA of " << P->data << " and " << Q->data << " is: " << lca->data << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}
