#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

void reverse(int arr[],int n,int m){
    int s=m+1;
    int e=n-1;
    while(e>s){
        swap(arr[s],arr[e]);
        e--;
        s++;
    }

}

int main(){

    int arr[6]={1, 2, 3, 4, 5, 6};

    reverse(arr,6,3);
    printArray(arr,6);
}
