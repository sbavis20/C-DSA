#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int>& s, int x) {
    // Base case: if stack is empty, push the element
    if (s.empty()) {
        s.push(x);
        return;
    }

    // Pop the top element and store it
    int num = s.top();
    s.pop();

    // Recursive call to process the remaining stack
    solve(s, x);

    // Push the stored element back onto the stack
    s.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) {
    solve(myStack, x);
    return myStack;
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
        s1.push(3);
        s1.push(4);
        cout << "Sample Input 1: ";
        printStack(s1);
        pushAtBottom(s1, 8);
        cout << "Sample Output 1: ";
        printStack(s1);
    }

    // Sample Input 2
    {
        stack<int> s2;
        s2.push(9);
        s2.push(4);
        s2.push(2);
        s2.push(6);
        cout << "Sample Input 2: ";
        printStack(s2);
        pushAtBottom(s2, 5);
        cout << "Sample Output 2: ";
        printStack(s2);
    }

    // Sample Input 3
    {
        stack<int> s3;
        s3.push(4);
        cout << "Sample Input 3: ";
        printStack(s3);
        pushAtBottom(s3, 0);
        cout << "Sample Output 3: ";
        printStack(s3);
    }

    // Sample Input 4
    {
        stack<int> s4;
        s4.push(9);
        s4.push(1);
        cout << "Sample Input 4: ";
        printStack(s4);
        pushAtBottom(s4, 5);
        cout << "Sample Output 4: ";
        printStack(s4);
    }

    return 0;
}
