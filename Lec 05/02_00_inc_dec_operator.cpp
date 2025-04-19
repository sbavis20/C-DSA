#include<iostream>
using namespace std;

int main(){

    int i;

    //pre increment
    int a = 3, b =4;
    int sum_pre = b +(++a);
    cout<<"Preincrement sum = "<<sum_pre<<endl;

    //post increment
    int a1 = 3, b1 =4;
    int sum_post = b1 +(a1++);
    cout<<"Postincrement sum = "<<sum_post<<endl;
}
