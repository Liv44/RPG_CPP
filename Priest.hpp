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
    Priest(string name);
    
    void healAllie(Character& other);
};

#endif 