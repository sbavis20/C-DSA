#include <iostream>
#include <algorithm> // for max function
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
    pair<int, int> solve(Node* root) {
        // Base case: if root is NULL, return pair of 0s
        if(root == NULL) {
            return make_pair(0, 0);
        }

        // Recursively solve for left and right subtrees
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);

        pair<int, int> res;

        // res.first represents maximum sum including current node
        res.first = root->data + left.second + right.second;

        // res.second represents maximum sum excluding current node
        res.second = max(left.first, left.second) + max(right.first, right.second);

        return res;
    }

    int getMaxSum(Node* root) {
        pair<int, int> ans = solve(root);
        return max(ans.first, ans.second);
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
        int result = sol.getMaxSum(root);
        cout << "Maximum sum of non-adjacent nodes: " << result << endl;
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree): ";
        cout << sol.getMaxSum(root1) << endl;

        // Test Case 2: Single node tree
        Node* root2 = new Node(5);
        cout << "Test Case 2 (Single node): ";
        cout << sol.getMaxSum(root2) << endl;

        // Test Case 3: Simple tree with 3 nodes
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->right = new Node(3);
        cout << "Test Case 3 (Simple tree): ";
        cout << sol.getMaxSum(root3) << endl;

        // Test Case 4: Tree with optimal sum excluding root
        Node* root4 = new Node(10);
        root4->left = new Node(1);
        root4->right = new Node(2);
        root4->left->left = new Node(3);
        root4->left->right = new Node(4);
        root4->right->left = new Node(5);
        root4->right->right = new Node(6);
        cout << "Test Case 4 (Complex tree 1): ";
        cout << sol.getMaxSum(root4) << endl;

        // Test Case 5: Tree with optimal sum including root
        Node* root5 = new Node(10);
        root5->left = new Node(1);
        root5->right = new Node(2);
        root5->left->left = new Node(10);
        root5->left->right = new Node(10);
        cout << "Test Case 5 (Complex tree 2): ";
        cout << sol.getMaxSum(root5) << endl;

        // Test Case 6: Large tree
        Node* root6 = new Node(1);
        root6->left = new Node(2);
        root6->right = new Node(3);
        root6->left->left = new Node(1);
        root6->right->left = new Node(4);
        root6->right->right = new Node(5);
        cout << "Test Case 6 (Large tree): ";
        cout << sol.getMaxSum(root6) << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
