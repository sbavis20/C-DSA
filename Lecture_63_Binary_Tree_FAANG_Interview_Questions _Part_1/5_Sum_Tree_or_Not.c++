#include <iostream>
#include <queue>
#include <utility> // for pair
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
    // Function to check if tree is Sum Tree and return sum
    pair<bool,int> isSumTree(Node* root) {
        // Base case 1: NULL node
        if(root == NULL) {
            return make_pair(true, 0);
        }

        // Base case 2: Leaf node
        if(root->left == NULL && root->right == NULL) {
            return make_pair(true, root->data);
        }

        // Recursive calls for left and right subtrees
        pair<bool,int> leftAns = isSumTree(root->left);
        pair<bool,int> rightAns = isSumTree(root->right);

        bool isLeftSumTree = leftAns.first;
        bool isRightSumTree = rightAns.first;

        // Check if current node satisfies Sum Tree condition
        bool condn = (root->data == leftAns.second + rightAns.second);

        pair<bool,int> ans;

        if(isLeftSumTree && isRightSumTree && condn) {
            ans.first = true;
            ans.second = 2 * root->data; // or root->data + leftAns.second + rightAns.second
        }
        else {
            ans.first = false;
            // The sum value doesn't matter if it's not a Sum Tree
            ans.second = 0;
        }

        return ans;
    }

    // Wrapper function
    bool isSumTreeWrapper(Node* root) {
        return isSumTree(root).first;
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
        if(sol.isSumTreeWrapper(root)) {
            cout << "\nThe tree is a Sum Tree" << endl;
        } else {
            cout << "\nThe tree is not a Sum Tree" << endl;
        }
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree): ";
        cout << (sol.isSumTreeWrapper(root1) ? "Sum Tree" : "Not Sum Tree") << endl;

        // Test Case 2: Single node (always Sum Tree)
        Node* root2 = new Node(5);
        cout << "Test Case 2 (Single node): ";
        cout << (sol.isSumTreeWrapper(root2) ? "Sum Tree" : "Not Sum Tree") << endl;

        // Test Case 3: Simple Sum Tree
        Node* root3 = new Node(10);
        root3->left = new Node(4);
        root3->right = new Node(6);
        cout << "Test Case 3 (Simple Sum Tree): ";
        cout << (sol.isSumTreeWrapper(root3) ? "Sum Tree" : "Not Sum Tree") << endl;

        // Test Case 4: Not a Sum Tree
        Node* root4 = new Node(10);
        root4->left = new Node(5);
        root4->right = new Node(6);
        cout << "Test Case 4 (Not a Sum Tree): ";
        cout << (sol.isSumTreeWrapper(root4) ? "Sum Tree" : "Not Sum Tree") << endl;

        // Test Case 5: Complex Sum Tree
        Node* root5 = new Node(26);
        root5->left = new Node(10);
        root5->right = new Node(3);
        root5->left->left = new Node(4);
        root5->left->right = new Node(6);
        root5->right->right = new Node(3);
        cout << "Test Case 5 (Complex Sum Tree): ";
        cout << (sol.isSumTreeWrapper(root5) ? "Sum Tree" : "Not Sum Tree") << endl;

        // Test Case 6: Complex Not Sum Tree
        Node* root6 = new Node(26);
        root6->left = new Node(10);
        root6->right = new Node(3);
        root6->left->left = new Node(4);
        root6->left->right = new Node(6);
        root6->right->right = new Node(4); // Changed from 3 to make it invalid
        cout << "Test Case 6 (Complex Not Sum Tree): ";
        cout << (sol.isSumTreeWrapper(root6) ? "Sum Tree" : "Not Sum Tree") << endl;
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
