#ifndef MONSTRE_HPP
#define MONSTRE_HPP
#include "./Character.hpp"
#include <string>
#include <cstdlib>

using namespace std;

class Monstre : public Character {
    static vector<Monstre*> registeredMonster;
    
    void registerMonster();
    Monstre * getOneMonster();

    public:
    Monstre(string name);
    void groupAttack();
    void upDefense();
    static int getRegisteredMonster();


};

#endif