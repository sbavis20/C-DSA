#include <iostream>
#include <climits> // for INT_MIN
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
    void solve(Node* root, int sum, int& maxSum, int len, int& maxLen) {
        // Base case
        if(root == NULL) {
            if(len > maxLen) {
                maxLen = len;
                maxSum = sum;
            }
            else if(len == maxLen) {
                maxSum = max(sum, maxSum);
            }
            return;
        }

        sum = sum + root->data;

        solve(root->left, sum, maxSum, len + 1, maxLen);  // Fixed: changed len-1 to len+1
        solve(root->right, sum, maxSum, len + 1, maxLen);  // Fixed: changed len-1 to len+1
    }

    int sumOfLongRootToLeafPath(Node* root) {
        int len = 0;
        int maxLen = 0;
        int sum = 0;
        int maxSum = INT_MIN;

        solve(root, sum, maxSum, len, maxLen);

        return maxSum;
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
    cout << "1. Enter tree manually\n";
    cout << "2. Run test cases\n";
    cin >> choice;

    if(choice == 1) {
        Node* root = buildTree();
        int result = sol.sumOfLongRootToLeafPath(root);
        cout << "Sum of longest root-to-leaf path: " << result << endl;
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree): ";
        cout << sol.sumOfLongRootToLeafPath(root1) << endl;

        // Test Case 2: Single node
        Node* root2 = new Node(5);
        cout << "Test Case 2 (Single node): ";
        cout << sol.sumOfLongRootToLeafPath(root2) << endl;

        // Test Case 3: Left-skewed tree
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->left->left = new Node(3);
        cout << "Test Case 3 (Left-skewed tree): ";
        cout << sol.sumOfLongRootToLeafPath(root3) << endl;

        // Test Case 4: Right-skewed tree
        Node* root4 = new Node(1);
        root4->right = new Node(2);
        root4->right->right = new Node(3);
        cout << "Test Case 4 (Right-skewed tree): ";
        cout << sol.sumOfLongRootToLeafPath(root4) << endl;

        // Test Case 5: Complete binary tree
        Node* root5 = new Node(1);
        root5->left = new Node(2);
        root5->right = new Node(3);
        root5->left->left = new Node(4);
        root5->left->right = new Node(5);
        root5->right->left = new Node(6);
        root5->right->right = new Node(7);
        cout << "Test Case 5 (Complete binary tree): ";
        cout << sol.sumOfLongRootToLeafPath(root5) << endl;

        // Test Case 6: Complex tree with multiple paths
        Node* root6 = new Node(4);
        root6->left = new Node(2);
        root6->right = new Node(5);
        root6->left->left = new Node(7);
        root6->left->right = new Node(1);
        root6->right->left = new Node(2);
        root6->left->right->left = new Node(6);
        cout << "Test Case 6 (Complex tree): ";
        cout << sol.sumOfLongRootToLeafPath(root6) << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
