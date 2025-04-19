#include<iostream>
using namespace std;

bool linearSearch(int arr[],int n,int k){
    //basecase
    if(n==0){
        return false;
    }

    if(arr[0]==k){
        return true;
    }else{
        return linearSearch(arr+1,n,k);
    }

}

int main(){

    int arr[5]={2,4,6,8,12};

    int ans = linearSearch(arr,5,22);

    cout<<ans<<endl;

    return 0;
}
