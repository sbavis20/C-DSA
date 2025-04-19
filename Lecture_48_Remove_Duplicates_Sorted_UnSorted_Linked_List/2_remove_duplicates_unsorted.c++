#include <iostream>
#include <unordered_set>
#include <vector>
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

// Function to remove duplicates from unsorted linked list
Node* removeDuplicates(Node* head) {
    if (!head) return head;

    unordered_set<int> seen;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (seen.count(curr->data)) {
            // Duplicate found: skip this node
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            seen.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}

// Print the list ending with -1
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "-1" << endl;
}

int main() {
    // Sample Test Cases
    vector<vector<int>> testCases = {
        {4, 2, 5, 4, 2, 2, -1},
        {1, 2, 1, 2, 2, 2, 7, 7, -1},
        {3, 3, 3, 3, 3, -1},
        {10, 20, 10, 20, 30, 10, 20, 30, -1}
    };

    for (auto& arr : testCases) {
        // Create Linked List
        Node* head = NULL;
        Node* tail = NULL;
        for (int val : arr) {
            if (val == -1) break;
            Node* newNode = new Node(val);
            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        // Remove Duplicates
        head = removeDuplicates(head);

        // Print Result
        printList(head);
    }

    return 0;
}
