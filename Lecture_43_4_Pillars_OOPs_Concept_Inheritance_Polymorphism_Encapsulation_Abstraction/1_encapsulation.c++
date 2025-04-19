#include<iostream>
using namespace std;

class Student{
    private:
        string name;
        int age;
        int height;

    public:
    int getAge(){
        return this->age;
    }
    void setAge(int a){
        this->age=a;
    }
};

int main(){
    Student s1;
    s1.setAge(18);
    cout<<"Age: "<<s1.getAge()<<endl;


    return 0;
}
