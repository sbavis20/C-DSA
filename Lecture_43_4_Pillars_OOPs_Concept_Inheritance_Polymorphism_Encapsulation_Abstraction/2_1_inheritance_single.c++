#include<iostream>
using namespace std;

class Animal{
    public:
        int age;
        int wieght;

        public:
        void speak(){
            cout<<"Speaking..."<<endl;
        }


};

//single inheritance
class Dog: public Animal{
    public:

};



int main(){
    Dog d;
    d.speak();


    return 0;
}
