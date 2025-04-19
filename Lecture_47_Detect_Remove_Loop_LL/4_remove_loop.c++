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

bool detetctLoop(Node* head){
    if(head==NULL){
        return false;
    }

    Node* slow =head;
    Node* fast = head;

    while(slow!=NULL && fast !=NULL){
        fast = fast -> next;
        if(fast !=NULL){
            fast = fast -> next;
        }

        slow = slow-> next;

        if(slow==fast){
            return 1;
        }
    }
    return false;
}

Node* detetctLoop1(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* slow =head;
    Node* fast = head;

    while(slow!=NULL && fast !=NULL){
        fast = fast -> next;
        if(fast !=NULL){
            fast = fast -> next;
        }

        slow = slow-> next;

        if(slow==fast){
            return slow;
        }
    }
    return slow;
}

Node* getStartingNode(Node* head){
    if(head==NULL){
        return NULL;
    }

    Node* intersection = detetctLoop1(head);
    Node* slow = head;

    while(slow!=intersection){
        slow = slow -> next;
        intersection = intersection -> next;
    }

    return slow;
}

void removeLoop(Node* head){
    if(head==NULL){
        return;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* temp = startOfLoop;

    while(temp->next!=startOfLoop){
        temp = temp -> next;
    }

    temp -> next =NULL;
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


    // bool ans = detectCycle(tail);

    // if(ans){
    //     cout<<"Cycle Present"<<endl;
    // }else{
    //     cout<<"No Cycle Detetcted"<<endl;
    // }

    // bool ans = detetctLoop(tail);

    // if(ans){
    //     cout<<"Cycle Present"<<endl;
    // }else{
    //     cout<<"No Cycle Detetcted"<<endl;
    // }
    // Node* loop=getStartingNode(head);
    // cout<<"start of loof: "<<loop->data<<endl;

    removeLoop(head);
    print(head);
    return 0;
}
