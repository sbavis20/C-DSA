#include<iostream>
using namespace std;

bool binarySearch(int *arr,int s,int e,int k){

    //basecase
    if(s>e){
        return -1;
    }

    int mid  = s + (e-s)/2;

    if(arr[mid]==k){
        return true;
    }

    if(arr[mid]<k){
        return binarySearch(arr,mid+1,e,k);
    }else{
        return binarySearch(arr,s,mid-1,k);
    }

}

int main(){

    int arr[5]={3,4,6,8,9};

    bool ans = binarySearch(arr,0,5,8);

    if(ans){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
}
