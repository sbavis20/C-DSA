#include<iostream>
#include<stack>
using namespace std;

int main(){

    //create stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);


    //pop operation
    s.pop();

    cout<<"Top Element: "<<s.top()<<endl;

    if(s.empty()){
        cout<<"Empty..."<<endl;
    }else{
        cout<<"Not Empty..."<<endl;
    }


}
