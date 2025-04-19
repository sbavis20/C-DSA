#include<iostream>
using namespace std;

void printArray(int arr[],int n){

        for(int i=0;i<n;i++){
            cout<<arr[i]<<endl;
        }

}

void rotate(int arr[],int n, int k){
    int temp[n]={0};

    for(int i =0;i<n;i++){
        temp[(i+k)%n] = arr[i];
    }
    printArray(temp,n);
}

int main(){

    int arr[5]={2,4,6,8,10};
    rotate(arr,5,3);


}
