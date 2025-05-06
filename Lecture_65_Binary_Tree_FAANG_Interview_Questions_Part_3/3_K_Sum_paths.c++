#include <iostream>
#include <vector>
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
    void solve(Node* root, int k, int &count, vector<int> path) {
        // Base case
        if(root == NULL) {
            return;
        }

        // Add current node's data to path
        path.push_back(root->data);

        // Recursively check left and right subtrees
        solve(root->left, k, count, path);
        solve(root->right, k, count, path);

        // Check all paths ending at current node
        int sum = 0;
        for(int i = path.size()-1; i >= 0; i--) {
            sum += path[i];
            if(sum == k) {
                count++;
            }
        }

        // Backtrack: remove current node from path
        path.pop_back();
    }

    int sumK(Node* root, int k) {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
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
    cout << "1. Enter tree and k value manually\n";
    cout << "2. Run test cases\n";
    cin >> choice;

    if(choice == 1) {
        Node* root = buildTree();
        int k;
        cout << "Enter target sum k: ";
        cin >> k;

        int result = sol.sumK(root, k);
        cout << "Number of paths with sum " << k << ": " << result << endl;
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree): ";
        cout << sol.sumK(root1, 5) << endl;

        // Test Case 2: Single node tree
        Node* root2 = new Node(5);
        cout << "Test Case 2 (Single node, k=5): ";
        cout << sol.sumK(root2, 5) << endl;

        // Test Case 3: Simple tree with one path
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->left->left = new Node(3);
        cout << "Test Case 3 (Simple tree, k=6): ";
        cout << sol.sumK(root3, 6) << endl;

        // Test Case 4: Multiple paths
        Node* root4 = new Node(1);
        root4->left = new Node(3);
        root4->right = new Node(-1);
        root4->left->left = new Node(2);
        root4->left->right = new Node(1);
        root4->right->left = new Node(4);
        root4->right->right = new Node(5);
        root4->left->right->left = new Node(1);
        root4->right->left->left = new Node(1);
        root4->right->left->right = new Node(2);
        root4->right->right->right = new Node(6);
        cout << "Test Case 4 (Complex tree, k=5): ";
        cout << sol.sumK(root4, 5) << endl;

        // Test Case 5: No paths match
        Node* root5 = new Node(1);
        root5->left = new Node(2);
        root5->right = new Node(3);
        cout << "Test Case 5 (No matching paths, k=10): ";
        cout << sol.sumK(root5, 10) << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
