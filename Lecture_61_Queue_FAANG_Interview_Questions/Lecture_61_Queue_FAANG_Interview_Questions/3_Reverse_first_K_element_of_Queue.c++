#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int>q,int k){
  stack<int> s;

  for(int i=0;i<k;i++){
    int val = q.front();
    q.pop();
    s.push(val);

  }

  while(!s.empty()){
    int val = s.top();
    s.pop();
    q.push(val);
  }

  int i = q.size().k;

  while(t--){
    int val = q.front();
    q.pop();
    q.push(val);
  }

  return q;
}
