#include <iostream>
using namespace std;

// Definition for singly-linked list
class Node {
public:
    int data;
    Node* next;
    Node() {
        this->data = 0;
        next = NULL;
    }
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

// Helper function to insert node at the tail
void insertAtTail(Node* &tail, Node* curr) {
    tail->next = curr;
    tail = curr;
}

// Sort list by rearranging nodes (not data)
Node* sortList(Node *head) {
    Node* zeroHead = new Node(-1);
    Node* zeroTail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* oneTail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twoTail = twoHead;

    Node* curr = head;

    while (curr != NULL) {
        int value = curr->data;

        if (value == 0) insertAtTail(zeroTail, curr);
        else if (value == 1) insertAtTail(oneTail, curr);
        else if (value == 2) insertAtTail(twoTail, curr);

        curr = curr->next;
    }

    // Connect the three lists
    if (oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    // Set new head
    head = zeroHead->next;

    // Delete dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

// Print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Sample Input 1: 7 nodes -> 1 0 2 1 0 2 1
    int n = 7;
    int arr[] = {1, 0, 2, 1, 0, 2, 1};

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    head = sortList(head);

    printList(head);

    return 0;
}
