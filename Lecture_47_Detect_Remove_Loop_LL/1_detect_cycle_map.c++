#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    //contructor
    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};

void insertAtHead(Node* &head,int d){
    //new node create
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;

}



bool detectCycle(Node* head){
    if(head==NULL){
        return false;
    }

    map<Node*,bool> visited;

    Node* temp=head;

    while(temp!=NULL){
        //cycle is present
        if(visited[temp]==true){
            return 1;
        }

        visited[temp]=true;
        temp =temp -> next;
    }

    return false;
}

void print(Node* &tail){
    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
}

int main(){
    //Singly LL
    // Node* node1 = new Node(10);
    // Node* head =node1;

    // insertAtHead(head,22);
    // insertAtHead(head,33);
    // insertAtHead(head,44);
    // insertAtHead(head,55);

    // print(head);

    //Circular LL
     // Create nodes
     Node* node1 = new Node(10);
     Node* head = node1;
     Node* tail = node1;

     // Insert elements at head
     insertAtHead(head, 22);
     insertAtHead(head, 33);
     insertAtHead(head, 44);
     insertAtHead(head, 55);

     cout << "Before making circular:" << endl;
     cout << "head " << head->data << endl;
     cout << "tail " << tail->data << endl;

     // Make the list circular by connecting tail to head
     tail->next = head;

     // Now the list is circular
     cout << "\nAfter making circular:" << endl;


    bool ans = detectCycle(tail);

    if(ans){
        cout<<"Cycle Present"<<endl;
    }else{
        cout<<"No Cycle Detetcted"<<endl;
    }

    return 0;
}
