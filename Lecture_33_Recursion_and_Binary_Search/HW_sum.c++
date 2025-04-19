#include<iostream>
using namespace std;

int sumele(int arr[],int n){
    int ans=0;
    //basecase
    if(n==0){

        return 0;
    }
    if(n==1){

        int temp = arr[0];
        return temp;
    }else{


        ans = arr[0]+arr[1];

        return (ans + sumele(arr+2,n-2));
    }





}

int main(){

    int arr[6]={1,1,1,1,1,1};

    int ans = sumele(arr,6);

    cout<<ans<<endl;

}
