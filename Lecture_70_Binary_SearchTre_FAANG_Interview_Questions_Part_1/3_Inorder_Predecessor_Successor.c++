#include <iostream>
#include <utility>
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

// Function to insert nodes into BST
TreeNode* insert(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->data) root->left = insert(root->left, key);
    else root->right = insert(root->right, key);
    return root;
}

pair<int, int> predecessorSuccessor(TreeNode* root, int key) {
    TreeNode* temp = root;

    int pred = -1;
    int suc = -1;

    // Find the node with key
    while (temp && temp->data != key) {
        if (temp->data > key) {
            suc = temp->data;
            temp = temp->left;
        } else {
            pred = temp->data;
            temp = temp->right;
        }
    }

    if (!temp) return {pred, suc}; // key not found

    // Find the predecessor in left subtree
    TreeNode* leftTree = temp->left;
    while (leftTree) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // Find the successor in right subtree
    TreeNode* rightTree = temp->right;
    while (rightTree) {
        suc = rightTree->data;
        rightTree = rightTree->left;
    }

    return {pred, suc};
}

int main() {
    TreeNode* root = nullptr;

    // Create BST
    int keys[] = {20, 8, 22, 4, 12, 10, 14};
    for (int key : keys)
        root = insert(root, key);

    int target = 10;
    pair<int, int> result = predecessorSuccessor(root, target);

    cout << "Predecessor of " << target << " is: " << result.first << endl;
    cout << "Successor of " << target << " is: " << result.second << endl;

    return 0;
}
