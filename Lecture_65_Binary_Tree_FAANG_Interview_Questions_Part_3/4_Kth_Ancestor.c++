#include <iostream>
#include <climits> // for INT_MAX
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
    Node* solve(Node* root, int &k, int node) {
        // Base case
        if(root == NULL) {
            return NULL;
        }

        // If current node is the target node
        if(root->data == node) {
            return root;
        }

        Node* leftAns = solve(root->left, k, node);
        Node* rightAns = solve(root->right, k, node);

        // If target node found in left subtree
        if(leftAns != NULL && rightAns == NULL) {
            k--;
            if(k <= 0) {
                // Lock the answer by setting k to maximum value
                k = INT_MAX;
                return root;
            }
            return leftAns;
        }

        // If target node found in right subtree
        if(leftAns == NULL && rightAns != NULL) {
            k--;
            if(k <= 0) {
                // Lock the answer by setting k to maximum value
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }

        // If target node not found in either subtree
        return NULL;
    }

    int kthAncestor(Node* root, int k, int node) {
        Node* ans = solve(root, k, node);

        // If no ancestor found or the found node is the target itself
        if(ans == NULL || ans->data == node) {
            return -1;
        }
        else {
            return ans->data;
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
    cout << "1. Enter tree and values manually\n";
    cout << "2. Run test cases\n";
    cin >> choice;

    if(choice == 1) {
        Node* root = buildTree();
        int k, node;
        cout << "Enter k (ancestor level): ";
        cin >> k;
        cout << "Enter node value: ";
        cin >> node;

        int result = sol.kthAncestor(root, k, node);
        if(result != -1) {
            cout << k << "th ancestor of " << node << " is: " << result << endl;
        } else {
            cout << "No " << k << "th ancestor exists for node " << node << endl;
        }
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree): ";
        cout << sol.kthAncestor(root1, 1, 1) << endl;

        // Test Case 2: Single node tree
        Node* root2 = new Node(5);
        cout << "Test Case 2 (Single node, k=1, node=5): ";
        cout << sol.kthAncestor(root2, 1, 5) << endl;

        // Test Case 3: Simple tree with 1st ancestor
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->left->left = new Node(3);
        cout << "Test Case 3 (k=1, node=3): ";
        cout << sol.kthAncestor(root3, 1, 3) << endl;

        // Test Case 4: Simple tree with 2nd ancestor
        Node* root4 = new Node(1);
        root4->left = new Node(2);
        root4->left->left = new Node(3);
        root4->left->left->left = new Node(4);
        cout << "Test Case 4 (k=2, node=4): ";
        cout << sol.kthAncestor(root4, 2, 4) << endl;

        // Test Case 5: No ancestor exists (k too large)
        Node* root5 = new Node(1);
        root5->left = new Node(2);
        root5->right = new Node(3);
        cout << "Test Case 5 (k=3, node=2): ";
        cout << sol.kthAncestor(root5, 3, 2) << endl;

        // Test Case 6: Complex tree
        Node* root6 = new Node(1);
        root6->left = new Node(2);
        root6->right = new Node(3);
        root6->left->left = new Node(4);
        root6->left->right = new Node(5);
        root6->right->left = new Node(6);
        root6->right->right = new Node(7);
        root6->left->right->left = new Node(8);
        cout << "Test Case 6 (k=2, node=8): ";
        cout << sol.kthAncestor(root6, 2, 8) << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
