#ifndef PRIEST_HPP
#define PRIEST_HPP
#include "./Character.hpp"
#include <string>
#include <cstdlib>

using namespace std;

class Priest : public Character {
    private:
    int mp;
    int maxMp;
    bool tryUsingMp(int mp);

    public:
    int speed = 10;
    Priest(string name) : Character(name,Job::PriestJob,25,200,20,1000), maxMp(100), mp(100){}
    void healAllie(Character& other);
};

#endif 