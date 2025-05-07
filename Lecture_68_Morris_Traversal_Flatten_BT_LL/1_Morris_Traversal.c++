#include <iostream>
#include <vector>
using namespace std;

// Node definition for binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Morris Inorder Traversal
vector<int> inOrder(Node* root) {
    vector<int> res;
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            res.push_back(curr->data);
            curr = curr->right;
        }
        else {
            Node* prev = curr->left;
            while (prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = nullptr;
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return res;
}

// Helper to build a sample binary tree
Node* buildTestTree() {
    /*
             1
            / \
           2   3
          / \   \
         4   5   6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    return root;
}

int main() {
    Node* root = buildTestTree();
    vector<int> result = inOrder(root);

    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}
