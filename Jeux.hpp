#ifndef JEUX_HPP
#define JEUX_HPP
#include <iostream>
#include <ostream>
#include <iterator>
#include "Character.hpp"
#include "Monstre.hpp"


using namespace std;

class Jeux
{   
public:
    Jeux();

    // Intro
    void intro();

    // Choix nom des personnages
    void namePerso();
    static vector<Character *> howsTurn();


    string mageName;
    string priestName;
    string barbarianName;
    
    public:
    bool playing;

private:
    int choix;
};

#endif
