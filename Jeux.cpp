#include "Jeux.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Mage.hpp"
#include "Priest.hpp"

Jeux::Jeux()
{
    choix = 0;
    playing = true;
}

////////////////////////////////////////////////// INTRO /////////////////////////////////////////////////////////////////////////////////////////

void Jeux::initJeux(){
    cout << "Entrer nom du personnage: " << endl;
}

void Jeux::job(){
    cout << "Choississez votre classe :\n" << endl;

    cout << "1 : Mage" << endl;
    cout << "2 : Prètre" << endl;
    cout << "3 : Barbarian" << endl;;
    cout << endl << "Choix : ";
    cin >> choix;

    switch(choix)
    {   
        case 1:
            cout << "Vous avez choisit la classe Mage" << endl;
            Job::MageJob;

        case 2:
            cout << "Vous avez choisit la classe Prètre" << endl;
            Job::PriestJob;

        case 3:
            cout << "Vous avez choisit la classe Barbarian" << endl;
            Job::BarbarianJob;

        default:
            Jeux::menuPrincipale();

    }
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
            cout << "Vous avez attaqué le monstre n°1" << endl;
            Jeux::menuPrincipale();

        case 2:
            cout << "Vous avez attaqué le monstre n°2" << endl;
            Jeux::menuPrincipale();

        case 3:
            cout << "Vous avez attaqué le monstre n°3" << endl;
            Jeux::menuPrincipale(); 
            
        case 4:
            Jeux::menuPrincipale();
            break;
        default:
            break;

    }

}

/////////////////////////////////////////////STATS PERSONNAGE ////////////////////////////////////////////////////////////////////////////////////

void Jeux::statPerso()
{
    cout << "Statut personnage:\n " << endl;
    cout << "Name: "  << endl; Jeux::initJeux();
    cout << "Class: " << endl; Jeux::job();
    cout << "PV: "<< 100 << " / " <<  1000<< endl;
}

///////////////////////////////////////// MENU DU JEU ////////////////////////////////////////////////////////////////////////////////////////////

void Jeux::menuPrincipale()
{
    cout << "Menu Principale" << endl;
    cout << "1 : Attaque" << endl;
    cout << "2 : Action de la classe" << endl; // Barbarian -> Furie/ Mage -> Boule de feu / Priest -> Soin
    cout << "3 : Boire une potion" << endl; // Le groupe disposera d'une potion commune au lancement du combat
    cout << "4 : Statut personnage" << endl;
    cout << "5 : Do nothing " << endl;
    cout << "6 : Quit game ! " << endl;

    cout << endl << "Choix : ";
    cin >> choix;
    cout << "\n" << endl;

    switch(choix)
    {   
        case 1:
            Jeux::encounter();
        case 2:
            Jeux::job();
        case 4: 
            Jeux::statPerso();
        case 5:
            playing = false;
            break;
        default:
            break;

    }
}
