<<<<<<< HEAD
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

    //Stat des persos
    void statCharacters(Character& oneCharacter);
    // Attaque et stats Mage
    void mageAttaque();

    // Attaque et stats Prètre
    void priestAttaque();

    // Attaque et stats Prètre
    void barbarianAttaque();

    // Tour dans l'ordre
    void monstreTurn(Monstre& oneMonstre);

    // Mage mage;
    // Priest priest;
    // Barbarian barbarian;

    string mageName;
    string priestName;
    string barbarianName;
    
    public:
    bool playing;

private:
    int choix;
};

#endif
=======
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

    //Stat des persos
    void statCharacters(Character& oneCharacter);
    // Attaque et stats Mage
    void mageAttaque();

    // Attaque et stats Prètre
    void priestAttaque();

    // Attaque et stats Prètre
    void barbarianAttaque();

    // Tour dans l'ordre
    void monstreTurn(Monstre& oneMonstre);
    static vector<Character *> howsTurn();
    // Mage mage;
    // Priest priest;
    // Barbarian barbarian;

    string mageName;
    string priestName;
    string barbarianName;
    
    public:
    bool playing;

private:
    int choix;
};

#endif
>>>>>>> origin/develop
