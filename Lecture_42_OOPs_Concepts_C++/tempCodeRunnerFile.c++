    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Naruto";
    hero1.setName(name);
    hero1.print();

    //use defualt copy constructor
    Hero hero2(hero1);
    hero2.print();

    hero1.name[0]='B';
    hero1.print();
    hero2.print();
