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
    void MageTurn();
    void monstreTurn(Monstre& oneMonstre);
    void yourTurn();
    void priestTurn();
    void barbarianTurn();
    vector<int> howsTurn();
    // Mage mage;
    // Priest priest;
    // Barbarian barbarian;

    static string mageName;
    static string priestName;
    static string barbarianName;

private:
    int choix;
    bool playing;
};

#endif
