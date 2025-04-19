#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};

// Function to reverse k nodes in linked list
Node* kReverse(Node* head, int k) {
    // Base case
    if(head == NULL) {
        return NULL;
    }

    // Step 1: Reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int count = 0;

    while(curr != NULL && count < k) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Step 2: Check if enough nodes are left for another k-group
    Node* temp = next;
    int remainingCount = 0;
    while(temp != NULL && remainingCount < k) {
        remainingCount++;
        temp = temp->next;
    }

    if(remainingCount == k) {
        head->next = kReverse(next, k);
    } else {
        head->next = next; // Leave remaining as is
    }

    // Step 3: Return new head
    return prev;
}

// Function to take input and create linked list
Node* takeInput(int n) {
    if (n == 0) return NULL;

    int data;
    cin >> data;
    Node* head = new Node(data);
    Node* tail = head;

    for (int i = 1; i < n; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
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
    // Sample input:
    // 6
    // 5 4 3 7 9 2
    // 4

    int n;
    cin >> n;
    Node* head = takeInput(n);

    int k;
    cin >> k;

    Node* newHead = kReverse(head, k);
    printList(newHead);

    return 0;
}
