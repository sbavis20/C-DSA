#include<iostream>
using namespace std;

int evenodd(int n){
    /*
    1--> Even
    0--> Odd
    if(a&1){return 0;}
    else(return 1;)
    */
    if(n/2==0){
        return true;
    }
    else{
        return false;
    }
}

int main(){
int num;
cin >> num;

int ans  = evenodd(num);

if(ans){
    cout<<"Even"<<endl;
}
else{
    cout<<"Odd"<<endl;
}

}
