#include "Jeux.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Mage.hpp"
#include "Priest.hpp"
#include "Potion.hpp"
#include "Monstre.hpp"

Jeux::Jeux(){
    choix = 0;
    playing = true;
    
}



////////////////////////////////////////////////// INTRO /////////////////////////////////////////////////////////////////////////////////////////
void Jeux::intro(){
    cout << "Ah vous voilà enfin ! Bienvenue sur notre jeu RPG\n" << endl; 
    cout << "Les règles sont simples, le but de notre jeu est de choisir une action a faire effectuer par vos personnages sur vos ennemies ou alliés.\n" << endl;
    cout << "Pour finir le jeu il faudra que soit l'équipe allié battent l'équipe des montres ou vise versa.\n" << endl;
    cout << "Sur ce bonne aventure et surtout bonne chance !\n" << endl;

    cout << "1 : START YOUR ADVENTURE !" << endl;
    cout << "2 : QUIT !" << endl;
    cout << endl << "Choix : ";
    cin >> choix;

    switch(choix)
    {   
        case 1:
            playing = true;
        
        case 2:
            playing = false;
            break;

        default:
            break;
    }
}  

///////////////////////////////////////////// NOM PERSONNAGE ////////////////////////////////////////////////////////////////////////////////////

void Jeux::namePerso(){
    cout << "Entrer le nom de votre Mage: " << endl;
    cin >> mageName;
    cout << "Le nom de votre mage est " << mageName<< endl;

    cout << "\nEntrer le nom de votre Prètre: " << endl;
    cin >> priestName;
    cout << "Le nom de votre prètre est " << priestName << endl;


    cout << "\nEntrer le nom de votre Barbarian: " << endl;
    cin >> barbarianName;
    cout << "Le nom de votre barbarian est " << barbarianName << "\n" << endl;

}

Mage mage(Jeux::mageName);
Priest priest(Jeux::priestName);
Barbarian barbarian(Jeux::barbarianName);
Monstre monstre1("monstre1");
Monstre monstre2("monstre2");
Monstre monstre3("monstre3");


/////////////////////////////////// PERSONNAGE VS MONSTRE /////////////////////////////////////////////////////////////////////////////////////

void Jeux::mageAttaque()
{   
    Monstre monstre1("monstre1");
    Monstre monstre2("monstre2");
    Monstre monstre3("monstre3");

    cout << "Attaque : \n" << endl;
    cout << "1 : Attaque monstre n°1 qui a " << monstre1.getCurrentHp() << " PV" << endl;
    cout << "2 : Attaque monstre n°2 qui a " << monstre2.getCurrentHp() << " PV" <<endl;
    cout << "3 : Attaque monstre n°3 qui a " << monstre3.getCurrentHp() << " PV" <<endl;
    cout << "4 : Back to menu !" << endl;
    cout << endl << "Choix : ";
    cin >> choix;

    if (choix == 1){
        cout << "Vous avez attaqué le monstre n°1\n" << endl;
        mage.attack(monstre1);
        cout << "monstre n°1 a " << monstre1.getCurrentHp() << " PV\n" << endl;

    } else if (choix == 2) {
        cout << "Vous avez attaqué le monstre n°2\n" << endl;
        mage.attack(monstre2);
        cout << "monstre n°2 a " << monstre2.getCurrentHp() << " PV\n" << endl;

    } else if (choix == 3) {
        cout << "Vous avez attaqué le monstre n°3\n" << endl;
        mage.attack(monstre3);
        cout << "monstre n°3 a " << monstre3.getCurrentHp() << " PV\n" << endl;

    } else if (choix == 4){
        Jeux::MageTurn();

    } else {
        cout << "Choisit un chiffre valable !\n" << endl;
    }

}

void Jeux::priestAttaque(){
    cout << "Attaque : \n" << endl;
    cout << "1 : Attaque monstre n°1 qui a " << monstre1.getCurrentHp() << " PV" << endl;
    cout << "2 : Attaque monstre n°2 qui a " << monstre2.getCurrentHp() << " PV" <<endl;
    cout << "3 : Attaque monstre n°3 qui a " << monstre3.getCurrentHp() << " PV" <<endl;
    cout << "4 : Back to menu !" << endl;
    cout << endl << "Choix : ";
    cin >> choix;

    if (choix == 1){
        cout << "Vous avez attaqué le monstre n°1\n" << endl;
        priest.attack(monstre1);
        cout << "monstre n°1 a " << monstre1.getCurrentHp() << " PV\n" << endl;

    } else if (choix == 2) {
        cout << "Vous avez attaqué le monstre n°2\n" << endl;
        priest.attack(monstre2);
        cout << "monstre n°2 a " << monstre2.getCurrentHp() << " PV\n" << endl;

    } else if (choix == 3) {
        cout << "Vous avez attaqué le monstre n°3\n" << endl;
        priest.attack(monstre3);
        cout << "monstre n°3 a " << monstre3.getCurrentHp() << " PV\n" << endl;

    } else if (choix == 4){
        Jeux::priestTurn();

    } else {
        cout << "Choisit un chiffre valable !\n" << endl;
    }
}

/////////////////////////////////////////////STATS PERSONNAGE ////////////////////////////////////////////////////////////////////////////////////
void Jeux::statCharacters(Character& oneCharacter){
    cout << "Statut du personnage : "<< oneCharacter.name<<endl;
    cout<< "Classe : "<<oneCharacter.job<<endl;
    cout<< "PV :"<< oneCharacter.getCurrentHp()<<endl;
}

///////////////////////////////////////// TOUR ET ATTAQUE DES PERSONNAGES ////////////////////////////////////////////////////////////////////////////////////////////

void Jeux::monstreTurn(Monstre& oneMonstre){
    int randomAction = rand()%3;
    switch(randomAction) {
        case 0:
        oneMonstre.groupAttack();
        case 1:
        oneMonstre.upDefense();
        case 2:
        oneMonstre.attackMonster();
    }
}

void Jeux::yourTurn(){
    cout << "C'est ton tour. Qui veux-tu faire jouer ? "<< endl;
    cout << "1 - Barbarian" << endl;
    cout << "2 - Priest" << endl;
    cout << "3 - Mage" << endl;
    cin >> choix;

    switch (choix){
        case 1:
        cout<<"Tu as choisi le Barbarian"<<endl;
        case 2:
        cout<<"Tu as choisi le Priest"<<endl;
        case 3:
        cout<<"Tu as choisi le Mage"<<endl;
    }
}

void Jeux::MageTurn()
{
    cout << "MAGE TURN:\n" << endl;
    cout << "Nombre de joueurs : " << Character::getRegisteredNumber()<<endl;
    cout << "Nombre de monstres : " << Monstre::getRegisteredMonster()<<endl;
    cout << "1 : Attaque basic" << endl;
    cout << "2 : Boule de feu" << endl; // Barbarian -> Furie/ Mage -> Boule de feu / Priest -> Soin
    cout << "3 : Boire une potion" << endl; // Le groupe disposera d'une potion commune au lancement du combat
    cout << "4 : Statut personnage" << endl;
    cout << "5 : Quit game ! " << endl;

    cout << endl << "Choix : ";
    cin >> choix;
    cout << "\n" << endl;

    switch(choix)
    {   
        case 1:
            Jeux::mageAttaque();
        case 2:
            Jeux::mageAttaque();
        case 3:
            // Potion small(1,300);
        case 4: 
            // Jeux::statCharacters();
        case 5:
            playing = false;
            break;
        default:
            break;

    }
}

void Jeux::priestTurn()
{
    cout << "PRIEST TURN:\n" << endl;
    cout << "Nombre de joueurs : " << Character::getRegisteredNumber()<<endl;
    cout << "Nombre de monstres : " << Monstre::getRegisteredMonster()<<endl;
    cout << "1 : Attaque basic" << endl;
    cout << "2 : Soin" << endl; // Barbarian -> Furie/ Mage -> Boule de feu / Priest -> Soin
    cout << "3 : Boire une potion" << endl; // Le groupe disposera d'une potion commune au lancement du combat
    cout << "4 : Statut personnage" << endl;
    cout << "5 : Quit game ! " << endl;

    cout << endl << "Choix : ";
    cin >> choix;
    cout << "\n" << endl;

    switch(choix)
    {   
        case 1:
            Jeux::priestAttaque();
        case 2:
            Jeux::priestAttaque();
        case 3:
            // Potion small(1,300);
        case 4: 
            // Jeux::statPriest();
        case 5:
            playing = false;
            break;
        default:
            break;

    }
}

void Jeux::barbarianAttaque()
{
    cout << "BARBARIAN TURN:\n" << endl;
    cout << "1 : Attaque -> basic" << endl;
    cout << "2 : Attaque -> Furie mode" << endl; // Barbarian -> Furie/ Mage -> Boule de feu / Priest -> Soin
    cout << "3 : Boire une potion" << endl; // Le groupe disposera d'une potion commune au lancement du combat
    cout << "4 : Statut personnage" << endl;
    cout << "5 : Quit game ! " << endl;

    cout << endl << "Choix : ";
    cin >> choix;
    cout << "\n" << endl;

    switch(choix)
    {   
        case 1:
            // Jeux::encounter();
        case 2:
            // Jeux::encounter();
        case 3:
            // Potion small(1,300);
        case 4: 
            // Jeux::statMage();
        case 5:
            playing = false;
            break;
        default:
            break;

    }
}
