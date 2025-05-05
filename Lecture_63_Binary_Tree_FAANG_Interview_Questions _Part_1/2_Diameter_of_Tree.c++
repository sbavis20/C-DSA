#include <iostream>
#include <algorithm>
#include <queue>
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
    int height(Node* node) {
        // Base case
        if(node == NULL) {
            return 0;
        }

        int left = height(node->left);
        int right = height(node->right);

        return max(left, right) + 1;
    }

    int diameter(Node* root) {
        if(root == NULL) {
            return 0;
        }

        int op1 = diameter(root->left);
        int op2 = diameter(root->right);
        int op3 = height(root->left) + height(root->right) + 1;

        return max(op1, max(op2, op3));
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
        cout << "\nHeight of tree: " << sol.height(root) << endl;
        cout << "Diameter of tree: " << sol.diameter(root) << endl;
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree):" << endl;
        cout << "Height = " << sol.height(root1) << endl;
        cout << "Diameter = " << sol.diameter(root1) << endl;

        // Test Case 2: Single node
        Node* root2 = new Node(1);
        cout << "\nTest Case 2 (Single node):" << endl;
        cout << "Height = " << sol.height(root2) << endl;
        cout << "Diameter = " << sol.diameter(root2) << endl;

        // Test Case 3: Left skewed tree
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->left->left = new Node(3);
        cout << "\nTest Case 3 (Left skewed):" << endl;
        cout << "Height = " << sol.height(root3) << endl;
        cout << "Diameter = " << sol.diameter(root3) << endl;

        // Test Case 4: Right skewed tree
        Node* root4 = new Node(1);
        root4->right = new Node(2);
        root4->right->right = new Node(3);
        cout << "\nTest Case 4 (Right skewed):" << endl;
        cout << "Height = " << sol.height(root4) << endl;
        cout << "Diameter = " << sol.diameter(root4) << endl;

        // Test Case 5: Balanced tree
        Node* root5 = new Node(1);
        root5->left = new Node(2);
        root5->right = new Node(3);
        root5->left->left = new Node(4);
        root5->left->right = new Node(5);
        cout << "\nTest Case 5 (Balanced tree):" << endl;
        cout << "Height = " << sol.height(root5) << endl;
        cout << "Diameter = " << sol.diameter(root5) << endl;

        // Test Case 6: Complex tree
        Node* root6 = new Node(1);
        root6->left = new Node(2);
        root6->right = new Node(3);
        root6->left->left = new Node(4);
        root6->left->right = new Node(5);
        root6->right->right = new Node(6);
        root6->left->right->left = new Node(7);
        root6->left->right->right = new Node(8);
        cout << "\nTest Case 6 (Complex tree):" << endl;
        cout << "Height = " << sol.height(root6) << endl;
        cout << "Diameter = " << sol.diameter(root6) << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
