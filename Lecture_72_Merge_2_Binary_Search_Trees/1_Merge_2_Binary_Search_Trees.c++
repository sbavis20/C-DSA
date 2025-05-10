#include <iostream>
#include <vector>
using namespace std;

// TreeNode definition
template <typename T>
class TreeNode {
public:
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

// Inorder traversal to get sorted array
void inorder(TreeNode<int>* root, vector<int>& in) {
    if (root == NULL) return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

// Merge two sorted arrays
vector<int> mergeArrays(vector<int> a, vector<int> b) {
    vector<int> ans;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans.push_back(a[i++]);
        } else {
            ans.push_back(b[j++]);
        }
    }

    while (i < a.size()) ans.push_back(a[i++]);
    while (j < b.size()) ans.push_back(b[j++]);

    return ans;
}

// Convert sorted array to balanced BST
TreeNode<int>* inorderToBST(int s, int e, vector<int>& in) {
    if (s > e) return NULL;

    int mid = s + (e - s) / 2;
    TreeNode<int>* root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);
    return root;
}

// Main merge function
TreeNode<int>* mergeBST(TreeNode<int>* root1, TreeNode<int>* root2) {
    vector<int> bst1, bst2;

    inorder(root1, bst1);
    inorder(root2, bst2);

    vector<int> mergedArray = mergeArrays(bst1, bst2);

    return inorderToBST(0, mergedArray.size() - 1, mergedArray);
}

// Helper to print inorder traversal of BST
void printInorder(TreeNode<int>* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Example usage
int main() {
    // BST 1:       2
    //             / \
    //            1   3
    TreeNode<int>* root1 = new TreeNode<int>(2);
    root1->left = new TreeNode<int>(1);
    root1->right = new TreeNode<int>(3);

    // BST 2:     5
    //           / \
    //          4   6
    TreeNode<int>* root2 = new TreeNode<int>(5);
    root2->left = new TreeNode<int>(4);
    root2->right = new TreeNode<int>(6);

    TreeNode<int>* merged = mergeBST(root1, root2);

    cout << "Merged BST (Inorder): ";
    printInorder(merged);
    cout << endl;

    return 0;
}
