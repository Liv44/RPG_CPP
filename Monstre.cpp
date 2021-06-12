#include "./Monstre.hpp"
#include <string>

vector<Monstre*> Monstre::registeredMonster;


void Monstre::registerMonster(){
        Monstre::registeredMonster.push_back(this);
};

Monstre::Monstre(string name) : Character(name,Job::MonstreJob,400,40,125,700) {
    Monstre::registerMonster();
}

void Monstre::groupAttack(){
    this->defense = 0;
}

void Monstre::upDefense(){
    Monstre * thisMonstre = getOneMonster();
    thisMonstre->defense +=20;
}

int Monstre::getRegisteredMonster(){
    Monstre::registeredMonster[0];
    return Monstre::registeredMonster.size();
}

Monstre *  Monstre::getOneMonster(){
    return Monstre::registeredMonster[0];
    // On peut récupérer le premier monstre. 
}
// Mettre en place 3 actions : 
// Attaque normale sur une cible aléatoire 
// Attaque de groupe
// Augmentation de la défense