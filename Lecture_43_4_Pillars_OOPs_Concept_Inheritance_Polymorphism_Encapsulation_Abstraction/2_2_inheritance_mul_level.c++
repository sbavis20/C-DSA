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


class Dog: public Animal{


};

//Multi level inheritance
class GermanShephard:public Dog{

};

int main(){
    GermanShephard g;
    g.speak();


    return 0;
}
