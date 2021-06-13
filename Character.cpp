#include "./Character.hpp"
#include <vector>
#include "./Jeux.hpp"
#include "./Monstre.hpp"
#include "./Potion.hpp"


vector<Character*> Character::registeredPlayer;


Character::Character(string name, Job job, int pAtt, int mAtt, int def, int maxHp){
    this->name = name;
    this->job = job;
    this->physicalAttack = pAtt;
    this->magicAttack = mAtt;
    this->defense = def;
    this->maxHp = maxHp;
    this->hp = maxHp;

}


void Character::heal(unsigned int healingValue) {
    if( hp + healingValue > maxHp){
        hp = maxHp;
    }
    else {
        hp += healingValue;
    }
}

void Character::drink(Potion& p){
    this->heal(p.getHealedHp());
}

Character& Character::operator+=(Potion& p){
    this->drink(p);
    return *this;
}

void Character::attack(Character& defender) {
    int damage = this->physicalAttack - defender.defense;
    defender.receiveDamage(damage);
}

int Character::getCurrentHp(){
    return this->hp;
}
int Character::getCurrentDef(){
    return this->defense;
}

void Character::registerPlayer(){
        Character::registeredPlayer.push_back(this);
};

int Character::getRegisteredNumber(){
    return Character::registeredPlayer.size();
}




void Character::receiveDamage(int damage){
    if(damage < 0) {
        damage = 0;
    }
    if(this->hp - damage < 0){
        this->hp = 0;
    }
    else {
        this->hp -= damage;
    }
}

vector<Character *> Character::getAllCharacters(){
    vector<Character *> allCharacters;
    for (int i = 0; i < (Character::registeredPlayer.size()); i++){
        allCharacters.push_back(Character::registeredPlayer[i]);
    }
    return allCharacters;
}


void Character::statCharacter(){
    cout << "Statut du personnage : "<< this->name<<endl;
    string jobName;
    switch(this->job){
        case 0 : jobName = "Freelancer"; break;
        case 1 : jobName = "Mage"; break;
        case 2 : jobName = "Warrior"; break;
        case 3 : jobName = "Barbarian"; break;
        case 4 : jobName = "Druid"; break;
        case 5 : jobName = "Priest"; break;
        case 6 : jobName = "Paladin"; break;
        case 7 : jobName = "Monstre";
    }
    cout<< "Classe : "<<jobName<<endl;
    cout<< "PV :"<< this->getCurrentHp()<<endl;
}

void Character::playerTurn(){
    int choix;
    cout << "C'est au tour de "<<this->name<<" de jouer"<<endl;
    cout << "Il reste "<<Monstre::getRegisteredMonster()<<" montres"<<endl;
    cout << "1 : Attaque basic" << endl;
    cout << "2 : Attaque spéciale" << endl; // Barbarian -> Furie/ Mage -> Boule de feu / Priest -> Soin
    cout << "3 : Boire une potion" << endl; // Le groupe disposera d'une potion commune au lancement du combat
    cout << "4 : Statut du personnage" << endl;
    cout << "5 : Quit game ! " << endl;

    cout << endl << "Choix : ";
    cin >> choix;
    cout << "\n" << endl;

    switch(choix)
    {   
        case 1:
            int choix;
            cout<< "Qui voulez-vous attaquer ?"<<endl;
            for (int i = 0; i < Monstre::registeredMonster.size(); i++){
                cout<< i+1 << Monstre::registeredMonster[i]->name<<i+1<< "a "<<Monstre::registeredMonster[i]->getCurrentHp()<<"PV"<<endl;
                };
            cin >> choix;
            this->attack(*(Monstre::registeredMonster[choix-1]));
            break;
        case 2:
            cout <<"Attaque spéciale !!!!"<<endl;
            break;
        case 3:
            // Potion small(1,300);
            // Character::Character += small;
        case 4:
            this->statCharacter();
            break;
        case 5:
            // Jeux::playing = false;
            break;
        default:
            break;

    }
}
