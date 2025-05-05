#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib> // for abs()
using namespace std;

// Binary Tree Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to calculate height of the tree
    int height(Node* node) {
        if(node == NULL) {
            return 0;
        }
        return max(height(node->left), height(node->right)) + 1;
    }

    // Function to check if tree is balanced
    bool isBalanced(Node* root) {
        // Base case
        if(root == NULL) {
            return true;
        }

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        bool diff = abs(height(root->left) - height(root->right)) <= 1;

        return left && right && diff;
    }
};

// Function to build a binary tree from level order traversal
Node* buildTree() {
    int data;
    cout << "Enter root data (-1 for NULL): ";
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* current = q.front();
        q.pop();

        int leftData, rightData;
        cout << "Enter left child of " << current->data << " (-1 for NULL): ";
        cin >> leftData;
        if(leftData != -1) {
            current->left = new Node(leftData);
            q.push(current->left);
        }

        cout << "Enter right child of " << current->data << " (-1 for NULL): ";
        cin >> rightData;
        if(rightData != -1) {
            current->right = new Node(rightData);
            q.push(current->right);
        }
    }

    return root;
}

// Function to print the tree (inorder traversal)
void printTree(Node* root) {
    if(root == NULL) {
        return;
    }

    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

int main() {
    Solution sol;
    int choice;

    cout << "Choose an option:\n";
    cout << "1. Enter tree manually\n";
    cout << "2. Run test cases\n";
    cin >> choice;

    if(choice == 1) {
        Node* root = buildTree();
        cout << "\nTree (Inorder): ";
        printTree(root);
        if(sol.isBalanced(root)) {
            cout << "\nThe tree is balanced" << endl;
        } else {
            cout << "\nThe tree is not balanced" << endl;
        }
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree): ";
        if(sol.isBalanced(root1)) {
            cout << "Balanced" << endl;
        } else {
            cout << "Not balanced" << endl;
        }

        // Test Case 2: Single node
        Node* root2 = new Node(1);
        cout << "Test Case 2 (Single node): ";
        if(sol.isBalanced(root2)) {
            cout << "Balanced" << endl;
        } else {
            cout << "Not balanced" << endl;
        }

        // Test Case 3: Balanced tree
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->right = new Node(3);
        cout << "Test Case 3 (Balanced tree): ";
        if(sol.isBalanced(root3)) {
            cout << "Balanced" << endl;
        } else {
            cout << "Not balanced" << endl;
        }

        // Test Case 4: Unbalanced tree (left skewed)
        Node* root4 = new Node(1);
        root4->left = new Node(2);
        root4->left->left = new Node(3);
        cout << "Test Case 4 (Left skewed tree): ";
        if(sol.isBalanced(root4)) {
            cout << "Balanced" << endl;
        } else {
            cout << "Not balanced" << endl;
        }

        // Test Case 5: Unbalanced tree (right skewed)
        Node* root5 = new Node(1);
        root5->right = new Node(2);
        root5->right->right = new Node(3);
        cout << "Test Case 5 (Right skewed tree): ";
        if(sol.isBalanced(root5)) {
            cout << "Balanced" << endl;
        } else {
            cout << "Not balanced" << endl;
        }

        // Test Case 6: Complex balanced tree
        Node* root6 = new Node(1);
        root6->left = new Node(2);
        root6->right = new Node(3);
        root6->left->left = new Node(4);
        root6->left->right = new Node(5);
        root6->right->left = new Node(6);
        cout << "Test Case 6 (Complex balanced tree): ";
        if(sol.isBalanced(root6)) {
            cout << "Balanced" << endl;
        } else {
            cout << "Not balanced" << endl;
        }
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
