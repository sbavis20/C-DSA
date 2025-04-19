#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

void bubbleSort(int arr[],int n){
    for(int i=1;i<n;i++){

        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }

}
    }
}

int main(){

    int arr[5] = {10,9,8,7,6};

    bubbleSort(arr,5);

    printArray(arr,5);
}
