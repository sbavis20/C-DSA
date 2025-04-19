#include<iostream>
using namespace std;

class A{
    public:
    void sayHello(){
        cout<<"Hello Sawamura "<<endl;
    }

    //overloaded function
    void sayHello(string name){
        cout<<"Hello Sawamura "<<endl;
    }


};

class B{
    public:
    int a;
    int b;

    int add(){
        return a+b;
    }

    void operator+ (B &obj){
        int value1 = this->a;
        int value2 = this->b;
        cout<<"Output "<<value2-value1<<endl;    }

};

int main(){

    B b;
    b.a = 1;
    b.b= 2;
    cout<<" "<<b.add()<<endl;


    B b1;
    b1.a =3;
    b1.b= 5;
   b+b1;

return 0;
}
