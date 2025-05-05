#include <iostream>
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
    // Function to check if two trees are identical
    bool isIdentical(Node* r1, Node* r2) {
        // Base cases
        if(r1 == NULL && r2 == NULL) {
            return true;
        }
        if(r1 == NULL || r2 == NULL) {
            return false;
        }

        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        bool value = (r1->data == r2->data);

        return left && right && value;
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
    cout << "1. Enter trees manually\n";
    cout << "2. Run test cases\n";
    cin >> choice;

    if(choice == 1) {
        cout << "\nBuilding first tree:\n";
        Node* root1 = buildTree();
        cout << "\nBuilding second tree:\n";
        Node* root2 = buildTree();

        cout << "\nFirst tree (Inorder): ";
        printTree(root1);
        cout << "\nSecond tree (Inorder): ";
        printTree(root2);

        if(sol.isIdentical(root1, root2)) {
            cout << "\n\nThe trees are identical" << endl;
        } else {
            cout << "\n\nThe trees are not identical" << endl;
        }
    }
    else if(choice == 2) {
        // Test Case 1: Both trees empty
        Node* root1 = NULL;
        Node* root2 = NULL;
        cout << "\nTest Case 1 (Both empty): ";
        cout << (sol.isIdentical(root1, root2) ? "Identical" : "Not identical") << endl;

        // Test Case 2: One empty, one not
        Node* root3 = new Node(1);
        cout << "Test Case 2 (One empty): ";
        cout << (sol.isIdentical(root1, root3) ? "Identical" : "Not identical") << endl;

        // Test Case 3: Identical single nodes
        Node* root4 = new Node(1);
        Node* root5 = new Node(1);
        cout << "Test Case 3 (Identical single nodes): ";
        cout << (sol.isIdentical(root4, root5) ? "Identical" : "Not identical") << endl;

        // Test Case 4: Different single nodes
        Node* root6 = new Node(1);
        Node* root7 = new Node(2);
        cout << "Test Case 4 (Different single nodes): ";
        cout << (sol.isIdentical(root6, root7) ? "Identical" : "Not identical") << endl;

        // Test Case 5: Identical complex trees
        Node* root8 = new Node(1);
        root8->left = new Node(2);
        root8->right = new Node(3);
        root8->left->left = new Node(4);
        Node* root9 = new Node(1);
        root9->left = new Node(2);
        root9->right = new Node(3);
        root9->left->left = new Node(4);
        cout << "Test Case 5 (Identical complex trees): ";
        cout << (sol.isIdentical(root8, root9) ? "Identical" : "Not identical") << endl;

        // Test Case 6: Different complex trees
        Node* root10 = new Node(1);
        root10->left = new Node(2);
        root10->right = new Node(3);
        Node* root11 = new Node(1);
        root11->left = new Node(2);
        root11->left->left = new Node(3);
        cout << "Test Case 6 (Different complex trees): ";
        cout << (sol.isIdentical(root10, root11) ? "Identical" : "Not identical") << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
