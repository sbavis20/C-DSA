#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T val) {
        data = val;
        left = right = nullptr;
    }
};

// Insert into BST
BinaryTreeNode<int>* insertIntoBST(BinaryTreeNode<int>* root, int val) {
    if (!root) return new BinaryTreeNode<int>(val);
    if (val < root->data)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}

// Inorder traversal to get sorted elements
void inorder(BinaryTreeNode<int>* root, vector<int>& in) {
    if (root == NULL) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Function to find if any two nodes sum up to the target
bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
    vector<int> inorderVal;
    inorder(root, inorderVal);
    int i = 0, j = inorderVal.size() - 1;

    while (i < j) {
        int sum = inorderVal[i] + inorderVal[j];
        if (sum == target) return true;
        else if (sum < target) i++;
        else j--;
    }
    return false;
}

int main() {
    BinaryTreeNode<int>* root = nullptr;
    vector<int> values = {10, 5, 15, 3, 7, 18};

    for (int val : values)
        root = insertIntoBST(root, val);

    int target = 22;

    if (twoSumInBST(root, target))
        cout << "Found a pair with sum " << target << endl;
    else
        cout << "No pair found with sum " << target << endl;

    return 0;
}
