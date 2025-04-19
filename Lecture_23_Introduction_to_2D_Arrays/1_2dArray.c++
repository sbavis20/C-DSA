#include<iostream>
using namespace std;
void printArray(int arr[][3],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}


void takeInputRow(int arr[][3],int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
}

void takeInputCol(int arr[][3],int n,int m){
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            cin>>arr[i][j];
        }
    }
}

bool isPresent(int arr[][3],int target,int n,int m){
    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            if(target==arr[i][j]){
                return 1;
            }
        }
    }
    return 0;
}

int main(){

   // int arr[2][3];
   // takeInputRow(arr,2,3);

   // printArray(arr,2,3);

   // takeInputCol(arr,2,3);


   // printArray(arr,2,3);

    //int arr[2][3] = {1,2,3,4,5,6};

    //int arr[2][3] = {{1,11,111},{2,22,222}};

    int arr[2][3]={2,4,6,8,10,12};
    int target=0;
    cin>>target;
    bool check = isPresent(arr,target,2,3);

    if(check){cout<<"Present"<<endl;}else{
        cout<<"Not Present"<<endl;
    }
    return 0;
}
