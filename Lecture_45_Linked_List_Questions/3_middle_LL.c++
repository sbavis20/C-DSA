#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

int getlength(Node* head){
    int len =0;
    while(head != NULL){
        len++;
        head=head->next;
    }

    return len;

}

Node *findMiddle(Node *head) {
    // Write your code here
    int len = getlength(head);
    int ans =(len/2);

    Node* temp=head;
    int cnt=0;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }

    return temp;

}

int main(){

    return 0;
}
