#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "./Potion.hpp"
#include <string>
#include <vector>
#include <iostream>


using namespace std;

enum Job {
    FreelancerJob,
    MageJob,
    WarriorJob,
    BarbarianJob,
    DruidJob,
    PriestJob,
    PaladinJob,
    MonstreJob
};



class Character
{


    public:
    string name;
    static vector<Character*> registeredCharacters;
    static vector<Character*> registeredPlayers;

    vector<Character *> getAllPlayers();
    int physicalAttack;
    int magicAttack;
    int defense;
    int maxHp;
    int hp;
    int speed;

    public:
    Job job;

    public:
    Character() : Character("John Doe",FreelancerJob,100,100,50,1000, 23){}

    Character(string name, Job job, int pAtt, int mAtt, int def, int maxHp, int speed);

    void heal(unsigned int healingValue);

    void drink(Potion& p);

    Character& operator+=(Potion& p);

    void attack(Character& defender);

    int getCurrentHp();
    int getCurrentDef();
    static int getNumberPlayers();
    void registerCharacter();
    void registerPlayer();

    void statCharacter();
    void playerTurn();
    void checkingDeadGuys();

    public:
    void receiveDamage(int damage);

    // Créer l'attaque spéciale ici
};


#endif