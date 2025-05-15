#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    int i; // row
    int j; // col

    Node(int val, int row, int col) {
        data = val;
        i = row;
        j = col;
    }
};

class Compare {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

vector<int> mergeSortedArrays(vector<vector<int>>& KArrays, int k) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Push first element of each array into minHeap
    for (int i = 0; i < k; i++) {
        if (!KArrays[i].empty()) {
            Node* tmp = new Node(KArrays[i][0], i, 0);
            minHeap.push(tmp);
        }
    }

    vector<int> ans;

    while (!minHeap.empty()) {
        Node* tmp = minHeap.top();
        minHeap.pop();
        ans.push_back(tmp->data);

        int i = tmp->i;
        int j = tmp->j;

        if (j + 1 < KArrays[i].size()) {
            Node* next = new Node(KArrays[i][j + 1], i, j + 1);
            minHeap.push(next);
        }
    }

    return ans;
}

int main() {
    vector<vector<int>> arrays = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };
    int k = arrays.size();

    vector<int> result = mergeSortedArrays(arrays, k);

    cout << "Merged Sorted Array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
