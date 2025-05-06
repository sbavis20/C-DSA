#include <iostream>
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
    Node* lca(Node* root, int n1, int n2) {
        // Base case
        if(root == NULL) {
            return NULL;
        }

        // If either n1 or n2 matches with root's data
        if(root->data == n1 || root->data == n2) {
            return root;
        }

        // Search for nodes in left and right subtrees
        Node* leftAns = lca(root->left, n1, n2);
        Node* rightAns = lca(root->right, n1, n2);

        // If both left and right subtrees return non-NULL, current node is LCA
        if(leftAns != NULL && rightAns != NULL) {
            return root;
        }
        // Otherwise return the non-NULL value
        else if(leftAns != NULL) {
            return leftAns;
        }
        else {
            return rightAns;
        }
    }
};

// Function to build a binary tree from user input
Node* buildTree() {
    int data;
    cout << "Enter data (-1 for NULL): ";
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    cout << "Enter left child of " << data << endl;
    root->left = buildTree();
    cout << "Enter right child of " << data << endl;
    root->right = buildTree();

    return root;
}

int main() {
    Solution sol;
    int choice;

    cout << "Choose an option:\n";
    cout << "1. Enter tree and nodes manually\n";
    cout << "2. Run test cases\n";
    cin >> choice;

    if(choice == 1) {
        Node* root = buildTree();
        int n1, n2;
        cout << "Enter first node value: ";
        cin >> n1;
        cout << "Enter second node value: ";
        cin >> n2;

        Node* result = sol.lca(root, n1, n2);
        if(result != NULL) {
            cout << "LCA of " << n1 << " and " << n2 << " is: " << result->data << endl;
        } else {
            cout << "One or both nodes not found in the tree" << endl;
        }
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree): ";
        Node* result1 = sol.lca(root1, 1, 2);
        cout << (result1 ? to_string(result1->data) : "NULL") << endl;

        // Test Case 2: Single node tree
        Node* root2 = new Node(1);
        cout << "Test Case 2 (Single node, both values same): ";
        Node* result2 = sol.lca(root2, 1, 1);
        cout << (result2 ? to_string(result2->data) : "NULL") << endl;

        // Test Case 3: Simple tree
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->right = new Node(3);
        cout << "Test Case 3 (Simple tree, nodes in different subtrees): ";
        Node* result3 = sol.lca(root3, 2, 3);
        cout << (result3 ? to_string(result3->data) : "NULL") << endl;

        // Test Case 4: Left-skewed tree
        Node* root4 = new Node(1);
        root4->left = new Node(2);
        root4->left->left = new Node(3);
        cout << "Test Case 4 (Left-skewed tree): ";
        Node* result4 = sol.lca(root4, 2, 3);
        cout << (result4 ? to_string(result4->data) : "NULL") << endl;

        // Test Case 5: Right-skewed tree
        Node* root5 = new Node(1);
        root5->right = new Node(2);
        root5->right->right = new Node(3);
        cout << "Test Case 5 (Right-skewed tree): ";
        Node* result5 = sol.lca(root5, 2, 3);
        cout << (result5 ? to_string(result5->data) : "NULL") << endl;

        // Test Case 6: Complex tree
        Node* root6 = new Node(1);
        root6->left = new Node(2);
        root6->right = new Node(3);
        root6->left->left = new Node(4);
        root6->left->right = new Node(5);
        root6->right->left = new Node(6);
        root6->right->right = new Node(7);
        cout << "Test Case 6 (Complex tree): ";
        Node* result6 = sol.lca(root6, 4, 5);
        cout << (result6 ? to_string(result6->data) : "NULL") << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
