#include<iostream>
using namespace std;
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

void selectionSort(int arr[], int n){
    for(int i=0;i<n-1;i++){
        int minIndex = i;

        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex],arr[i]);
    }
}

int main(){

    int arr[5]={10,9,8,7,6};

    selectionSort(arr,5);

    printArray(arr,5);
}
