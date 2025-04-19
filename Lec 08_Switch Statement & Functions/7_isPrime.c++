#include<iostream>
using namespace std;

bool isPrime(int num){
    for(int  i =2;i<=num;i++){
        //divide fogaya hai, not a prime no.
        if(num%i==0){
            return 0;
        }
    }

    return 1;
}

int main(){
    int num;
    cin>> num;

    int ans = isPrime(num);

    if(ans){cout<<"Prime..."<<endl; }
    else{cout<<"Not Prime..."<<endl;}

    return 0;
}
