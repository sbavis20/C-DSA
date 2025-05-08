#include <iostream>
#include <queue>
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

// Function to insert a node into BST
Node* insertIntoBST(Node* root, int d) {
    // Base case
    if(root == NULL) {
        root = new Node(d);
        return root;
    }

    if(d > root->data) {
        // Insert in right subtree
        root->right = insertIntoBST(root->right, d);
    }
    else {
        // Insert in left subtree
        root->left = insertIntoBST(root->left, d);
    }

    return root;
}

// Function to take input and build BST
void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

// Function for level order traversal (BFS)
void levelOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";

            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

// Function for inorder traversal (DFS)
void inorder(Node* root) {
    if(root == NULL) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to find minimum value in BST
int minValue(Node* root) {
    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

// Function to find maximum value in BST
int maxValue(Node* root) {
    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}

int main() {
    Node* root = NULL;

    cout << "Enter data to create BST (enter -1 to stop): ";
    takeInput(root);

    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);

    cout << "\nInorder Traversal (sorted order): ";
    inorder(root);

    cout << "\n\nMinimum value in BST: " << minValue(root);
    cout << "\nMaximum value in BST: " << maxValue(root) << endl;

    return 0;
}
