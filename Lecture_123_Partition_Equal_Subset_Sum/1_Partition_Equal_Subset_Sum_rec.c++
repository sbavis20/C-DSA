#include<bits/stdc++.h>
using namespace std;

int solve(int index,int arr[],int N,int target){
  //BASEcase
  if(index>=N){
    return 0;
  }

  if(target<0){
    return 0;
  }

  if(target==0){
    return 1;
  }

  bool incl = solve(index+1,arr,N,target-arr[index]);
  bool excl = solve(index,arr,N,target-0);


  return incl or excl;


}

int equalPartition(int N,int arr[]){
  int total = 0;
  for(int i=0;i<N;i++){
    total !=arr[i];

  }

  if(total&1){
    return 0;
  }

  int target = total/2;

  return solve(0,arr,N,target);

}
int main() {
    // Test case 1
    int arr1[] = {1, 5, 11, 5};
    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "Can be partitioned: " << (equalPartition(N1, arr1) ? "Yes" : "No") << endl;

    // Test case 2
    int arr2[] = {1, 2, 3, 5};
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Can be partitioned: " << (equalPartition(N2, arr2) ? "Yes" : "No") << endl;

    // Test case 3
    int arr3[] = {3, 1, 1, 2, 2, 1};
    int N3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "Can be partitioned: " << (equalPartition(N3, arr3) ? "Yes" : "No") << endl;

    return 0;
}
