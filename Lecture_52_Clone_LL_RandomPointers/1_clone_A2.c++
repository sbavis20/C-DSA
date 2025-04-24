#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;
    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->random = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int d) {
    Node* newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node* copyList(Node* head) {
    // Step 1: Create a clone list with only next pointers
    Node* cloneHead = NULL;
    Node* cloneTail = NULL;

    Node* temp = head;
    while(temp != NULL) {
        insertAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // Step 2: Create a mapping between original and clone nodes
    unordered_map<Node*, Node*> oldToNewNode;

    Node* originalNode = head;
    Node* cloneNode = cloneHead;
    while(originalNode != NULL && cloneNode != NULL) {
        oldToNewNode[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    // Step 3: Set random pointers in clone list
    originalNode = head;
    cloneNode = cloneHead;
    while(originalNode != NULL) {
        cloneNode->random = oldToNewNode[originalNode->random];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}

void printList(Node* head) {
    while(head != NULL) {
        cout << "[" << head->data << ", ";
        if(head->random != NULL) {
            cout << head->random->data;
        } else {
            cout << "NULL";
        }
        cout << "] ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Sample Input 1
    Node* node1 = new Node(1);
    Node* node2 = new Node(3);
    Node* node3 = new Node(5);
    Node* node4 = new Node(9);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node1->random = node3;
    node2->random = node3;
    node3->random = NULL;
    node4->random = node3;

    cout << "Original List: ";
    printList(node1);

    Node* clonedList = copyList(node1);
    cout << "Cloned List: ";
    printList(clonedList);
    cout << endl;

    // Sample Input 2
    Node* n1 = new Node(7);
    Node* n2 = new Node(7);

    n1->next = n2;
    n1->random = NULL;
    n2->random = NULL;

    cout << "Original List: ";
    printList(n1);

    Node* clonedList2 = copyList(n1);
    cout << "Cloned List: ";
    printList(clonedList2);

    return 0;
}
