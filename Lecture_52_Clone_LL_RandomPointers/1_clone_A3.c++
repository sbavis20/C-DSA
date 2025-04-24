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
      //step 1: Create a Clone List
      Node* cloneHead = NULL;
      Node* cloneTail = NULL;

      Node* temp = head;
      while(temp != NULL) {
          insertAtTail(cloneHead, cloneTail, temp->data);
          temp = temp -> next;
      }

      // step 2: insert nodes of Clone List in between originalList

      Node* originalNode = head;
      Node* cloneNode = cloneHead;

      while(originalNode != NULL && cloneNode != NULL) {
          Node* next = originalNode -> next;
          originalNode -> next = cloneNode;
          originalNode = next;

          next = cloneNode -> next;
          cloneNode -> next = originalNode;
          cloneNode  = next;
      }

      // step 3: Random pointer copy
      originalNode = head;
      cloneNode = cloneHead;

      while(originalNode != NULL && cloneNode != NULL) {

          if(originalNode -> random != NULL) {
              cloneNode -> random = originalNode -> random -> next;
          }
          else
          {
              cloneNode -> random  = NULL;
          }

          cloneNode = cloneNode -> next;
          originalNode = originalNode -> next;
      }

      //step 4: revert step 2 changes
      Node* original = head;
      Node* copy = cloneHead;

       while (original && copy)
          {
              original->next =
               original->next? original->next->next : original->next;

              copy->next = copy->next?copy->next->next:copy->next;
              original = original->next;
              copy = copy->next;
          }

      // step 5 answer return
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
