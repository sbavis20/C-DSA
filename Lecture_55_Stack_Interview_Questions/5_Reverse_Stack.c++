#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s, int element) {
    // Base case: if stack is empty, push the element
    if (s.empty()) {
        s.push(element);
        return;
    }

    // Pop the top element and store it
    int num = s.top();
    s.pop();

    // Recursive call to insert the element at the bottom
    insertAtBottom(s, element);

    // Push the stored element back onto the stack
    s.push(num);
}

void reverseStack(stack<int>& s) {
    // Base case: if stack is empty, return
    if (s.empty()) {
        return;
    }

    // Pop the top element and store it
    int num = s.top();
    s.pop();

    // Recursive call to reverse the remaining stack
    reverseStack(s);

    // Insert the stored element at the bottom of the reversed stack
    insertAtBottom(s, num);
}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    // Sample Input 1
    {
        stack<int> s1;
        s1.push(2);
        s1.push(1);
        s1.push(3);
        cout << "Sample Input 1: ";
        printStack(s1);
        reverseStack(s1);
        cout << "Sample Output 1: ";
        printStack(s1);
    }

    // Sample Input 2
    {
        stack<int> s2;
        s2.push(3);
        s2.push(2);
        cout << "Sample Input 2: ";
        printStack(s2);
        reverseStack(s2);
        cout << "Sample Output 2: ";
        printStack(s2);
    }

    return 0;
}
