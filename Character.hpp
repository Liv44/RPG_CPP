#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "./Potion.hpp"
#include <string>
#include <vector>

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
    static vector<Character*> registeredPlayer;
    vector<Character *> getOneCharacter();
    int physicalAttack;
    int magicAttack;
    int defense;
    int maxHp;
    int hp;

    private:
    Job job;

    public:
    Character() : Character("John Doe",FreelancerJob,100,100,50,1000){}

    Character(string name, Job job, int pAtt, int mAtt, int def, int maxHp);

    void heal(unsigned int healingValue);

    void drink(Potion& p);

    Character& operator+=(Potion& p);

    void attack(Character& defender);

    int getCurrentHp();
    int getCurrentDef();
    static int getRegisteredNumber();
    void registerPlayer();

    public:
    void receiveDamage(int damage);

};


#endif