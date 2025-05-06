#include <iostream>
#include <vector>
#include <queue>
#include <map>
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
    vector<int> topView(Node* root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }

        map<int, int> topNode;
        queue<pair<Node*, int>> q;

        q.push(make_pair(root, 0));

        while(!q.empty()) {
            pair<Node*, int> temp = q.front();
            q.pop();

            Node* frontNode = temp.first;
            int hd = temp.second;

             topNode[hd] = frontNode->data;


            if(frontNode->left) {
                q.push(make_pair(frontNode->left, hd-1));
            }

            if(frontNode->right) {
                q.push(make_pair(frontNode->right, hd+1));  // Fixed: changed hd-1 to hd+1
            }
        }

        // Store the results in order of increasing horizontal distance
        for(auto i : topNode) {
            ans.push_back(i.second);
        }

        return ans;
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
        vector<int> result = sol.topView(root);
        cout << "Top View: ";
        printVector(result);
    }
    else if(choice == 2) {
        // Test Case 1: Empty tree
        Node* root1 = NULL;
        cout << "\nTest Case 1 (Empty tree): ";
        printVector(sol.topView(root1));

        // Test Case 2: Single node
        Node* root2 = new Node(1);
        cout << "Test Case 2 (Single node): ";
        printVector(sol.topView(root2));

        // Test Case 3: Left-skewed tree
        Node* root3 = new Node(1);
        root3->left = new Node(2);
        root3->left->left = new Node(3);
        cout << "Test Case 3 (Left-skewed tree): ";
        printVector(sol.topView(root3));

        // Test Case 4: Right-skewed tree
        Node* root4 = new Node(1);
        root4->right = new Node(2);
        root4->right->right = new Node(3);
        cout << "Test Case 4 (Right-skewed tree): ";
        printVector(sol.topView(root4));

        // Test Case 5: Complete binary tree
        Node* root5 = new Node(1);
        root5->left = new Node(2);
        root5->right = new Node(3);
        root5->left->left = new Node(4);
        root5->left->right = new Node(5);
        root5->right->left = new Node(6);
        root5->right->right = new Node(7);
        cout << "Test Case 5 (Complete binary tree): ";
        printVector(sol.topView(root5));

        // Test Case 6: Complex tree
        Node* root6 = new Node(1);
        root6->left = new Node(2);
        root6->right = new Node(3);
        root6->left->right = new Node(4);
        root6->left->right->right = new Node(5);
        root6->right->left = new Node(6);
        cout << "Test Case 6 (Complex tree): ";
        printVector(sol.topView(root6));
    }
    else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
