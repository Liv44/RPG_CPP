#include "Jeux.hpp"

Jeux::Jeux()
{
    choix = 0;
    playing = true;
}

void Jeux::menuPrincipale()
{
    cout << "Menu Principale" << endl;
    cout << "1 : Attaque" << end;
    cout << "2 : Action de la classe" << endl; // Barbarian -> Furie/ Mage -> Boule de feu / Priest -> Soin
    cout << "3 : Boire une potion" << endl; // Le groupe disposera d'une potion commune au lancement du combat
    cout << "4 : Do nothing " << endl;
    cout << "5 : Quit game ! " << endl;

    cout << endl << "Choix : ";
    cin >> Choix;

    switch(choix)
    {
        case 5:
            playing = false;
            break;
        default:
            break;

    }
}