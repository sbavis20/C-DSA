#include<iostream>
using namespace std;

bool Check_rotated_sorted_array(int arr[],int n){
    int count=0;

    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            count++;
        }
    }
    if(arr[n-1]>arr[0]){count++;}

    return count==1;
}

int main(){
        int arr[5]={3,4,5,1,2};

        if(Check_rotated_sorted_array(arr,5)){
            cout<<"Yes"<<endl;
        }

}
