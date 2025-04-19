#include<iostream>
#include<vector>

using namespace std;

int main(){

vector<int> a(5,1);
//a(size,element)  all will be 1 in vector
cout<<"Print a"<<endl;
for(int i:a){
    cout<<i<<" ";
}

//copy a vector
vector<int> last(a);
cout<<"Print last"<<endl;
for(int i:last){
    cout<<i<<" ";
}


    vector<int>v;
cout<<"Capicity : "<<v.capacity()<<endl;
v.push_back(1);

cout<<"Capicity : "<<v.capacity()<<endl;

v.push_back(2);
cout<<"Capicity : "<<v.capacity()<<endl;

v.push_back(3);
cout<<"Capicity : "<<v.capacity()<<endl;

cout<<"Size : "<<v.size()<<endl;

cout<<"Element at 2nd Index : "<<v.at(2)<<endl;

cout<<"Front : "<<v.front()<<endl;

cout<<"Back : "<<v.back()<<endl;

cout<<"Before pop "<<endl;
for(int i:v){
    cout<<i<<" ";
}cout<<endl;

v.pop_back();

cout<<"After pop "<<endl;
for(int i:v){
    cout<<i<<" ";
}cout<<endl;

cout<<"before clear size : "<<v.size()<<endl;
v.clear();
cout<<"Afetr clear size : "<<v.size()<<endl;

}
