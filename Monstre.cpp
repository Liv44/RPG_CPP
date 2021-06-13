#include "./Monstre.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
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
    vector <Character *> allCharacters = Character::getAllCharacters();
    for (int i = 0; i < (allCharacters.size()); i++){
        Monstre::attack(*allCharacters[i]);
    }
    this->physicalAttack=attackNotChanged;
    cout << "Le monstre fait une attaque de groupe !\n" << endl;
}

void Monstre::upDefense(){
    Monstre * thisMonstre = getOneMonster();
    thisMonstre->defense +=20;
    cout << "Le monstre fait gagner 20 points de défense à "<< thisMonstre->name <<"\n"<< endl;
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
    vector <Character *> allCharacters = Character::getAllCharacters();
    int randomCharacter = rand()%getRegisteredNumber();
    Character * oneCharacter = allCharacters[randomCharacter];
    Monstre::attack(*oneCharacter);
    cout << "Le monstre a attaqué"<< oneCharacter->name <<"\n"<< endl;

}
// Mettre en place 3 actions : 
// Attaque normale sur une cible aléatoire 
// Attaque de groupe OK
// Augmentation de la défense OK


void Monstre::monstreTurn(){
    int randomAction = 0;
    switch(randomAction) {
        case 0:
        this->groupAttack();
        case 1:
        this->upDefense();
        case 2:
        this->attackMonster();
    }
}