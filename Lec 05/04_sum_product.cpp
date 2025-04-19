#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;

    int sum = 0, product =1;
    int re = 0;
    while(n!=0){
        re = n % 10;
        //cout<<re;
        sum = sum +re;
        //cout<<sum<<endl;
        product = product * re;
        //cout<<product<<endl;

        n = n/10;
    }


    cout<<product - sum<<endl;


}
