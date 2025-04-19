#include<iostream>
#include<list>

using namespace std;

int main(){

list<int> l1;
list<int> l2(l1); //copy l1 into l2

list<int> l3(5,100);
for(int i:l3){
    cout<<i<<" ";
}cout<<endl;

list<int> l;

l.push_front(1);
l.push_back(2);

for(int i:l){
    cout<<i<<" ";
}cout<<endl;

l.erase(l.begin());
cout<<"After erase "<<endl;
for(int i:l){
    cout<<i<<" ";
}cout<<endl;


cout<<"Size of list : "<<l.size()<<endl;







}
