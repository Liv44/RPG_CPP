#include "./Monstre.hpp"
#include <string>
#include <cstdlib>
#include <ctime>

vector<Monstre*> Monstre::registeredMonster;


void Monstre::registerMonster(){
        Monstre::registeredMonster.push_back(this);
};

Monstre::Monstre(string name) : Character(name,Job::MonstreJob,800,40,15,300) {
    Monstre::registerMonster();
    attackNotChanged = physicalAttack;
}

void Monstre::groupAttack(){
    this->physicalAttack=physicalAttack / getRegisteredNumber();
    vector <Character *> allCharacters = Character::getOneCharacter();
    for (int i = 0; i < (allCharacters.size()); i++){
        Monstre::attack(*allCharacters[i]);
    }
    this->physicalAttack=attackNotChanged;
}

void Monstre::upDefense(){
    Monstre * thisMonstre = getOneMonster();
    thisMonstre->defense +=20;
}

int Monstre::getRegisteredMonster(){
    return Monstre::registeredMonster.size();
}

Monstre *  Monstre::getOneMonster(){
    //mettre un random pour le monstre.
    srand(time(NULL));
    int randomMonster = rand()%getRegisteredMonster();
    return Monstre::registeredMonster[randomMonster];
}

void Monstre::attackMonster(){
    vector <Character *> allCharacters = Character::getOneCharacter();
    int randomCharacter = rand()%getRegisteredNumber();
    Monstre::attack(*allCharacters[randomCharacter]);
}
// Mettre en place 3 actions : 
// Attaque normale sur une cible aléatoire 
// Attaque de groupe OK
// Augmentation de la défense OK