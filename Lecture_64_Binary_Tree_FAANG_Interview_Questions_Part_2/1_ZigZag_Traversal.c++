#include <iostream>
#include <vector>
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
    vector<int> zigZagTraversal(Node* root) {
        vector<int> result;
        if(root == NULL) {
            return result;
        }

        queue<Node*> q;
        q.push(root);

        bool leftToRight = true;

        while(!q.empty()) {
            int size = q.size();
            vector<int> ans(size);

            // Level processing
            for(int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();

                // Calculate index based on traversal direction
                int index = leftToRight ? i : size - 1 - i;
                ans[index] = frontNode->data;

                if(frontNode->left) {
                    q.push(frontNode->left);
                }
                if(frontNode->right) {
                    q.push(frontNode->right);
                }
            }

            // Direction change
            leftToRight = !leftToRight;

            // Add current level to result
            for(auto i : ans) {
                result.push_back(i);
            }
        }
        return result;
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
        vector<int> result = sol.zigZagTraversal(root);
        cout << "Zigzag Traversal: ";
        printVector(result);
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree): ";
        printVector(sol.zigZagTraversal(root1));

        // Test Case 2: Single node
        Node* root2 = new Node(1);
        cout << "Test Case 2 (Single node): ";
        printVector(sol.zigZagTraversal(root2));

        // Test Case 3: Complete binary tree
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->right = new Node(3);
        root3->left->left = new Node(4);
        root3->left->right = new Node(5);
        root3->right->left = new Node(6);
        root3->right->right = new Node(7);
        cout << "Test Case 3 (Complete binary tree): ";
        printVector(sol.zigZagTraversal(root3));

        // Test Case 4: Left-skewed tree
        Node* root4 = new Node(1);
        root4->left = new Node(2);
        root4->left->left = new Node(3);
        root4->left->left->left = new Node(4);
        cout << "Test Case 4 (Left-skewed tree): ";
        printVector(sol.zigZagTraversal(root4));

        // Test Case 5: Right-skewed tree
        Node* root5 = new Node(1);
        root5->right = new Node(2);
        root5->right->right = new Node(3);
        root5->right->right->right = new Node(4);
        cout << "Test Case 5 (Right-skewed tree): ";
        printVector(sol.zigZagTraversal(root5));

        // Test Case 6: Complex tree
        Node* root6 = new Node(1);
        root6->left = new Node(2);
        root6->right = new Node(3);
        root6->left->left = new Node(4);
        root6->right->left = new Node(5);
        root6->right->right = new Node(6);
        root6->right->left->left = new Node(7);
        root6->right->left->right = new Node(8);
        cout << "Test Case 6 (Complex tree): ";
        printVector(sol.zigZagTraversal(root6));
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
