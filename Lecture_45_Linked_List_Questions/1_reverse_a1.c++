#include <iostream>
using namespace std;

template <typename T>
class LinkedListNode {
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to reverse the linked list
LinkedListNode<int>* reverseLinkedList(LinkedListNode<int>* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    LinkedListNode<int>* forward = NULL;

    while (curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    return prev;
}

// Function to print the linked list
void printList(LinkedListNode<int>* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "-1" << endl;
}

// Function to create a linked list from user input
LinkedListNode<int>* takeInput() {
    int data;
    cin >> data;

    LinkedListNode<int>* head = NULL;
    LinkedListNode<int>* tail = NULL;

    while (data != -1) {
        LinkedListNode<int>* newNode = new LinkedListNode<int>(data);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        cin >> data;
    }

    return head;
}

int main() {
    // Take input
    LinkedListNode<int>* head = takeInput();

    // Reverse the list
    LinkedListNode<int>* reversedHead = reverseLinkedList(head);

    // Print the result
    printList(reversedHead);

    return 0;
}
