#include "Priest.hpp"


Priest::Priest(string name) : Character(name,Job::PriestJob,200,0,15,900,15){
    this->maxMp=100;
    this->mp=100;
    registerPlayer();
}


bool Priest::tryUsingMp(int mp){
    if(this->mp < mp){
        return false;
    }
    this->mp -= mp;
    return true;
}

void Priest::healAllie(Character& other){

    if(!tryUsingMp(this->maxMp*0.10f)){
            return;
    }
    other.heal(rand()%200 + 201);
} 