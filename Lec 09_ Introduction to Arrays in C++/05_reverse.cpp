#include<iostream>
using namespace std;

void reverse(int arr[], int size){

    int p=0;
    int q = size-1;
    int temp;

    while(p<q){

        temp = arr[p];
        arr[p] = arr[q];
        arr[q] = temp;
        p++;
        q--;
    }

    for(int i = 0; i<size;i++){
        cout<<arr[i]<<endl;
    }

}

int main(){
    int arr[5]={1,2,3,4,5};

    reverse(arr,5);


    return 0;
}
