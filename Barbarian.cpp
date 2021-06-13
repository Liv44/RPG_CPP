#include "./Barbarian.hpp"

Barbarian::Barbarian(string name) : Character(name,Job::BarbarianJob,200,0,15,900, 15) {
    baseAttack = this->physicalAttack;
    baseDefense = this->defense;
    inFury = false; 
    registerPlayer();
}

void Barbarian::enterFury(){
    if( inFury ){
        throw IllegalFury(true);
    }
    baseAttack = this->physicalAttack;
    baseDefense = this->defense;
    inFury = true;
    physicalAttack *= 1.5f;
    defense = 0;
    this->receiveDamage(maxHp*0.15f);
}

void Barbarian::leaveFury(){
    if(!inFury){
        throw IllegalFury(false);
    }
    physicalAttack = baseAttack;
    defense = baseDefense;
    inFury = false;
}