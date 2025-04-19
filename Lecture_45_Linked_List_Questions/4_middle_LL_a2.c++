#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

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

Node* getMiddle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* fast = head->next;
    Node* slow = head;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
}

Node* findMiddle(Node* head) {
    return getMiddle(head);
}

void printFromNode(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Sample Input 2:
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Construct the linked list
    Node* head = new Node(arr[0]);
    Node* tail = head;
    for (int i = 1; i < n; i++) {
        tail->next = new Node(arr[i]);
        tail = tail->next;
    }

    // Find and print from middle
    Node* middle = findMiddle(head);
    printFromNode(middle);

    return 0;
}
