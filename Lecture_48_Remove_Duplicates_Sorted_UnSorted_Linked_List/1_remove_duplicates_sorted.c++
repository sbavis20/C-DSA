#include <iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

// Function to remove duplicates from a sorted doubly linked list
Node* removeDuplicates(Node* head) {
    if (head == NULL) return NULL;

    Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* nodeToDelete = curr->next;
            curr->next = nodeToDelete->next;
            if (nodeToDelete->next != NULL) {
                nodeToDelete->next->prev = curr;
            }
            delete nodeToDelete;
        } else {
            curr = curr->next;
        }
    }

    return head;
}

// Helper function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a doubly linked list from an array
Node* createDoublyLinkedList(const vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i = 1; i < arr.size(); ++i) {
        Node* newNode = new Node(arr[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
    }

    return head;
}

int main() {
    // Sample Input
    int n = 5;
    vector<int> values = {1, 2, 2, 2, 3};

    // Create list
    Node* head = createDoublyLinkedList(values);

    // Remove duplicates
    head = removeDuplicates(head);

    // Output the result
    printList(head);

    return 0;
}
