#include<iostream>
using namespace std;

void largetRowSum(int arr[][3],int n,int m){
    int temp=0;
    int maxrow =-1;
    for(int i=0;i<n;i++){
        int sum = 0;

        for(int j=0;j<m;j++){
            sum += arr[i][j];

        }
        if(temp<sum){
            temp=sum;
            maxrow=i;
            }


    }
    cout<<"Larget Sum rows: "<<temp<<" "<<maxrow<<endl;

}

int main(){
    int arr[2][3]={2,4,6,8,10,12};

    largetRowSum(arr,2,3);

    return 0;
}
