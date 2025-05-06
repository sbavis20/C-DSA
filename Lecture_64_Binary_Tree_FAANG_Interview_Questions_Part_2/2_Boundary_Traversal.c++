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
    // Traverse left boundary (excluding leaves)
    void traverseLeft(Node* root, vector<int>& ans) {
        if((root == NULL) || (root->left == NULL && root->right == NULL)) {
            return;
        }
        ans.push_back(root->data);
        if(root->left) {
            traverseLeft(root->left, ans);
        }
        else {
            traverseLeft(root->right, ans);
        }
    }

    // Traverse all leaf nodes
    void traverseLeaf(Node* root, vector<int>& ans) {
        if(root == NULL) {
            return;
        }
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }

    // Traverse right boundary (excluding leaves) in reverse
    void traverseRight(Node* root, vector<int>& ans) {
        if((root == NULL) || (root->left == NULL && root->right == NULL)) {
            return;
        }
        if(root->right) {
            traverseRight(root->right, ans);
        }
        else {
            traverseRight(root->left, ans);
        }
        ans.push_back(root->data);
    }

    vector<int> boundary(Node* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return ans;
        }

        ans.push_back(root->data);

        // Traverse left boundary
        traverseLeft(root->left, ans);

        // Traverse leaf nodes
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);

        // Traverse right boundary in reverse
        traverseRight(root->right, ans);

        return ans;
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

// Function to print a vector
void printVector(vector<int> v) {
    for(int i : v) {
        cout << i << " ";
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
        vector<int> result = sol.boundary(root);
        cout << "Boundary Traversal: ";
        printVector(result);
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree): ";
        printVector(sol.boundary(root1));

        // Test Case 2: Single node
        Node* root2 = new Node(1);
        cout << "Test Case 2 (Single node): ";
        printVector(sol.boundary(root2));

        // Test Case 3: Left-skewed tree
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->left->left = new Node(3);
        cout << "Test Case 3 (Left-skewed tree): ";
        printVector(sol.boundary(root3));

        // Test Case 4: Right-skewed tree
        Node* root4 = new Node(1);
        root4->right = new Node(2);
        root4->right->right = new Node(3);
        cout << "Test Case 4 (Right-skewed tree): ";
        printVector(sol.boundary(root4));

        // Test Case 5: Complete binary tree
        Node* root5 = new Node(1);
        root5->left = new Node(2);
        root5->right = new Node(3);
        root5->left->left = new Node(4);
        root5->left->right = new Node(5);
        root5->right->left = new Node(6);
        root5->right->right = new Node(7);
        cout << "Test Case 5 (Complete binary tree): ";
        printVector(sol.boundary(root5));

        // Test Case 6: Complex tree
        Node* root6 = new Node(1);
        root6->left = new Node(2);
        root6->right = new Node(3);
        root6->left->right = new Node(4);
        root6->left->right->left = new Node(5);
        root6->left->right->right = new Node(6);
        root6->right->right = new Node(7);
        cout << "Test Case 6 (Complex tree): ";
        printVector(sol.boundary(root6));
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
