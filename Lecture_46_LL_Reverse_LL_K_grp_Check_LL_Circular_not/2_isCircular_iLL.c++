#include<iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};

void insertAtHead(Node* &head,int d){
    Node* temp= new Node(d);
    temp->next=head;
    head=temp;
}

void insertNode(Node* &tail,int element,int d){
    //empty list
    if(tail==NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next =newNode;
    }
    else{
        Node* curr = tail;
        while(curr->data!=element){
            curr= curr->next;
        }
        Node* temp = new Node(d);
        temp->next = curr-> next;
        curr->next = temp;
    }

}

bool isCircular(Node* head){
    //empty list
    if(head==NULL){
        return true;
       }

    Node * temp = head->next;
    while(temp!=NULL&&temp!=head){
        temp = temp -> next;
    }

    if(temp==head){
        return true;
        }
        return false;
}

int main(){
    //single list
    // Node* node1 = new Node(10);
    // Node* head=node1;
    // insertAtHead(head,22);
    // insertAtHead(head,33);
    // insertAtHead(head,100);

    //circular ll
    Node* node1 = new Node(10);
    Node* tail = node1;

    insertNode(tail, 5, 7);

    insertNode(tail, 7, 9);


    insertNode(tail, 5, 6);


    if(isCircular(tail)) {
        cout << " Linked List is Circular in nature" << endl;
    }
    else{
        cout << "Linked List is not Circular " << endl;
    }
    return 0;
}
