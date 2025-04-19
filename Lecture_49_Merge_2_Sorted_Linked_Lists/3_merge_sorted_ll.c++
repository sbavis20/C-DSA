#include <iostream>
using namespace std;

/************************************************************

    Linked list node structure.

************************************************************/
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};

// Helper function to merge two sorted lists
Node<int>* solve(Node<int>* first, Node<int>* second) {
    Node<int>* curr1 = first;
    Node<int>* next1 = curr1->next;

    Node<int>* curr2 = second;
    Node<int>* next2 = curr2->next;

    while (next1 != NULL && curr2 != NULL) {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            curr1 = curr2;
            curr2 = next2;
        } else {
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL) {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

// Sort and merge two sorted lists
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second) {
    if (first == NULL) return second;
    if (second == NULL) return first;

    if (first->data <= second->data) {
        return solve(first, second);
    } else {
        return solve(second, first);
    }
}

// Print linked list
void printList(Node<int>* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "-1" << endl; // Sentinel as per sample
}

// Helper to build list from array
Node<int>* buildList(const int arr[], int size) {
    if (size == 0) return NULL;

    Node<int>* head = new Node<int>(arr[0]);
    Node<int>* tail = head;
    for (int i = 1; i < size; i++) {
        tail->next = new Node<int>(arr[i]);
        tail = tail->next;
    }
    return head;
}

int main() {
    // Sample Input 1:
    int arr1[] = {7, 8};         // First list
    int arr2[] = {1, 3, 4, 6};   // Second list

    Node<int>* first = buildList(arr1, 2);
    Node<int>* second = buildList(arr2, 4);

    Node<int>* merged = sortTwoLists(first, second);

    printList(merged); // Expected: 1 3 4 6 7 8 -1

    return 0;
}
