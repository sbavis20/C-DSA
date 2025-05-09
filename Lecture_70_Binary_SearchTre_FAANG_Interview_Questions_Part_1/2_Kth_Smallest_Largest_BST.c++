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
        left = nullptr;
        right = nullptr;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

// Helper function to find the kth smallest element
int solve(BinaryTreeNode<int>* root, int& i, int k) {
    if (!root) return -1;

    int left = solve(root->left, i, k);
    if (left != -1) return left;

    i++;
    if (i == k) return root->data;

    return solve(root->right, i, k);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i = 0;
    return solve(root, i, k);
}

// Test cases in main function
int main() {
    /*
            5
           / \
          3   7
         / \ / \
        2  4 6  8
    */
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(5);
    root->left = new BinaryTreeNode<int>(3);
    root->right = new BinaryTreeNode<int>(7);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(4);
    root->right->left = new BinaryTreeNode<int>(6);
    root->right->right = new BinaryTreeNode<int>(8);

    for (int k = 1; k <= 7; k++) {
        cout << k << "th smallest: " << kthSmallest(root, k) << endl;
    }

    delete root;
    return 0;
}
