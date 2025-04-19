#include<iostream>
using namespace std;

class Animal{
    public:
        int age;
        int wieght;

        public:
        void bark(){
            cout<<"Barking..."<<endl;
        }


};

class Human{
    public:
    string color;

    public:
    void Speak(){
        cout<<"Speaking..."<<endl;
    }
};

//Muliple Inheritance
class Hybrid: public Animal,public Human{


};




int main(){
    Hybrid h;
    h.Speak();
    h.bark();

    return 0;
}
