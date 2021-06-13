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
    cout << "Le nom de votre prêtre est " << priestName << endl;

    cout << "\nEntrer le nom de votre Barbarian: " << endl;
    cin >> barbarianName;
    cout << "Le nom de votre barbarian est " << barbarianName << "\n" << endl;

}
///////////////////////////////////////// TOUR ET ATTAQUE DES PERSONNAGES ////////////////////////////////////////////////////////////////////////////////////////////
vector<Character *> Jeux::howsTurn() 
{
    vector<Character*> AllCharact = Character::registeredCharacters;
    int i = 0;
    Character* save;
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
    return(AllCharact);
}
