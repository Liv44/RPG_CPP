#include "Monster.hpp"

Monster::Monster(string name, int pAtt, int def, int maxHp)
{
    this->name = name;
    this->physicalAttack = pAtt;
    this->defense = def;
    this->maxHp = maxHp;
    this->hp = maxHp;

};