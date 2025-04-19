#include <iostream>
using namespace std;

// Definition for singly-linked list
class Node {
public:
    int data;
    Node* next;
    Node() {
        this->data = 0;
        this->next = NULL;
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

// Function to sort 0s, 1s, 2s in a linked list
Node* sortList(Node *head) {
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == 0) zeroCount++;
        else if (temp->data == 1) oneCount++;
        else if (temp->data == 2) twoCount++;
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL) {
        if (zeroCount > 0) {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount > 0) {
            temp->data = 1;
            oneCount--;
        }
        else {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Sample Input 1:
    int n = 7;
    int arr[] = {1, 0, 2, 1, 0, 2, 1};

    // Creating the linked list
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

    // Sorting the list
    head = sortList(head);

    // Output
    printList(head);

    return 0;
}
