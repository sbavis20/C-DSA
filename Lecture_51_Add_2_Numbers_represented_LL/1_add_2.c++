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

// Function to reverse a linked list
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to add two reversed linked lists
Node* add(Node* first, Node* second) {
    Node* res = NULL;
    Node* temp = NULL;
    Node* prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = new Node(sum);
        if (res == NULL) {
            res = temp;
        } else {
            prev->next = temp;
        }
        prev = temp;
        if (first) first = first->next;
        if (second) second = second->next;
    }
    if (carry > 0) {
        temp->next = new Node(carry);
    }
    return res;
}

// Function to add two numbers represented by linked lists
Node* addTwoLists(Node* first, Node* second) {
    first = reverse(first);
    second = reverse(second);
    Node* ans = add(first, second);
    ans = reverse(ans);
    return ans;
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
    // Example 1: 5 -> 6 -> 3 (represents 365) + 8 -> 4 -> 2 (represents 248) = 6 -> 1 -> 5 (represents 613)
    int arr1[] = {5, 6, 3};
    int arr2[] = {8, 4, 2};
    Node* first = createLinkedList(arr1, 3);
    Node* second = createLinkedList(arr2, 3);
    cout << "First List: ";
    printList(first);
    cout << "Second List: ";
    printList(second);
    Node* sum = addTwoLists(first, second);
    cout << "Sum List: ";
    printList(sum);
    cout << endl;

    // Example 2: 7 -> 5 -> 9 -> 4 -> 6 (represents 64957) + 8 -> 4 (represents 48) = 5 -> 0 -> 0 -> 5 -> 6 (represents 65005)
    int arr3[] = {7, 5, 9, 4, 6};
    int arr4[] = {8, 4};
    first = createLinkedList(arr3, 5);
    second = createLinkedList(arr4, 2);
    cout << "First List: ";
    printList(first);
    cout << "Second List: ";
    printList(second);
    sum = addTwoLists(first, second);
    cout << "Sum List: ";
    printList(sum);
    cout << endl;

    // Example 3: 9 -> 9 -> 9 (represents 999) + 1 (represents 1) = 0 -> 0 -> 0 -> 1 (represents 1000)
    int arr5[] = {9, 9, 9};
    int arr6[] = {1};
    first = createLinkedList(arr5, 3);
    second = createLinkedList(arr6, 1);
    cout << "First List: ";
    printList(first);
    cout << "Second List: ";
    printList(second);
    sum = addTwoLists(first, second);
    cout << "Sum List: ";
    printList(sum);
    cout << endl;

    return 0;
}
