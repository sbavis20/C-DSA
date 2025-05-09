#include <iostream>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int>* root, int &ans) {
    // Base case: if the node is NULL
    if (root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    // Recursive calls for left and right subtrees
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;

    // Calculate the size of the current node's subtree
    currNode.size = left.size + right.size + 1;

    // Update the maximum and minimum values for the current node
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    // Check if the current subtree is a BST
    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isBST = true;
    } else {
        currNode.isBST = false;
    }

    // If the current subtree is a BST, update the answer (max size of BST found)
    if (currNode.isBST) {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestBST(TreeNode<int>* root) {
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}

int main() {
    // Create test cases
    TreeNode<int>* root1 = new TreeNode<int>(10);
    root1->left = new TreeNode<int>(5);
    root1->right = new TreeNode<int>(15);
    root1->left->left = new TreeNode<int>(1);
    root1->left->right = new TreeNode<int>(8);
    root1->right->right = new TreeNode<int>(7);

    cout << "Largest BST size in Tree 1: " << largestBST(root1) << endl;

    TreeNode<int>* root2 = new TreeNode<int>(10);
    root2->left = new TreeNode<int>(5);
    root2->right = new TreeNode<int>(15);
    root2->left->left = new TreeNode<int>(1);
    root2->left->right = new TreeNode<int>(8);
    root2->right->left = new TreeNode<int>(12);
    root2->right->right = new TreeNode<int>(20);

    cout << "Largest BST size in Tree 2: " << largestBST(root2) << endl;

    return 0;
}
