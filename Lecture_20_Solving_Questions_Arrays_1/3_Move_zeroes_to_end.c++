#include<iostream>
using namespace std;
void printArray(int arr[],int n){
    for(int i =0;i<n;i++){
        cout<<arr[i]<<endl;
    }

}

void moveZero(int arr[],int n){
    int i = 0;

    for(int j=0;j<n;j++){
        if(arr[j]!=0){
            swap(arr[j],arr[i]);
            i++;
        }
    }



}


int main(){


    int arr[5]={0,0,1,2,3};

    moveZero(arr,5);
    printArray(arr,5);
}
