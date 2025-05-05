#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

        node(int d){
            this->data = d;
            this->left = NULL;
            this->right = NULL;
        }
};


// Function to build tree interactively
node* buildTree(node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter data for inserting left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

// Function to create tree from array (for test cases)
node* buildTreeFromArray(int arr[], int& index, int size){
    if(index >= size || arr[index] == -1){
        index++;
        return NULL;
    }

    node* root = new node(arr[index++]);
    root->left = buildTreeFromArray(arr, index, size);
    root->right = buildTreeFromArray(arr, index, size);
    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){  // Fixed: changed = to ==
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void preorder(node* root){
    //base case
    if(root==NULL){
        return ;
    }
    cout<<root-> data<<" ";
    preorder(root->left);

    preorder(root-> right);
}

int main(){
    node* root = NULL;
    int choice;

    cout << "Choose input method:\n";
    cout << "1. Interactive input\n";
    cout << "2. Predefined test cases\n";
    cin >> choice;

    if(choice == 1){
        // Interactive tree building
        cout << "Enter -1 for NULL nodes\n";
        root = buildTree(root);
    }
    else if(choice == 2){
        // Predefined test cases
        int testCase;
        cout << "Choose test case:\n";
        cout << "1. Simple binary tree\n";
        cout << "2. Left-skewed tree\n";
        cout << "3. Right-skewed tree\n";
        cout << "4. Complete binary tree\n";
        cin >> testCase;

        int index = 0;
        switch(testCase){
            case 1: {
                // Simple binary tree: 1 2 4 -1 -1 5 -1 -1 3 -1 6 -1 -1
                int arr[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
                root = buildTreeFromArray(arr, index, sizeof(arr)/sizeof(arr[0]));
                break;
            }
            case 2: {
                // Left-skewed tree: 1 2 3 4 -1 -1 -1 -1 -1
                int arr[] = {1, 2, 3, 4, -1, -1, -1, -1, -1};
                root = buildTreeFromArray(arr, index, sizeof(arr)/sizeof(arr[0]));
                break;
            }
            case 3: {
                // Right-skewed tree: 1 -1 2 -1 3 -1 4 -1 -1
                int arr[] = {1, -1, 2, -1, 3, -1, 4, -1, -1};
                root = buildTreeFromArray(arr, index, sizeof(arr)/sizeof(arr[0]));
                break;
            }
            case 4: {
                // Complete binary tree: 1 2 4 -1 -1 5 -1 -1 3 6 -1 -1 7 -1 -1
                int arr[] = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
                root = buildTreeFromArray(arr, index, sizeof(arr)/sizeof(arr[0]));
                break;
            }
            default:
                cout << "Invalid choice\n";
                return 0;
        }
    }
    else{
        cout << "Invalid choice\n";
        return 0;
    }

    cout << "\nPreorder:\n";
    preorder(root);

    return 0;
}
