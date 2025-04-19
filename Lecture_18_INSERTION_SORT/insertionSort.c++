#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp = arr[i];

        int j = i-1;
        for(;j>=0;j--){

            if(arr[j]>temp){
                //shift
                arr[j+1]=arr[j];

            }
            else{//ruk jao
            break;

            }



        }

        arr[j+1]=temp;
    }
}

int main(){


    int arr[5]={10,9,8,7,6};

    insertionSort(arr,5);

    printArray(arr,5);
}
