#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to find the middle of the linked list
Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }

    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    Node* result = dummy->next;
    delete dummy;
    return result;
}

// Function to perform merge sort on linked list
Node* mergeSort(Node* head) {
    // Base case
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Find the middle of the list
    Node* mid = findMid(head);

    // Split the list into two halves
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // Recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge the sorted halves
    Node* result = merge(left, right);

    return result;
}

// Function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from an array
Node* createLinkedList(int arr[], int n) {
    if (n == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for (int i = 1; i < n; i++) {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    // Example 1
    int arr1[] = {5, 3, 8, 1, 6, 2};
    Node* head1 = createLinkedList(arr1, 6);
    cout << "Original List 1: ";
    printList(head1);
    head1 = mergeSort(head1);
    cout << "Sorted List 1: ";
    printList(head1);
    cout << endl;

    // Example 2
    int arr2[] = {9, 7, 5, 3, 1};
    Node* head2 = createLinkedList(arr2, 5);
    cout << "Original List 2: ";
    printList(head2);
    head2 = mergeSort(head2);
    cout << "Sorted List 2: ";
    printList(head2);
    cout << endl;

    // Example 3
    int arr3[] = {4};
    Node* head3 = createLinkedList(arr3, 1);
    cout << "Original List 3: ";
    printList(head3);
    head3 = mergeSort(head3);
    cout << "Sorted List 3: ";
    printList(head3);
    cout << endl;

    return 0;
}
