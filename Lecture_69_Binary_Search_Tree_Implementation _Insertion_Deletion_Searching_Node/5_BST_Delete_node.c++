#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Helper function to find minimum value node
Node* minValueNode(Node* node) {
    Node* current = node;
    while(current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from BST
Node* deleteFromBST(Node* root, int val) {
    // Base case
    if(root == NULL) {
        return root;
    }

    if(root->data == val) {
        // Node with only one child or no child
        if(root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteFromBST(root->right, temp->data);
    }
    else if(root->data > val) {
        root->left = deleteFromBST(root->left, val);
    }
    else {
        root->right = deleteFromBST(root->right, val);
    }

    return root;
}

// Function to insert nodes into BST
Node* insertIntoBST(Node* root, int data) {
    if(root == NULL) {
        return new Node(data);
    }

    if(data <= root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

// Function to create BST from user input
Node* takeInput() {
    int data;
    Node* root = NULL;

    cout << "Enter data (enter -1 to stop): ";
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter next data (or -1 to stop): ";
        cin >> data;
    }
    return root;
}

// Function for inorder traversal (prints BST in sorted order)
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Create BST
    Node* root = takeInput();

    cout << "\nBST before deletion (inorder): ";
    inorder(root);

    int deleteValue;
    cout << "\n\nEnter value to delete from BST: ";
    cin >> deleteValue;

    // Delete node
    root = deleteFromBST(root, deleteValue);

    cout << "\nBST after deletion (inorder): ";
    inorder(root);

    // Test cases
    cout << "\n\nRunning test cases:\n";

    // Test Case 1: Delete leaf node
    Node* testRoot1 = new Node(50);
    testRoot1->left = new Node(30);
    testRoot1->right = new Node(70);
    testRoot1->left->left = new Node(20);
    testRoot1->left->right = new Node(40);
    testRoot1->right->left = new Node(60);
    testRoot1->right->right = new Node(80);

    cout << "\nTest Case 1 (Delete leaf 20):\n";
    cout << "Before: "; inorder(testRoot1);
    testRoot1 = deleteFromBST(testRoot1, 20);
    cout << "\nAfter: "; inorder(testRoot1);

    // Test Case 2: Delete node with one child
    cout << "\n\nTest Case 2 (Delete node 70 with one child):\n";
    cout << "Before: "; inorder(testRoot1);
    testRoot1 = deleteFromBST(testRoot1, 70);
    cout << "\nAfter: "; inorder(testRoot1);

    // Test Case 3: Delete node with two children
    cout << "\n\nTest Case 3 (Delete node 30 with two children):\n";
    cout << "Before: "; inorder(testRoot1);
    testRoot1 = deleteFromBST(testRoot1, 30);
    cout << "\nAfter: "; inorder(testRoot1);

    // Test Case 4: Delete root node
    cout << "\n\nTest Case 4 (Delete root node 50):\n";
    cout << "Before: "; inorder(testRoot1);
    testRoot1 = deleteFromBST(testRoot1, 50);
    cout << "\nAfter: "; inorder(testRoot1);

    // Test Case 5: Delete non-existent node
    cout << "\n\nTest Case 5 (Delete non-existent node 100):\n";
    cout << "Before: "; inorder(testRoot1);
    testRoot1 = deleteFromBST(testRoot1, 100);
    cout << "\nAfter: "; inorder(testRoot1);

    return 0;
}
