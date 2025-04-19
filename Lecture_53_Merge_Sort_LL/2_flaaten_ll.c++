#include <iostream>
#include <vector>
using namespace std;

// Node definition
class Node {
public:
    int data;
    Node *next;
    Node *child;

    Node() : data(0), next(nullptr), child(nullptr) {}
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};

// Merge two sorted linked lists connected via 'child'
Node* mergeLists(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;

    if (a->data < b->data) {
        result = a;
        result->child = mergeLists(a->child, b);
    } else {
        result = b;
        result->child = mergeLists(a, b->child);
    }

    result->next = nullptr;  // Flattening: eliminate 'next'
    return result;
}

// Flatten multilevel linked list
Node* flattenLinkedList(Node* head) {
    if (!head || !head->next)
        return head;

    // Recursively flatten the rest of the list
    head->next = flattenLinkedList(head->next);

    // Merge current list with the next one
    head = mergeLists(head, head->next);

    return head;
}

// Helper function to print flattened list using 'child' pointers
void printFlattened(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->child;
    }
    cout << "-1\n";
}

// Helper to create a child linked list from a vector
Node* createChildList(const vector<int>& vals) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int val : vals) {
        Node* newNode = new Node(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->child = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    // Sample Input:
    // 4
    // 1 2 3
    // 8 10 15
    // 18 22
    // 29

    vector<vector<int>> input = {
        {1, 2, 3},
        {8, 10, 15},
        {18, 22},
        {29}
    };

    // Create multilevel list using next and child pointers
    Node* head = nullptr;
    Node* prev = nullptr;

    for (const auto& childList : input) {
        Node* sublist = createChildList(childList);
        if (!head) {
            head = sublist;
        } else {
            prev->next = sublist;
        }
        prev = sublist;
    }

    // Flatten and print the result
    Node* flat = flattenLinkedList(head);
    printFlattened(flat);

    return 0;
}
