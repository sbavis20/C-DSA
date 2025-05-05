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

void postorder(node* root){
    //base case
    if(root==NULL){
        return ;
    }

    postorder(root->left);

    postorder(root-> right);

    cout<<root-> data<<" ";
}

void buildfromLevelOrder(node*&root){
    queue<node*> q;
    q.push(root);
    cout<<"Enter data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right node for: "<<temp-> data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right = new node(rightData);
            q.push(temp->right);

        }
    }
}

int main(){
    node* root = NULL;
   buildfromLevelOrder(root);
    return 0;
}
