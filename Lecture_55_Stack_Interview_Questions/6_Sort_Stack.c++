#include <iostream>
#include <stack>
using namespace std;

void sortedInsert(stack<int> &s, int num) {
    // Base case: if stack is empty or top element is smaller than num
    if (s.empty() || (!s.empty() && s.top() < num)) {
        s.push(num);
        return;
    }

    // Pop the top element and store it
    int n = s.top();
    s.pop();

    // Recursive call to insert num in the correct position
    sortedInsert(s, num);

    // Push the stored element back onto the stack
    s.push(n);
}

void sortStack(stack<int> &s) {
    // Base case: if stack is empty, return
    if (s.empty()) {
        return;
    }

    // Pop the top element and store it
    int num = s.top();
    s.pop();

    // Recursive call to sort the remaining stack
    sortStack(s);

    // Insert the stored element in the sorted stack
    sortedInsert(s, num);
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
        s1.push(5);
        s1.push(-2);
        s1.push(9);
        s1.push(-7);
        s1.push(3);
        cout << "Sample Input 1: ";
        printStack(s1);
        sortStack(s1);
        cout << "Sample Output 1: ";
        printStack(s1);
    }

    // Sample Input 2
    {
        stack<int> s2;
        s2.push(30);
        s2.push(18);
        s2.push(14);
        s2.push(-3);
        s2.push(-5);
        cout << "Sample Input 2: ";
        printStack(s2);
        sortStack(s2);
        cout << "Sample Output 2: ";
        printStack(s2);
    }

    return 0;
}
