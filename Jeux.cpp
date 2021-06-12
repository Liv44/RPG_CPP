#include "Jeux.hpp"
#include "./Character.hpp"
#include "./Barbarian.hpp"
#include "./Mage.hpp"
#include "./Priest.hpp"
#include "./Potion.hpp"
#include "Monstre.hpp"

Jeux::Jeux()
{
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
        case 1:;
        
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
    Mage mage(mageName);

    cout << "\nEntrer le nom de votre Prètre: " << endl;
    cin >> priestName;
    cout << "Le nom de votre prètre est " << priestName << endl;
    Priest priest(priestName);

    cout << "\nEntrer le nom de votre Barbarian: " << endl;
    cin >> barbarianName;
    cout << "Le nom de votre barbarian est " << barbarianName << "\n" << endl;
    Barbarian barbarian(barbarianName);

}
/////////////////////////////////// PERSONNAGE VS MONSTRE /////////////////////////////////////////////////////////////////////////////////////

void Jeux::mageAttaque()
{   
    Mage mage(mageName);
    Monstre monstre1("monstre1");
    Monstre monstre2("monstre2");
    Monstre monstre3("monstre3");

    cout << "Attaque : \n" << endl;
    cout << "1 : Attaque monstre n°1" << "monstre1 a " << monstre1.getCurrentHp() << " PV" << endl;
    cout << "2 : Attaque monstre n°2" << "monstre2 a " << monstre2.getCurrentHp() << " PV" <<endl;
    cout << "3 : Attaque monstre n°3" << "monstre3 a " << monstre3.getCurrentHp() << " PV" <<endl;
    cout << "4 : Back to menu !" << endl;
    cout << endl << "Choix : ";
    cin >> choix;

    if(choix == 1){
        cout << "Vous avez attaqué le monstre n°1\n" << endl;
        mage.attack(monstre1);
        cout << "monstre1 a " << monstre1.getCurrentHp() << " PV" << endl;

    } else if (choix == 2) {
        cout << "Vous avez attaqué le monstre n°2\n" << endl;
        mage.attack(monstre2);
        cout << "monstre2 a " << monstre2.getCurrentHp() << " PV" << endl;

    } else if (choix == 3) {
        cout << "Vous avez attaqué le monstre n°3\n" << endl;
        mage.attack(monstre3);
        cout << "monstre3 a " << monstre3.getCurrentHp() << " PV" << endl;

    } else if (choix == 4){
        Jeux::MageTurn();

    } else {
        cout << "Choisit un chiffre valable !\n" << endl;
    }

}

/////////////////////////////////////////////STATS PERSONNAGE ////////////////////////////////////////////////////////////////////////////////////

void Jeux::statMage()
{
    cout << "Statut personnage:\n " << endl;
    cout << "Name: "<< mageName << endl;
    cout << "Class: " << Job::MageJob << endl;
    cout << "PV: "<< "" << " / " << "" << endl;
}

///////////////////////////////////////// TOUR ET ATTAQUE DES PERSONNAGES ////////////////////////////////////////////////////////////////////////////////////////////

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
            Jeux::statMage();
        case 5:
            playing = false;
            break;
        default:
            break;

    }
}

void Jeux::priestAttaque()
{
    cout << "PRIEST TURN:\n" << endl;
    cout << "1 : Attaque -> basic" << endl;
    cout << "2 : Attaque -> Soin" << endl; // Barbarian -> Furie/ Mage -> Boule de feu / Priest -> Soin
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
            Jeux::statMage();
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
            Jeux::statMage();
        case 5:
            playing = false;
            break;
        default:
            break;

    }
}
