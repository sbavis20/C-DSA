#include<iostream>
using namespace std;

class Human{
    public:
        int hieght;
        int age;
        int wieght;

        public:
            int getAge(){
                return this->age;
            }

            void setWieght(int w){
                this->wieght=w;
            }

};

class Male: public Human{
    public:
        string color;
    public:
    void Sleep(){
        cout<<"Male Sleeping..."<<endl;
    }
};

int main(){
    Male m1;

    cout<<"Hieght: "<<m1.hieght<<endl;
    cout<<"Wieght: "<<m1.wieght<<endl;
    cout<<"Age: "<<m1.age<<endl;
    cout<<"color: "<<m1.color<<endl;

    m1.Sleep();

    return 0;
}
