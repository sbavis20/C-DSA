#include<iostream>
using namespace std;

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }

}

void swapAlt(int arr[], int size){

    for(int i=0;i<size;i+=2){
        if(i+1<size){
            swap(arr[i],arr[i+1]);
        }
    }

}

int main(){
    int even[8]={5,1,2,3,4,7,8,9};

    int odd[5]={9,8,7,6,5};

    swapAlt(even,8);

    swapAlt(odd,5);

    print(even,8);
    cout<<"Odd"<<endl;
    print(odd,5);

    return 0;
}
