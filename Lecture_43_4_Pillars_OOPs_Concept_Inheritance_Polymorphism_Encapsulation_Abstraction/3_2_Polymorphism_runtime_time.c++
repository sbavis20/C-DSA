#include<iostream>
using namespace std;
//depends on inheritance
//no of arguments
//

class Animal{
    public:
    void speak(){
        cout<<"Speaking..."<<endl;
    }
};

class Dog:public Animal{
    public:
    void speak(){
        cout<<"barking..."<<endl;
    }
};

int main(){
    Dog d;
    d.speak();
return 0;
}
