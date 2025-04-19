#include<iostream>
using namespace std;

int score = 22;

void a(int& i){
    cout<<i<<endl;
    cout<<score<<endl;

}

void b(int& i){
    cout<<i<<endl;
    cout<<score<<endl;
}

int main(){
    int i =5;
    a(i);
    cout<<score<<endl;
    return 0;
}
