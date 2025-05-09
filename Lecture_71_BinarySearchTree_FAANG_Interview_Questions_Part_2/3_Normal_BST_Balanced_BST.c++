#include <iostream>
#include <vector>
#include <queue>
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
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Convert inorder array to balanced BST
TreeNode<int>* inorderTOBST(int s, int e, vector<int>& in) {
    if (s > e) return NULL;

    int mid = (s + e) / 2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);

    root->left = inorderTOBST(s, mid - 1, in);
    root->right = inorderTOBST(mid + 1, e, in);

    return root;
}

// Convert unbalanced BST to balanced BST
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> inorderVal;
    inorder(root, inorderVal);
    return inorderTOBST(0, inorderVal.size() - 1, inorderVal);
}

// Helper function to insert nodes in BST
TreeNode<int>* insertBST(TreeNode<int>* root, int val) {
    if (!root)
        return new TreeNode<int>(val);

    if (val < root->data)
        root->left = insertBST(root->left, val);
    else
        root->right = insertBST(root->right, val);

    return root;
}

// Level order traversal for visual confirmation
void levelOrder(TreeNode<int>* root) {
    if (!root) return;
    queue<TreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        while (n--) {
            TreeNode<int>* curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
        cout << endl;
    }
}

int main() {
    TreeNode<int>* root = nullptr;

    // Creating an unbalanced BST
    root = insertBST(root, 10);
    root = insertBST(root, 8);
    root = insertBST(root, 7);
    root = insertBST(root, 6);
    root = insertBST(root, 5);

    cout << "Original (Unbalanced) BST Level Order:\n";
    levelOrder(root);

    TreeNode<int>* balanced = balancedBst(root);

    cout << "\nBalanced BST Level Order:\n";
    levelOrder(balanced);

    return 0;
}
