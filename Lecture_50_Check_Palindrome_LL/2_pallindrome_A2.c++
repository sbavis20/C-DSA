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

class Solution {
private:
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    bool isPalindrome(Node* head) {
        if (head->next == NULL) {
            return true;
        }

        // Step 1: Find the middle of the linked list
        Node* middle = getMid(head);

        // Step 2: Reverse the second half of the linked list
        Node* temp = middle->next;
        middle->next = reverse(temp);

        // Step 3: Compare the first half and the reversed second half
        Node* head1 = head;
        Node* head2 = middle->next;

        while (head2 != NULL) {
            if (head1->data != head2->data) {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Step 4: Reverse the second half again to restore the original list
        temp = middle->next;
        middle->next = reverse(temp);

        return true;
    }
};

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
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
    Solution sol;

    // Example 1: Palindrome linked list
    int arr1[] = {1, 2, 3, 2, 1};
    Node* head1 = createLinkedList(arr1, 5);
    cout << "Linked List 1: ";
    printList(head1);
    bool result1 = sol.isPalindrome(head1);
    cout << "Is Palindrome: " << (result1 ? "Yes" : "No") << endl << endl;

    // Example 2: Non-palindrome linked list
    int arr2[] = {1, 2, 3, 4, 5};
    Node* head2 = createLinkedList(arr2, 5);
    cout << "Linked List 2: ";
    printList(head2);
    bool result2 = sol.isPalindrome(head2);
    cout << "Is Palindrome: " << (result2 ? "Yes" : "No") << endl << endl;

    // Example 3: Single node (always a palindrome)
    int arr3[] = {1};
    Node* head3 = createLinkedList(arr3, 1);
    cout << "Linked List 3: ";
    printList(head3);
    bool result3 = sol.isPalindrome(head3);
    cout << "Is Palindrome: " << (result3 ? "Yes" : "No") << endl << endl;

    // Example 4: Even number of nodes (palindrome)
    int arr4[] = {1, 2, 2, 1};
    Node* head4 = createLinkedList(arr4, 4);
    cout << "Linked List 4: ";
    printList(head4);
    bool result4 = sol.isPalindrome(head4);
    cout << "Is Palindrome: " << (result4 ? "Yes" : "No") << endl << endl;

    // Example 5: Even number of nodes (non-palindrome)
    int arr5[] = {1, 2, 3, 1};
    Node* head5 = createLinkedList(arr5, 4);
    cout << "Linked List 5: ";
    printList(head5);
    bool result5 = sol.isPalindrome(head5);
    cout << "Is Palindrome: " << (result5 ? "Yes" : "No") << endl << endl;

    return 0;
}
