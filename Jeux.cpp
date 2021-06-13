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
            break;
        
        case 2:
            playing = false;
            break;

        default:
            break;
    }
}  

///////////////////////////////////////////// NOM PERSONNAGE ////////////////////////////////////////////////////////////////////////////////////

Mage mage("test");
Priest priest("test");
Barbarian barbarian("test");
Monstre monstre1("monstre1");
Monstre monstre2("monstre2");
Monstre monstre3("monstre3");


/////////////////////////////////// PERSONNAGE VS MONSTRE /////////////////////////////////////////////////////////////////////////////////////

void Jeux::mageAttaque()
{
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
        // Jeux::MageTurn();

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
        // Jeux::priestTurn();

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

