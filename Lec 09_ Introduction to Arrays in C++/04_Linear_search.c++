#include<iostream>
using namespace std;

bool search(int arr[],int size, int key){
    for(int i = 0; i<size;i++){
        if(arr[i] == key){return true;}

    }
    return false;
}

int main(){

    int arr[10]= {1,5,8,9,24,98,4,6,4,10};
    int key;
    cout<<"Enter the element to search: " <<endl;
    cin>>key;

    bool found = search(arr,10,key);

    if(found){cout<<"Key is present"<<endl;}
    else{cout<<"Not found"<<endl;}

    return 0;
}
