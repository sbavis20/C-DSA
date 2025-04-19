/*
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].

Now, in the given array/list, 'M' numbers are present twice and one number is present only once.

You need to find and return that number which is unique in the array/list.

 Note:
Unique element is always present in the array/list according to the given condition.
Sample Input 1:
1
7
2 3 1 6 3 6 2
Sample Output 1:
1
Explanation: The array is [2, 3, 1, 6, 3, 6, 2]. Here, the numbers 2, 3, and 6 are present twice, and the number 1 is present only once. So, the unique number in this array is 1.
Link:https://www.naukri.com/code360/problems/find-unique_625159?source=youtube&campaign=love_babbar_codestudio1
*/

#include<iostream>
using namespace std;

int findUnique(int *arr,int size){
    int ans =0;
    for(int i = 0; i<size;i++){
        ans = ans^arr[i];
    }

    return ans;
}

int main(){

    int arr[10];
    int testcases,size;

    cin>>testcases;
    cin>>size;
    for(int i=0;i<testcases;i++){

        for(int j= 0; j<size;j++){
            cin>>arr[j];
        }
    int ans = findUnique(arr,size);
    cout<<ans<<endl;
    }



    return 0;
}
