#include "./Priest.hpp"

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
    // int randomHeal = rand() % 200 + 201;
    other.heal(rand()%201 + 200);
}