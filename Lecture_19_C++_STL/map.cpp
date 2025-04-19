#include<iostream>
#include<map>

using namespace std;

int main(){

    map<int,string> m;

    m[1] = "Q";
    m[2] = "W";
    m[5] = "R";
    m[7] = "T";
    m[11] = "Y";

    m.insert(   {8,"U"}  );

    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;

    m.erase(8);
    cout<<"After erase oper : "<<endl;
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }cout<<endl;


    auto it = m.find(5);

    for(auto i = it; i!=m.end();i++){
        cout<<(*i).first<<endl;
    }cout<<endl;








}
