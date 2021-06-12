#ifndef JEUX_HPP
#define JEUX_HPP
#include <iostream>
#include <ostream>
#include <iterator>

using namespace std;

class Jeux
{   
public:
    Jeux();

    void intro();
    void namePerso();
    void mageAttaque();
    void priestAttaque();
    void barbarianAttaque();
    void statMage();
    void encounter();

    inline bool getPlaying() const {return this->playing; }

    string mageName;
    string priestName;
    string barbarianName;

private:
    int choix;
    bool playing;
    // Encounter 
};

#endif
