#include<iostream>
using namespace std;

void printArray(int arr[],int n){

    for(int i=0;i<n;i++){

        cout<<arr[i]<<" ";
    }cout<<endl;
}

int partition(int arr[],int s,int e){

    int pivot = arr[s];

    int cnt=0;

    for(int i=s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }

    int pivotIndex = s+cnt;

    swap(arr[pivotIndex],arr[s]);

    int i=s,j=e;

    while(i<pivotIndex && j> pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }

        while(arr[j]>pivot){
            j--;
        }

        if(i< pivotIndex && j > pivotIndex){
            swap(arr[i++],arr[j--]);
        }

    }

    return pivotIndex;

}

void quickSort(int arr[],int s,int e){
    //base condition
    if(s>=e){
        return;
    }

    int p = partition(arr,s,e);

    //right
    quickSort(arr,s,p-1);

    //left
    quickSort(arr,p+1,e);
}

int main(){
    int arr[5]={99,88,77,66,2};

    quickSort(arr,0,5);

    printArray(arr,5);

    return 0;
}
