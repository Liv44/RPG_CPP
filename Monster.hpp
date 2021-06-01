#ifndef MONSTER_HPP
#define MONSTER_HPP
#include <string>
#include <iostream>
#include <ostream>
#include <iterator>

using namespace std;

class Monster
{
    public:

    int physicalAttack;
    int hp;
    int maxHp;
    int defense;
    string name;

    Monster();
};

#endif