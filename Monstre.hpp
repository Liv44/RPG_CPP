#ifndef MONSTRE_HPP
#define MONSTRE_HPP
#include "./Character.hpp"
#include <string>
#include <cstdlib>

using namespace std;


class Monstre : public Character {
    void registerMonster();
    Monstre * getOneMonster();
    int dividedAttack;
    int attackNotChanged;

    public:
    static vector<Monstre*> registeredMonsters;
    int speed = rand() % 20;
    Monstre(string name);
    void groupAttack();
    void upDefense();
    static int getNumberMonsters();
    void attackMonster();
    void monstreTurn();

};

#endif