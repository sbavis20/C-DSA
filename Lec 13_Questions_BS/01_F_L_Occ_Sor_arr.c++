#include<iostream>
using namespace std;

int firstOcc(int arr[],int size,int key){
    int start =0;
    int end = size -1;
    int ans =0;
    int mid = start + (end-start)/2;

    while(start<=end){

        if (arr[mid]==key){
            ans = mid;
            end = mid - 1;

        }

        else if(key>arr[mid]){
            start = mid + 1;
        }

        else if ( key < arr[mid]){
            end = mid -1;
        }


        mid =  start + (end - start)/2;
    }

    return ans;

}

int lastOcc(int arr[],int size,int key){
    int start =0;
    int end = size -1;
    int ans =0;
    int mid = start + (end-start)/2;

    while(start<=end){

        if (arr[mid]==key){
            ans = mid;
            start = mid + 1;

        }

        else if(key>arr[mid]){
            start = mid + 1;
        }

        else if ( key < arr[mid]){
            end = mid -1;
        }


        mid =  start + (end - start)/2;
    }

    return ans;

}

int main(){
    int even[6]={2,4,8,8,9,10};

    cout<<"First Occ Index= "<<firstOcc(even,6,8);

    cout<<"Last Occ Index= "<<lastOcc(even,6,8);


    return 0;
}
