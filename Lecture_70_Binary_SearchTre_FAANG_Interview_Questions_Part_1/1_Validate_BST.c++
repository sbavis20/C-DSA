#include <iostream>
#include <climits>
using namespace std;

// Definition of Binary Tree Node
template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Helper function to check if a binary tree is a BST
bool isBST(BinaryTreeNode<int> *root, int min, int max) {
    if (root == NULL) {
        return true;
    }

    if (root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data - 1);
        bool right = isBST(root->right, root->data + 1, max);
        return left && right;
    } else {
        return false;
    }
}

// Public function to validate BST
bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root, INT_MIN, INT_MAX);
}

// ---------------------------
// Main Function with Test Cases
// ---------------------------
int main() {
    // Test Case 1: Valid BST
    BinaryTreeNode<int>* root1 = new BinaryTreeNode<int>(10);
    root1->left = new BinaryTreeNode<int>(5);
    root1->right = new BinaryTreeNode<int>(15);
    root1->left->left = new BinaryTreeNode<int>(2);
    root1->left->right = new BinaryTreeNode<int>(8);
    root1->right->right = new BinaryTreeNode<int>(20);

    cout << "Test Case 1 - Should be BST: ";
    cout << (validateBST(root1) ? "YES" : "NO") << endl;

    // Test Case 2: Not a BST
    BinaryTreeNode<int>* root2 = new BinaryTreeNode<int>(10);
    root2->left = new BinaryTreeNode<int>(5);
    root2->right = new BinaryTreeNode<int>(8); // Invalid: 8 < 10

    cout << "Test Case 2 - Should not be BST: ";
    cout << (validateBST(root2) ? "YES" : "NO") << endl;

    // Test Case 3: Single Node
    BinaryTreeNode<int>* root3 = new BinaryTreeNode<int>(42);

    cout << "Test Case 3 - Single node tree is BST: ";
    cout << (validateBST(root3) ? "YES" : "NO") << endl;

    // Test Case 4: Empty Tree
    BinaryTreeNode<int>* root4 = NULL;

    cout << "Test Case 4 - Empty tree is BST: ";
    cout << (validateBST(root4) ? "YES" : "NO") << endl;

    return 0;
}
