#include<iostream>
using namespace std;

int birnarySearch(int n){
    int s = 0;
    int e = n;
    int ans =-1;

    int mid= s + (e-s)/2;

    while(s<=e){
        int square = mid*mid;

        if(square == n){
            return mid;
        }
        if(square<n){
            ans=mid;
            s = mid +1;
        }
        else{
            e = mid -1;
        }
        mid= s + (e-s)/2;
    }

    return ans;
}

int sqrt(int k){
    return birnarySearch(k);
}

int main(){
        int k;
        cin>>k;

        cout<<"Square root is : "<<sqrt(k)<<endl;

    return 0;
}
