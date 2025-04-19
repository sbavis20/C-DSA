#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Function to check if a vector is a palindrome
bool checkPalindrome(vector<int> arr) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;

    while (s <= e) {
        if (arr[s] != arr[e]) {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node* head) {
    vector<int> arr;
    Node* temp = head;

    while (temp != NULL) {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(arr);
}

// Function to insert node at tail
void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// Main function to test the code
int main() {
    // Sample Input 1: 1 2 3 2 1 -1 (Palindrome)
    // Sample Input 2: 1 2 2 3 -1 (Not Palindrome)

    Node* head = NULL;
    Node* tail = NULL;

    int data;
    cout << "Enter linked list elements (end with -1): ";
    while (cin >> data && data != -1) {
        insertAtTail(head, tail, data);
    }

    if (isPalindrome(head)) {
        cout << "Palindrome Linked List" << endl;
    } else {
        cout << "Not a Palindrome Linked List" << endl;
    }

    return 0;
}
