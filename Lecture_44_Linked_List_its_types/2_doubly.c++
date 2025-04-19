#include<iostream>
using namespace std;

class Node{

    public:
        int data;
        Node* prev;
        Node* next;

    Node(int d){
        this->data=d;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){
        int value = this-> data;
        if(next!=NULL){
            delete next;
            next = NULL;
           }
           cout<<"Memory free for node with data"<<value<<endl;
    }

};

void print(Node* &head){
    Node* temp =head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int getLength(Node* head){
    int len =0;
    Node* temp = head;

    while(temp!=NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void inserAthead(Node* &tail,Node* &head,int d){
    //empty list
    if(head==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail =temp;
    }else{
        Node* temp =new Node(d);
        temp->next = head;
        head->prev = temp;
        head= temp;
    }


}

void inserAtTail(Node* &tail,Node* &head,int d){
    if(tail==NULL){
        Node* temp = new Node(d);
        head = temp;
        tail =temp;
    }else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp -> prev = tail;
        tail = temp;
    }

}

void inserAtPosition(Node* &tail,Node* &head,int position,int d){
    //insert at start
    if(position==1){
        inserAthead(tail,head,d);
    }
    Node* temp = head;
    int cnt=1;

    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }

    //inserting at last Position
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;
    temp-> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;

}

void deleteNode(int position,Node* &head){
    //deleting firt or start node
    if(position ==1){
        Node* temp =head;
        temp-> next->prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete  temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr=curr->next;
            cnt++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;
    }


}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    // int len = getLength(head);
    // cout<<"Len : "<<len<<endl;

    inserAthead(tail,head,11);
    print(head);

    inserAthead(tail,head,19);
    print(head);

    // inserAtTail(tail,15);
    // print(head);

    inserAtPosition(tail,head,3,22);
    print(head);

    inserAtPosition(tail,head,1,101);
    print(head);

    inserAtPosition(tail,head,5,101);
    print(head);

    deleteNode(7,head);
    print(head);


    return 0;
}
