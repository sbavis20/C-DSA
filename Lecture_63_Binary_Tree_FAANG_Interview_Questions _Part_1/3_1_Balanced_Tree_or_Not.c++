#include <iostream>
#include <algorithm>
#include <queue>
#include <utility> // for pair
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
    // Optimized function to check if tree is balanced and return height
    pair<bool,int> isBalancedFast(Node* root) {
        // Base case
        if(root == NULL) {
            return make_pair(true, 0);
        }

        pair<bool,int> left = isBalancedFast(root->left);
        pair<bool,int> right = isBalancedFast(root->right);

        bool leftBalanced = left.first;
        bool rightBalanced = right.first;
        bool heightDiff = abs(left.second - right.second) <= 1;

        pair<bool,int> ans;
        ans.first = leftBalanced && rightBalanced && heightDiff;
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    // Wrapper function
    bool isBalanced(Node* root) {
        return isBalancedFast(root).first;
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
        cout << (sol.isBalanced(root1) ? "Balanced" : "Not balanced") << endl;

        // Test Case 2: Single node
        Node* root2 = new Node(1);
        cout << "Test Case 2 (Single node): ";
        cout << (sol.isBalanced(root2) ? "Balanced" : "Not balanced") << endl;

        // Test Case 3: Balanced tree
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->right = new Node(3);
        cout << "Test Case 3 (Balanced tree): ";
        cout << (sol.isBalanced(root3) ? "Balanced" : "Not balanced") << endl;

        // Test Case 4: Unbalanced tree (left skewed)
        Node* root4 = new Node(1);
        root4->left = new Node(2);
        root4->left->left = new Node(3);
        cout << "Test Case 4 (Left skewed tree): ";
        cout << (sol.isBalanced(root4) ? "Balanced" : "Not balanced") << endl;

        // Test Case 5: Unbalanced tree (right skewed)
        Node* root5 = new Node(1);
        root5->right = new Node(2);
        root5->right->right = new Node(3);
        cout << "Test Case 5 (Right skewed tree): ";
        cout << (sol.isBalanced(root5) ? "Balanced" : "Not balanced") << endl;

        // Test Case 6: Complex balanced tree
        Node* root6 = new Node(1);
        root6->left = new Node(2);
        root6->right = new Node(3);
        root6->left->left = new Node(4);
        root6->left->right = new Node(5);
        root6->right->left = new Node(6);
        cout << "Test Case 6 (Complex balanced tree): ";
        cout << (sol.isBalanced(root6) ? "Balanced" : "Not balanced") << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
