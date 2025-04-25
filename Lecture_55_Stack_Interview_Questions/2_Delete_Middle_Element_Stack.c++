#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void solve(stack<int>& inputStack, int count, int size) {
    // Base case: when count reaches the middle index
    if (count == size / 2) {
        inputStack.pop();
        return;
    }

    int num = inputStack.top();
    inputStack.pop();

    // Recursive call to reach the middle index
    solve(inputStack, count + 1, size);

    // Push the elements back after removing the middle element
    inputStack.push(num);
}

void deleteMiddle(stack<int>& inputStack, int N) {
    int size = N + 1; // Since the stack size is N+1
    int count = 0;
    solve(inputStack, count, size);
}

void printStack(stack<int> s) {
    if (s.empty()) {
        return;
    }
    int num = s.top();
    s.pop();
    printStack(s);
    cout << num << " ";
}

int main() {
    // Sample Input 1
    {
        stack<int> s1;
        vector<int> arr1 = {1, 2, 3, 4, 5};

        for (int num : arr1) {
            s1.push(num);
        }

        cout << "Sample Input 1 : ";
        printStack(s1);
        cout << endl;

        deleteMiddle(s1, 4);
        cout << "Sample Output 1: ";
        printStack(s1);
        cout << endl;
    }

    // Sample Input 2
    {
        stack<int> s2;
        vector<int> arr2 = {83, 74, 67, 49, 94, 8, 11, 1};

        for (int num : arr2) {
            s2.push(num);
        }
        cout << "Sample Input 2: ";
        printStack(s2);
        cout << endl;

        deleteMiddle(s2, 7);

        cout << "Sample Output 2: ";
        printStack(s2);
        cout << endl;
    }

    // Sample Input 3
    {
        stack<int> s3;
        vector<int> arr3 = {5, 10};

        for (int num : arr3) {
            s3.push(num);
        }
        cout << "Sample Input 3: ";
        printStack(s3);
        cout << endl;

        deleteMiddle(s3, 1);

        cout << "Sample Output 3: ";
        printStack(s3);
        cout << endl;
    }

    // Sample Input 4
    {
        stack<int> s4;
        vector<int> arr4 = {1, 3, 4, 2, 7};

        for (int num : arr4) {
            s4.push(num);
        }

        cout << "Sample Input 4: ";
        printStack(s4);
        cout << endl;

        deleteMiddle(s4, 4);

        cout << "Sample Output 4: ";
        printStack(s4);
        cout << endl;
    }

    // Sample Input 5
    {
        stack<int> s5;
        vector<int> arr5 = {9, 5, 2, 7, 8, 6};

        for (int num : arr5) {
            s5.push(num);
        }
        cout << "Sample Input 5: ";
        printStack(s5);
        cout << endl;

        deleteMiddle(s5, 5);

        cout << "Sample Output 5: ";
        printStack(s5);
        cout << endl;
    }

    return 0;
}
