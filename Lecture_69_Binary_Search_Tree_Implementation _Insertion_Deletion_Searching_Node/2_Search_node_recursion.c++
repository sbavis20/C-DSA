#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool searchInBST(BinaryTreeNode<int>* root, int x) {
    // Base case
    if(root == NULL) {
        return false;
    }

    if(root->data == x) {
        return true;
    }

    if(root->data > x) {
        return searchInBST(root->left, x);
    } else {
        return searchInBST(root->right, x);
    }
}

// Function to insert nodes into BST
BinaryTreeNode<int>* insertIntoBST(BinaryTreeNode<int>* root, int data) {
    if(root == NULL) {
        return new BinaryTreeNode<int>(data);
    }

    if(data <= root->data) {
        root->left = insertIntoBST(root->left, data);
    } else {
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

// Function to create BST from user input
BinaryTreeNode<int>* takeInput() {
    int data;
    BinaryTreeNode<int>* root = NULL;

    cout << "Enter data (enter -1 to stop): ";
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter next data (or -1 to stop): ";
        cin >> data;
    }
    return root;
}

int main() {
    // Create BST
    BinaryTreeNode<int>* root = takeInput();

    int searchValue;
    cout << "\nEnter value to search in BST: ";
    cin >> searchValue;

    // Search for value
    if(searchInBST(root, searchValue)) {
        cout << searchValue << " is present in the BST." << endl;
    } else {
        cout << searchValue << " is not present in the BST." << endl;
    }

    // Test cases
    cout << "\nRunning test cases:\n";

    // Test Case 1: Value present in BST
    BinaryTreeNode<int>* testRoot1 = new BinaryTreeNode<int>(5);
    testRoot1->left = new BinaryTreeNode<int>(3);
    testRoot1->right = new BinaryTreeNode<int>(7);
    cout << "Test Case 1 (Search 3): "
         << (searchInBST(testRoot1, 3) ? "Found" : "Not Found") << endl;

    // Test Case 2: Value not present in BST
    cout << "Test Case 2 (Search 10): "
         << (searchInBST(testRoot1, 10) ? "Found" : "Not Found") << endl;

    // Test Case 3: Empty tree
    BinaryTreeNode<int>* testRoot2 = NULL;
    cout << "Test Case 3 (Search 5 in empty tree): "
         << (searchInBST(testRoot2, 5) ? "Found" : "Not Found") << endl;

    // Test Case 4: Value at root
    cout << "Test Case 4 (Search 5 at root): "
         << (searchInBST(testRoot1, 5) ? "Found" : "Not Found") << endl;

    return 0;
}
