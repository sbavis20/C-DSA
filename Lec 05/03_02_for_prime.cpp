#include<iostream>
using namespace std;

int main(){
    int a;
    cin>>a;

     bool isPrime = 1;
    for(int i =2;i<a;i++){
        if(a%i==0){
            //cout<<"Not Prime"<<endl;
            isPrime = 0;
            break;
        }
    }

    if(isPrime == 0){
        cout<<"Not a prime";
    }else{
        cout<<"Prime";
        }


}
