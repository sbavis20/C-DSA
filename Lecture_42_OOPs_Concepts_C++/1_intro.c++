#include<iostream>
#include <string.h>
using namespace std;

class Hero{
    //properties
    public:
    char *name;
    int health;
    char level;
    static int timeToComplete;

    void print(){
        cout<<"Name : "<<this->name<<", ";
        cout<<"Health : "<<this->health<<", ";
        cout<<"Level : "<<this->level<<endl;
        cout<<endl;
    }

    int getHealth(){
        return health;
    }

    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health=h;
    }

    void setLevel(char ch){
        level=ch;
    }

    //simple contructor
    Hero(){
        cout<<"Default contructor called"<<endl;
        name = new char[100];
    }

    //parameterised contructor
    Hero(int health){
        // cout<<"this-> ka address "<<this<<endl;
        this->health=health;
    }

    Hero(int health,char level){
        // cout<<"this-> ka address "<<this<<endl;
        this->health=health;
        this->level=level;
    }

    //copy contructor
    // Hero(Hero& temp){
    //     cout<<"Copy Contructor Called"<<endl;
    //     this-> health=temp.health;
    //     this->level = temp.level;
    // }

    Hero(Hero& temp){
        char *ch = new char[strlen(temp.name)];

        strcpy(ch,temp.name);
        this-> name =ch;

        cout<<"Copy Contructor Called"<<endl;
        this-> health=temp.health;
        this->level = temp.level;
    }

    void setName(char name[]){
        strcpy(this->name,name);
    }

    //desctructor
    ~Hero(){
        cout<<"Desctructor called"<<endl;
    }

    static int random(){
        //cout<<this->health<<endl;
        cout<<timeToComplete<<endl;
    }
};

int Hero::timeToComplete =5;

int main(){

    //static functions
    //this keyword X
    //object create X
    //static fun can access only static member
    cout<<Hero::random()<<endl;


   // cout<<Hero::timeToComplete<<endl; //try to it like this bcoz its class belongs doent not belong to object

    // Hero a;

    // cout<<a.timeToComplete<<endl; //works but not needed

    //destructor --> memory deaallocate
    //same as class
    // no return type
    // no ip para

    // //static
    // Hero a;
    // //destructur for static called automatically

    // //dynamic
    // Hero *h1 = new Hero();
    // // called manually
    // delete h1;

    // //contructor and destructor called only one time each for a object


    // //copy assingment operator
    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // char name[7] = "Naruto";
    // hero1.setName(name);
    // hero1.print();

    // //use defualt copy constructor
    // Hero hero2(hero1);
    // hero2.print();

    // hero1.name[0]='B';
    // hero1.print();
    // hero2.print();

    // hero1 = hero2;
    // hero1.print();
    // hero2.print();

    // //deep copy call selfmade copy contructor
    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // char name[7] = "Naruto";
    // hero1.setName(name);
    // hero1.print();

    // //use defualt copy constructor
    // Hero hero2(hero1);
    // hero2.print();

    // hero1.name[0]='B';
    // hero1.print();
    // hero2.print();

    /*Name : Baruto, Health : 12, Level : D

Name : Naruto, Health : 12, Level : D*/






// // //deafult copy constructor --> shallow copy
//     Hero hero1;
//     hero1.setHealth(12);
//     hero1.setLevel('D');
//     char name[7] = "Naruto";
//     hero1.setName(name);
//     hero1.print();

//     //use defualt copy constructor
//     Hero hero2(hero1);
//     hero2.print();

//     hero1.name[0]='B';
//     hero1.print();
//     hero2.print();
//     //shallow copy
//     /*Name : Baruto, Health : 12, Level : D

//     Name : Baruto, Health : 12, Level : D*/


    // Hero minato(999,'S');
    // minato.print();

    // //copy contructor
    // Hero naruto(minato);
    // naruto.print();


    //object created statically
    // Hero a(15,'S');
    // // cout<<"Address of a: "<<&a<<endl;
    // a.print();
    // //dynamically
    // Hero *h = new Hero(25);
    // h->print();

    // Hero temp(99,'S');
    // temp.print();


    //static allocation

    // Hero a;
    // a.setHealth(95);
    // a.setHealth('B');
    // cout<<"Level is: "<<a.level<<endl;
    // cout<<"health is: "<<a.getHealth()<<endl;
    // //dynamic allocation
    // Hero *b = new Hero;
    // b->setLevel('A');
    // b->setHealth(70);
    // cout<<"Level is "<<(*b).level<<endl;
    // cout<<"Health is "<<(*b).getHealth()<<endl;

    // cout<<"Level is "<<b->level<<endl;
    // cout<<"Health is "<<b->getHealth()<<endl;

    // Hero ramesh;
    // cout<<"Health is: "<<ramesh.getHealth()<<endl;
    // ramesh.health = 70;
    // ramesh.level='A';
    // cout<<"Health is: "<<ramesh.getHealth()<<endl;
    // cout<<"Level is: "<<ramesh.getLevel()<<endl;

    //creation of object


    //Hero h1;

    //cout<<"Size : "<<sizeof(h1)<<endl;

    return 0;
}
