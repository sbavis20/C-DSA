#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Define a Node for a singly linked list
template<typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) {
        data = val;
        next = nullptr;
    }
};

// Custom comparator for the min heap
class compare {
public:
    bool operator()(Node<int>* a, Node<int>* b) {
        return a->data > b->data; // Min-heap
    }
};

// Function to merge k sorted linked lists
Node<int>* mergeKLists(vector<Node<int>*> &listArray) {
    priority_queue<Node<int>*, vector<Node<int>*>, compare> minHeap;

    int k = listArray.size();
    if (k == 0) return nullptr;

    // Push the head node of all lists into the min heap
    for (int i = 0; i < k; i++) {
        if (listArray[i] != nullptr) {
            minHeap.push(listArray[i]);
        }
    }

    Node<int>* head = nullptr;
    Node<int>* tail = nullptr;

    while (!minHeap.empty()) {
        Node<int>* top = minHeap.top();
        minHeap.pop();

        if (head == nullptr) {
            head = top;
            tail = top;
        } else {
            tail->next = top;
            tail = top;
        }

        if (top->next != nullptr) {
            minHeap.push(top->next);
        }
    }

    return head;
}

// Helper function to print the linked list
void printList(Node<int>* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test
int main() {
    // Create test case: 3 sorted linked lists
    Node<int>* a = new Node<int>(1);
    a->next = new Node<int>(4);
    a->next->next = new Node<int>(5);

    Node<int>* b = new Node<int>(1);
    b->next = new Node<int>(3);
    b->next->next = new Node<int>(4);

    Node<int>* c = new Node<int>(2);
    c->next = new Node<int>(6);

    vector<Node<int>*> lists = {a, b, c};

    Node<int>* merged = mergeKLists(lists);
    cout << "Merged Sorted List: ";
    printList(merged);

    return 0;
}
