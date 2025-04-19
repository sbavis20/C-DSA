#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue <string> q;

    q.push("Q");
    q.push("S");
    q.push("A");

    cout<<"Top Element : "<<q.front()<<endl;

    q.pop();
    cout<<"Top element after pop opr : "<<q.front()<<endl;

    cout<<"Size afetr pop opr : "<<q.size()<<endl;





}
