#ifndef MAGE_HPP
#define MAGE_HPP
#include "./Character.hpp"
#include <string>
#include <cstdlib>

using namespace std;

class Mage : public Character {
    private:
    int mp;
    int maxMp;
    bool tryUsingMp(int mp);

    public:
    Mage(string name);
    void fireball(Character& other);
};

#endif