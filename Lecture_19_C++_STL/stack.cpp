#include<iostream>
#include<stack>

using namespace std;

int main(){

    stack<string> s;

    s.push("Sawamura");
    s.push("Bokuto");
    s.push("Kageyama");

    cout<<"top Element --> "<<s.top()<<endl;

    s.pop();
    cout<<"Top element after pop opr : "<<s.top()<<endl;

    cout<<"Size of stack : "<<s.size()<<endl;

    cout<<"Empty or Not "<<s.empty()<<endl;






}
