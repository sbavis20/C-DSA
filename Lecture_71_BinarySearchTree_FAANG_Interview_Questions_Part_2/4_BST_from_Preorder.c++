#include <iostream>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

BinaryTreeNode<int>* solve(vector<int>& preorder, int mini, int maxi, int& i) {
    if (i >= preorder.size()) {
        return NULL;
    }

    if (preorder[i] < mini || preorder[i] > maxi) {
        return NULL;
    }

    // Create the current root node
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[i]);
    i++;  // Move to the next element

    // Recursively construct the left and right subtrees
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);

    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int>& preorder) {
    int i = 0;
    int mini = INT_MIN;  // Minimum value of the tree node
    int maxi = INT_MAX;  // Maximum value of the tree node

    return solve(preorder, mini, maxi, i);
}

// Helper function to print the inorder traversal of the tree
void inorderTraversal(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main() {
    // Test case 1
    vector<int> preorder1 = {10, 5, 1, 7, 40, 50};
    BinaryTreeNode<int>* root1 = preorderToBST(preorder1);
    cout << "Inorder Traversal of Tree 1: ";
    inorderTraversal(root1);
    cout << endl;

    // Test case 2
    vector<int> preorder2 = {8, 5, 1, 7, 10, 12};
    BinaryTreeNode<int>* root2 = preorderToBST(preorder2);
    cout << "Inorder Traversal of Tree 2: ";
    inorderTraversal(root2);
    cout << endl;

    // Test case 3
    vector<int> preorder3 = {15, 10, 8, 12, 20, 17, 25};
    BinaryTreeNode<int>* root3 = preorderToBST(preorder3);
    cout << "Inorder Traversal of Tree 3: ";
    inorderTraversal(root3);
    cout << endl;

    return 0;
}
