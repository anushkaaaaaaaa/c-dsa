#include <iostream>
using namespace std;

class Hero{
    //properties
    public:
    //iske neeche likhi cheece kahi bhi accessible hai
    int health=100;
    char level='A';
    
    void print(){
        std::cout<<level<<endl;
    }
};

//Public members are accessible outside the class
//Private members are accessible inside the class
//Protected members are accessible inside and outside the class

