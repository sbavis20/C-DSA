#include<iostream>
using namespace std;

//Hierachical Inheritance
class A{
    public:
        void funA(){
            cout<<"A function "<<endl;
        }
};

class B: public A{
    public:
        void funB(){
            cout<<"B function "<<endl;
        }
};

class C:public A{
    public:
    void funC(){
        cout<<"C function "<<endl;
    }
};

int main(){

    A a;
    a.funA();

    B b;
    b.funA();
    b.funB();

    C c;
    c.funA();
    c.funC();

    return 0;
}
