#include "./Character.hpp"
#include <vector>
#include "./Jeux.hpp"
#include "./Monstre.hpp"
#include "./Potion.hpp"


vector<Character*> Character::registeredCharacters;




Character::Character(string name, Job job, int pAtt, int mAtt, int def, int maxHp, int speed){
    this->name = name;
    this->job = job;
    this->physicalAttack = pAtt;
    this->magicAttack = mAtt;
    this->defense = def;
    this->maxHp = maxHp;
    this->hp = maxHp;
    this->speed=speed;
    registerCharacter();
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
    string nameDefender = defender.name;
    defender.receiveDamage(damage);
    cout<< this->name<<" a attaqué "<<nameDefender<<" (- "<<damage<<"PV)."<<endl; 
}

int Character::getCurrentHp(){
    return this->hp;
}
int Character::getCurrentDef(){
    return this->defense;
}

void Character::registerCharacter(){
        Character::registeredCharacters.push_back(this);
};
void Character::registerPlayer(){
    Character::registeredPlayers.push_back(this);
   
}

int Character::getNumberPlayers(){
    return Character::registeredPlayers.size();
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
    cout<< "Défense : "<< this->getCurrentDef()<<"\n"<<endl;

}

void Character::playerTurn(){
    Character::checkingDeadGuys();
    cout << "C'est au tour de "<<this->name<<" de jouer\n"<<endl;

    if (this->job == 7){
        vector < Monstre *> allMonsters = Monstre::registeredMonsters;
        for (int i = 0; i < allMonsters.size(); i++){
            if (this->name == allMonsters[i]->name){
                Character::checkingDeadGuys();
                allMonsters[i]->monstreTurn();
                Character::checkingDeadGuys();
                break;
            }
        }
    } else {
        int choix;
    cout << "Il reste "<<Monstre::getNumberMonsters()<<" monstres"<<endl;
    cout << "1 : Attaquer." << endl;
    // cout << "2 : Attaque spéciale" << endl; 
        // Barbarian -> Furie/ Mage -> Boule de feu / Priest -> Soin
    // cout << "3 : Boire une potion" << endl; 
        // Le groupe disposera d'une potion commune au lancement du combat
    cout << "4 : Statut du personnage" << endl;
    // cout << "5 : Quit game ! " << endl;

    cout << endl << "Choix : ";
    cin >> choix;
    cout << "\n" << endl;

    switch(choix)
    {   
        case 1:
            int choix;
            cout<< "Qui voulez-vous attaquer ?"<<endl;
            for (int i = 0; i < Monstre::registeredMonsters.size(); i++){
                cout<< i+1 <<"- "<< Monstre::registeredMonsters[i]->name<< " a "<<Monstre::registeredMonsters[i]->getCurrentHp()<<"PV."<<endl;
                };
            cin >> choix;
            this->attack(*(Monstre::registeredMonsters[choix-1]));
            break;
        case 2:
            cout <<"Attaque spéciale !!!!"<<endl;
            // Créer l'attaque spéciale !!!
            break;
        case 3:
            // Potion small(1,100);
            // *this += small;
            break;
        case 4:
            this->statCharacter();
            this->playerTurn();
            break;
        case 5:
            // Jeux::playing = false;
            break;
        default:
            break;

    }
    }
    Character::checkingDeadGuys();
    
}

void Character::checkingDeadGuys(){
    vector<Monstre *> MonstersAlive = Monstre::registeredMonsters;
    vector<Character *> PlayersAlive = Character::registeredPlayers;
    vector<Character *> CharactersAlive = Character::registeredCharacters;


    for (int i = 0; i < MonstersAlive.size(); i++){
        if (MonstersAlive[i]->hp==0){
            cout<< MonstersAlive[i]->name<< " est mort !"<<endl;
            (Monstre::registeredMonsters).erase (Monstre::registeredMonsters.begin()+i);
        }
    }

    for (int i = 0; i < PlayersAlive.size(); i++){
        if (PlayersAlive[i]->hp==0){
            cout<< PlayersAlive[i]->name<< " est mort !"<<endl;
            (Character::registeredPlayers).erase (Character::registeredPlayers.begin()+i);
        }
    }
    for (int i = 0; i < CharactersAlive.size(); i++){
        if (CharactersAlive[i]->hp==0){
            (Character::registeredCharacters).erase (Character::registeredCharacters.begin()+i);
        }
    }
}
