#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "./Character.hpp"
#include <string>
#include "./Exceptions.hpp"

using namespace std;

class Barbarian : public Character {
    private:
    int baseAttack;
    int baseDefense;
    bool inFury;

    public:
    int speed = 15;
    Barbarian(string name);
    void enterFury();
    void leaveFury();
};


#endif