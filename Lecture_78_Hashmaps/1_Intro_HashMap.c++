#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;



int main(){
    unordered_map<string,int> m;

    //insert
    pair<string,int> p =make_pair("naruto",3);
    m.insert(p);

    pair<string,int> pair2("7th",2);
    m.insert(pair2);

    m["hokage"]=1;

    //search
    cout<<m["7th"]<<endl;
    cout<<m.at("hokage")<<endl;
    //cout<<m.at("leaf")<<endl; //not found entry not present
    //cout<<m["leaf"]<<endl; //will create a entry for leaf

    //size
    cout<<m.size()<<endl;

    //to check presence
    cout<<m.count("village");

    //erase
    m.erase("7th");

    //method 1
    // for(auto i:m){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }

    //iterators
    unordered_map<string,int>::iterator it = m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

    return 0;
}
