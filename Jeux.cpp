#include "Jeux.hpp"
#include "Character.hpp"
#include "Barbarian.hpp"
#include "Mage.hpp"
#include "Priest.hpp"
#include "Potion.hpp"
#include "Monstre.hpp"
#include "iostream"

using namespace std;

Jeux::Jeux()
{
    choix = 0;
    playing = true;
}

Monstre monstre1("monstre1");
Monstre monstre2("monstre2");
Monstre monstre3("monstre3");
Barbarian barbare("barbare");
Mage mage("mage");
Priest priest("pretre");
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
        //Jeux::MageTurn();

    } else {
        cout << "Choisit un chiffre valable !\n" << endl;
    }

}

void Jeux::priestAttaque(){
    Priest priest(priestName);
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
        //Jeux::priestTurn();

    } else {
        cout << "Choisit un chiffre valable !\n" << endl;
    }
}
///////////////////////////////////////// TOUR ET ATTAQUE DES PERSONNAGES ////////////////////////////////////////////////////////////////////////////////////////////
vector<Character *> Jeux::howsTurn() 
{
    vector<Character*> AllCharact = Character::registeredCharacters;
    int i = 0;
    Character* save;
    cout << AllCharact.size()<<endl;
    while (i != AllCharact.size() -2) {
        if (AllCharact[i]->speed > AllCharact[i+1]->speed) {
            save = AllCharact[i];
            AllCharact[i] = AllCharact[i + 1];
            AllCharact[i+1] = save;
            i = 0;
        } else {
            i++;
        } 
    }
    cout << AllCharact[0] <<" "<<AllCharact[1]<<" "<<AllCharact[2]<<" "<<AllCharact[3]<<" "<<AllCharact[4]<<" "<<AllCharact[5]<<endl;
    return(AllCharact);
}
