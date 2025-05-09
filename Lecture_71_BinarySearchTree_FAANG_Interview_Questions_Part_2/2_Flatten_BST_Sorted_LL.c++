#include <iostream>
#include <vector>
using namespace std;

// Definition of TreeNode
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(T val) {
        data = val;
        left = right = nullptr;
    }
};

// Inorder traversal
void inorder(TreeNode<int>* root, vector<int>& in) {
    if (root == NULL) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Flatten BST into right-skewed tree
TreeNode<int>* flatten(TreeNode<int>* root) {
    vector<int> inorderVal;
    inorder(root, inorderVal);

    if (inorderVal.empty()) return nullptr;

    TreeNode<int>* newRoot = new TreeNode<int>(inorderVal[0]);
    TreeNode<int>* curr = newRoot;

    for (int i = 1; i < inorderVal.size(); i++) {
        TreeNode<int>* temp = new TreeNode<int>(inorderVal[i]);
        curr->left = nullptr;
        curr->right = temp;
        curr = temp;
    }

    return newRoot;
}

// Helper function to insert into BST
TreeNode<int>* insertIntoBST(TreeNode<int>* root, int val) {
    if (!root) return new TreeNode<int>(val);
    if (val < root->data)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);
    return root;
}

// Print right-skewed tree
void printRightSkewed(TreeNode<int>* root) {
    TreeNode<int>* curr = root;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    TreeNode<int>* root = nullptr;
    vector<int> values = {10, 5, 1, 7, 15, 12, 20};

    for (int val : values)
        root = insertIntoBST(root, val);

    TreeNode<int>* flattened = flatten(root);
    cout << "Right-skewed flattened BST: ";
    printRightSkewed(flattened);

    return 0;
}
