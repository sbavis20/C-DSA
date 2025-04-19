#include<iostream>
using namespace std;

int getSum(int *arr,int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}

int main(){

    int n;
    cin>>n;
    //variable size array
    int* arr = new int[n];

    //array input
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int ans = getSum(arr,n);

    cout<<"Sum: "<<ans<<endl;

    delete []arr;
    // char ch = 'q';
    // cout<<sizeof(ch)<<endl;

    // char* c =&ch;
    // cout<<sizeof(c)<<endl;

    // int i=10;
    // cout<<sizeof(i)<<endl;

    // int* ptr = &i;
    // cout<<sizeof(ptr)<<endl;

    return 0;
}
