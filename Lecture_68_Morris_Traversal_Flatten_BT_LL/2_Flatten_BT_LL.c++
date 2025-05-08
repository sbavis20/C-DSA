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
    void flatten(Node* root) {
        Node* curr = root;
        while(curr != NULL) {
            if(curr->left) {
                // Find the rightmost node in left subtree
                Node* pred = curr->left;
                while(pred->right) {
                    pred = pred->right;
                }

                // Rewire connections
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;  // Set left pointer to NULL
            }
            curr = curr->right;
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

// Function to print the flattened tree (linked list)
void printFlattened(Node* root) {
    Node* curr = root;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
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
        sol.flatten(root);
        cout << "Flattened tree: ";
        printFlattened(root);
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree): ";
        sol.flatten(root1);
        printFlattened(root1);

        // Test Case 2: Single node tree
        Node* root2 = new Node(1);
        cout << "Test Case 2 (Single node): ";
        sol.flatten(root2);
        printFlattened(root2);

        // Test Case 3: Left-skewed tree
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->left->left = new Node(3);
        cout << "Test Case 3 (Left-skewed tree): ";
        sol.flatten(root3);
        printFlattened(root3);

        // Test Case 4: Right-skewed tree
        Node* root4 = new Node(1);
        root4->right = new Node(2);
        root4->right->right = new Node(3);
        cout << "Test Case 4 (Right-skewed tree): ";
        sol.flatten(root4);
        printFlattened(root4);

        // Test Case 5: Balanced tree
        Node* root5 = new Node(1);
        root5->left = new Node(2);
        root5->right = new Node(5);
        root5->left->left = new Node(3);
        root5->left->right = new Node(4);
        root5->right->right = new Node(6);
        cout << "Test Case 5 (Balanced tree): ";
        sol.flatten(root5);
        printFlattened(root5);

        // Test Case 6: Complex tree
        Node* root6 = new Node(1);
        root6->left = new Node(2);
        root6->right = new Node(3);
        root6->left->left = new Node(4);
        root6->left->right = new Node(5);
        root6->right->left = new Node(6);
        root6->left->right->left = new Node(7);
        cout << "Test Case 6 (Complex tree): ";
        sol.flatten(root6);
        printFlattened(root6);
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
