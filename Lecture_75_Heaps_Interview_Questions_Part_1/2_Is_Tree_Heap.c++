#include <iostream>
using namespace std;

// Define Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

bool isCBT(Node* root, int index, int cnt) {
    if (root == NULL) {
        return true;
    }
    if (index >= cnt) {
        return false;
    }

    bool left = isCBT(root->left, 2 * index + 1, cnt);
    bool right = isCBT(root->right, 2 * index + 2, cnt);

    return (left && right);
}

bool isMaxOrder(Node* root) {
    // Leaf node
    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    // Node with only left child
    if (root->right == NULL) {
        return (root->data > root->left->data);
    } else {
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right &&
                root->data > root->left->data &&
                root->data > root->right->data);
    }
}

bool isHeap(Node* root) {
    int totalCount = countNodes(root);
    return isCBT(root, 0, totalCount) && isMaxOrder(root);
}

// Sample tree testing
int main() {
    /*
         90
        /  \
      15    10
     / \   /
    7  12  5
    */

    Node* root = new Node(90);
    root->left = new Node(15);
    root->right = new Node(10);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right->left = new Node(5);

    if (isHeap(root)) {
        cout << "The binary tree is a Max-Heap" << endl;
    } else {
        cout << "The binary tree is NOT a Max-Heap" << endl;
    }

    return 0;
}
