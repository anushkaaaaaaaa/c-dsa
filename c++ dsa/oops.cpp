#include <iostream>
#include "hero.cpp"
using namespace std;

class Hero{
    private:
    int health;

    public:
    char level;
}

void print(){
    cout<<level<<endl;
    
}
//Parameterised constructor
Hero(int health){
    this -> health = health;
}

Hero(int health,char level){
    this -> health = health;
    this -> level = level;

}

//copy constructor

Hero(Hero& temp){
    this -> health = temp.health;
    this -> level = temp.level;
}

void print(){
    cout<<"health: "<<this->health<<endl;
    cout<<"level: "<<this->level<<endl;
}

int getHealth(){
    return health;
}

char getLevel(){
    return level;
}

void setHealth(int h){
    health = h;
}

void setLevel(char ch){
    level = ch;
}


int main() {
    //creation of Object

    Hero h1;
    //size ke jagah ek garbage value dal gyi
    cout<<"size : "<<sizeof(h1)<<endl;
    cout<<"health of : " <<h1.health<<endl;
    cout<<"level of: "<<h1.level<<endl;

    return 0;
}

