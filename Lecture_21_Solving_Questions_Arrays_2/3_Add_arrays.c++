#include<iostream>
using namespace std;
#include<vector>

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
    cout<<arr[i]<<endl;
    }
}

vector<int> reverse(vector<int> v) {

    int s = 0;
    int e = v.size()-1;

    while(s<e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> addArray(int arr1[],int n,int arr2[],int m){
    int i =n-1;
    int j = m-1;
    vector<int> ans;
    int carry =0;
    while(i>=0 && j>=0){
        int val1 = arr1[i];
        int val2  = arr2[j];

        int sum = val1 + val2 + carry;

        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }

    while(i>=0){
        int sum = arr1[i]+carry;
        carry = sum/10;
        sum = sum %10;
        ans.push_back(sum);
        i--;
    }


    while(j>=0){
        int sum = arr2[i]+carry;
        carry = sum/10;
        sum = sum %10;
        ans.push_back(sum);
        j--;
    }


    while(carry!=0){
        int sum = carry;
        carry = sum/10;
        sum = sum %10;
        ans.push_back(sum);
        i--;
    }

    return reverse(ans);

}
int main(){

    int arr1[3]={1,2,3};
    int arr2[2]={4,5};

   vector<int> ans = addArray(arr1,3,arr2,2);
    for(int a : ans){
        cout<<a;;
    }



}
