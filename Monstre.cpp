#include "./Monstre.hpp"
#include "./Character.hpp"
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>

vector<Monstre*> Monstre::registeredMonsters;
vector<Character*> Character::registeredPlayers;


void Monstre::registerMonster(){
        Monstre::registeredMonsters.push_back(this);
};
Monstre::Monstre(string name) : Character(name,Job::MonstreJob,800,40,15,300, rand() % 20) {
    Monstre::registerMonster();
    attackNotChanged = physicalAttack;
}

void Monstre::groupAttack(){
    cout <<this->name << " fait une attaque de groupe !\n" << endl;

    this->physicalAttack=physicalAttack / getNumberPlayers();
    vector <Character *> allCharacters = Character::registeredPlayers;
    for (int i = 0; i < (allCharacters.size()); i++){
        Monstre::attack(*allCharacters[i]);
    }
    this->physicalAttack=attackNotChanged;
}

void Monstre::upDefense(){
    Monstre * thisMonstre = getOneMonster();
    thisMonstre->defense +=20;
    cout << "Le monstre fait gagner 20 points de défense à "<< thisMonstre->name <<"\n"<< endl;
}

int Monstre::getNumberMonsters(){
    return Monstre::registeredMonsters.size();
}

Monstre *  Monstre::getOneMonster(){
    //mettre un random pour le monstre.
    srand(time(NULL));
    int randomMonster = rand()%getNumberMonsters();
    return Monstre::registeredMonsters[randomMonster];
}

void Monstre::attackMonster(){
    vector <Character *> allCharacters = Character::registeredPlayers;
    int randomCharacter = rand()%getNumberPlayers();
    Character * oneCharacter = allCharacters[randomCharacter];
    cout << "Le monstre attaque "<< oneCharacter->name <<"\n"<< endl;

    Monstre::attack(*oneCharacter);
}


void Monstre::monstreTurn(){
    int randomAction = rand()%3;
    switch(randomAction) {
        case 0:
        this->groupAttack();
        break;
        case 1:
        this->upDefense();
        break;
        case 2:
        this->attackMonster();
        break;
    }
}