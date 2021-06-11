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

    void initJeux();
    void menuPrincipale();
    void statPerso();
    void encounter();
    void job();

    inline bool getPlaying() const {return this->playing; }

private:
    int choix;
    bool playing;

    // Encounter 
};

#endif