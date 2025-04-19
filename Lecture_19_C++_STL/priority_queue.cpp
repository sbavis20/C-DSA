#include<iostream>
#include<queue>

using namespace std;

int main(){

priority_queue <int> maxi; //MAX heap

priority_queue<int,vector<int>,greater<int> > mini; //MIN Heap

maxi.push(88);
maxi.push(22);
maxi.push(9);
maxi.push(1);
maxi.push(0);

cout<<"Size of MAX heap : "<<maxi.size()<<endl;

int max_heap_size =  maxi.size();

for (int i =0; i< max_heap_size;i++){
    cout<<maxi.top()<<" ";
    maxi.pop();
}cout<<endl;





mini.push(88);
mini.push(22);
mini.push(9);
mini.push(1);
mini.push(0);

cout<<"Size of MIN heap : "<<mini.size()<<endl;

int mini_heap_size =  mini.size();

for (int i =0; i< mini_heap_size;i++){
    cout<<mini.top()<<" ";
    mini.pop();
}cout<<endl;




}
