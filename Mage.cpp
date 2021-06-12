#include "./Mage.hpp"

Mage::Mage(string name) : Character(name,Job::MageJob,15,200,30,1000) {
    this->maxMp = 100;
    this->mp = 100;
    Character::registerPlayer();
}

bool Mage::tryUsingMp(int mp){
    if(this->mp < mp){
        return false;
    }
    this->mp -= mp;
    return true;
    Character::registerPlayer();
}

void Mage::fireball(Character& other){
    if(!tryUsingMp(this->maxMp*0.10f)){
        return;
    }
    int randomNumber = rand() % 10;
    if(randomNumber == 0){
        return;
    }
    other.receiveDamage(this->magicAttack);
}