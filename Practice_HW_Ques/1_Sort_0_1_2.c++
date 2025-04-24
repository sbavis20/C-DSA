#include <iostream>
using namespace std;

void sort012(int *arr, int n) {
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else if (arr[mid] == 2) {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    // Sample Input 1
    {
        int arr1[] = {0, 1, 2, 2, 1, 0};
        int n1 = sizeof(arr1) / sizeof(arr1[0]);
        sort012(arr1, n1);
        cout << "Sample Input 1 Output: ";
        for (int i = 0; i < n1; i++) {
            cout << arr1[i] << " ";
        }
        cout << endl;
    }

    // Sample Input 2
    {
        int arr2[] = {0, 1, 2, 1, 2, 1, 2};
        int n2 = sizeof(arr2) / sizeof(arr2[0]);
        sort012(arr2, n2);
        cout << "Sample Input 2 Output: ";
        for (int i = 0; i < n2; i++) {
            cout << arr2[i] << " ";
        }
        cout << endl;
    }

    // Sample Input 3
    {
        int arr3[] = {2, 2, 2, 1, 1, 1, 0};
        int n3 = sizeof(arr3) / sizeof(arr3[0]);
        sort012(arr3, n3);
        cout << "Sample Input 3 Output: ";
        for (int i = 0; i < n3; i++) {
            cout << arr3[i] << " ";
        }
        cout << endl;
    }

    // Sample Input 4
    {
        int arr4[] = {2, 1, 2, 0, 1, 0};
        int n4 = sizeof(arr4) / sizeof(arr4[0]);
        sort012(arr4, n4);
        cout << "Sample Input 4 Output: ";
        for (int i = 0; i < n4; i++) {
            cout << arr4[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
