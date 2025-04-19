#include<iostream>
using namespace std;

int main(){
    char a1;
    cout<<"Entera charcter: "<<endl;
    cin>>a1;

    int a = a1;
    cout<<a<<endl;
    if(a>=48 && a<=57 ){
        cout<<"0-9"<<endl;
    }
    else if (a>=65 && a<=90){
        cout<<"Capital A-Z"<<endl;
    }
    else{
        cout<<"LowerCase a-z"<<endl;
    }


}
