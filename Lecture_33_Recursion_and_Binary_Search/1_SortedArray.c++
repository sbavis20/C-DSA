#include<iostream>
using namespace std;

bool isSorted(int arr[],int n){
    //basecase
    if(n==0||n==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }else{
        bool ans = isSorted(arr+1,n-1);
        return ans;
    }


}

int main(){

    int arr[6]={2,4,6,9,11,1};

    bool ans = isSorted(arr,6);

    if(ans){
        cout<<"Sorted"<<endl;
    }else{
        cout<<"Not Sorted"<<endl;
    }

}
