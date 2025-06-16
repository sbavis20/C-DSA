#include<iostream>
#include<bits/stdc++.h>

using namespace std;


int main(){
  queue<int> q;

  q.push(11);
  cout<<"Front is: "<<q.front()<<endl;
  q.push(5);
  q.push(10);


  cout<<"Size of Queue: "<<q.size()<<endl;

  q.pop();

  cout<<"Size of Queue after pop : "<<q.size()<<endl;

  if(q.empty()){
    cout<<"Empty..."<<endl;
  }else{
    cout<<"Not Empty..."<<endl;
  }
  return 0;
}
