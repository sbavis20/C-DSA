#include<iostream>
#include<deque>

using namespace std;

int main(){

deque<int> d;

d.push_back(1);
d.push_front(2);

for(int i:d){
    cout<<i<<" ";
}cout<<endl;

cout<<"Element at First Index : "<<d.at(1)<<endl;

cout<<"Front "<<d.front()<<endl;
cout<<"Back "<<d.back()<<endl;

cout<<"Empty or Not "<<d.empty()<<endl;

d.pop_front();
for(int i:d){
    cout<<i<<" ";
}cout<<endl;
d.pop_front();
for(int i:d){
    cout<<i<<" ";
}cout<<endl;


d.push_back(1);
d.push_front(2);

cout<<"Before erase size"<<d.size()<<endl;

d.erase(d.begin(),d.begin()+1);

cout<<"After erase size"<<d.size()<<endl;
for(int i:d){
    cout<<i<<" ";
}cout<<endl;


}
