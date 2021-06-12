#include "Jeux.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Mage.hpp"
#include "Priest.hpp"
#include "Potion.hpp"

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

void Jeux::encounter()
{
    cout << "Attaque : \n" << endl;
    cout << "1 : Attaque monstre n°1" << endl;
    cout << "2 : Attaque monstre n°2" << endl;
    cout << "3 : Attaque monstre n°3" << endl;
    cout << "4 : Back to menu !" << endl;
    cout << endl << "Choix : ";
    cin >> choix;

    switch(choix)
    {   
        case 1:
            cout << "Vous avez attaqué le monstre n°1\n" << endl;
            // mage.attack(monster1)
        case 2:
            cout << "Vous avez attaqué le monstre n°2\n" << endl;
            // mage.attack(monster2)
        case 3:
            cout << "Vous avez attaqué le monstre n°3\n" << endl;
            // mage.attack(monster3)
        case 4:

        default:
            break;

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

void Jeux::mageAttaque()
{
    cout << "MAGE TURN:\n" << endl;
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
            Jeux::encounter();
        case 2:
            Jeux::encounter();
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
            Jeux::encounter();
        case 2:
            Jeux::encounter();
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
            Jeux::encounter();
        case 2:
            Jeux::encounter();
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
