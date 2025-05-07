#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Binary Tree Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Step 1: Create parent mapping and find target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*>& nodeToParent) {
        Node* res = NULL;
        queue<Node*> q;
        q.push(root);
        nodeToParent[root] = NULL;

        while (!q.empty()) {
            Node* front = q.front();
            q.pop();

            if (front->data == target) {
                res = front;
            }

            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }

            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }

    // Step 2: Burn the tree from the target node
    int burnTree(Node* root, map<Node*, Node*>& nodeToParent) {
        map<Node*, bool> visited;
        queue<Node*> q;
        q.push(root);
        visited[root] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                Node* front = q.front();
                q.pop();

                if (front->left && !visited[front->left]) {
                    flag = true;
                    q.push(front->left);
                    visited[front->left] = true;
                }

                if (front->right && !visited[front->right]) {
                    flag = true;
                    q.push(front->right);
                    visited[front->right] = true;
                }

                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = true;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = true;
                }
            }

            if (flag) time++;
        }

        return time;
    }

    // Step 3: Combine both to get the answer
    int minTime(Node* root, int target) {
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        return burnTree(targetNode, nodeToParent);
    }
};

// Helper to build a sample tree for testing
Node* buildTestTree() {
    /*
             1
            / \
           2   3
          / \   \
         4   5   6
                /
               7
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);
    return root;
}

int main() {
    Node* root = buildTestTree();
    Solution sol;
    int target = 5;
    int result = sol.minTime(root, target);
    cout << "Minimum time to burn the tree from target " << target << " is: " << result << endl;
    return 0;
}
