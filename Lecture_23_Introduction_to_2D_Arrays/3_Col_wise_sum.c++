#include<iostream>
using namespace std;

void colWiseSum(int arr[][3],int n,int m){

    for(int j=0;j<m;j++){
        int sum = 0;
        for(int i=0;i<n ;i++){
            sum += arr[i][j];
        }
        cout<<"Row Wise Sum: "<<sum<<endl;
    }

}

int main(){
    int arr[2][3]={1,3,5,7,9,11};

   colWiseSum(arr,2,3);



    return 0;
}
