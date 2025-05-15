#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int getKthLargest(vector<int> &arr,int k){
    vector<int> sumStore;
    int n = arr.size();

    for(int i=0;i<n;i++){
        int sum =0;
        for(int j=0;j<n;j++){
            sum+=arr[j];
            sumStore.push_back(sum);
        }
    }

    sort(sumStore.begin(),sumStore.end());

    return sumStore[sumStore.size()-k];
}

int main(){

    return 0;
}
