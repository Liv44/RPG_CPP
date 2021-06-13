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

    // Intro
    void intro();

    // Choix nom des personnages
    void namePerso();

    // Attaque et stats Mage
    void mageAttaque();
    void statMage();

    // Attaque et stats Prètre
    void priestAttaque();
    void statPriest();

    // Attaque et stats Prètre
    void barbarianAttaque();
    void statBarbarian();

    // Tour dans l'ordre
    void MageTurn();
    void monstre1Turn();
    void priestTurn();
    void monstre2Turn();
    void barbarianTurn();
    void monstre3Turn();

    void howsTurn();

    string mageName;
    string priestName;
    string barbarianName;

private:
    int choix;
    bool playing;
};

#endif
