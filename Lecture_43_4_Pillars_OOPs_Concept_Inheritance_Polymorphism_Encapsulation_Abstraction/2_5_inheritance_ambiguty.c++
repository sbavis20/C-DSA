#include<iostream>
using namespace std;

//Hierachical Inheritance
class A{
    public:
        void funA(){
            cout<<"A function "<<endl;
        }
};

class B{
    public:
        void funA(){
            cout<<"B function "<<endl;
        }
};

class C:public A,public B{
    public:
    void funC(){
        cout<<"C function "<<endl;
    }
};

int main(){

    C c;
    //c.funA();//abiguty
    c.A::funA();
    c.funC();

    return 0;
}
