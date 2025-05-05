#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

BinaryTreeNode<int>* buildTreeLevelWise() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty()) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            front->left = leftNode;
            pendingNodes.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            front->right = rightNode;
            pendingNodes.push(rightNode);
        }
    }
    return root;
}

void inorder(BinaryTreeNode<int>* root, int &count) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, count);
    if (root->left == NULL && root->right == NULL) {
        count++;
    }
    inorder(root->right, count);
}

int noOfLeafNodes(BinaryTreeNode<int>* root) {
    int cnt = 0;
    inorder(root, cnt);
    return cnt;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        BinaryTreeNode<int>* root = buildTreeLevelWise();
        cout << noOfLeafNodes(root) << endl;
    }

    return 0;
}
