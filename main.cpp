#include <cstdlib>
#include <ctime>
#include <iostream>
#include "./Character.hpp"
#include "./Barbarian.hpp"
#include "./Mage.hpp"
#include "./Potion.hpp"
#include "./Exceptions.hpp"
#include "./Priest.hpp"
#include "./Monstre.hpp"
#include "./Jeux.hpp"


using namespace std;

int main(int argc, char const *argv[])
{   
    Jeux jeux;
    
    try {
    
        srand(time(NULL));

        jeux.intro();
        Monstre monstre1("monstre1");
        Monstre monstre2("monstre2");
        Monstre monstre3("monstre3");
        string mageName = "Le Mage";
        string priestName = "Le Prêtre";
        string barbarianName = "Le Barbare";


        Mage mage(mageName);
        Barbarian barbarian(barbarianName);
        Priest priest(priestName);
        mage.statCharacter();
        barbarian.statCharacter();
        priest.statCharacter();

        do{
            vector <Character *> allCharactersSorted = Jeux::howsTurn();
            cout << "NOUVEAU TOUR DE JEU !!! \nVoici l'ordre de ce tour : ";
            for (int i = 0; i < allCharactersSorted.size(); i++){
                cout << allCharactersSorted[i]->name<<" ";
            }
            cout<< "."<<endl;

        for (int i = 0; i < allCharactersSorted.size(); i++){
            if (allCharactersSorted[i]->getCurrentHp()>0){
                allCharactersSorted[i]->playerTurn();
            }
            if (Monstre::registeredMonsters.size()==0){
                cout << "Bravo! Vous avez vaincu les monstres !" << endl;
                break;
            } else if (Character::registeredPlayers.size()==0){
                cout<< "Dommage, vous avez perdu."<<endl;
            }
        };
        } while (Character::registeredPlayers.size()==0 || Monstre::registeredMonsters.size()!=0) ;
    }
        catch(EmptyPotion& ep){
            cout << "An illegal barbarian fury operation occured : " << ep.what() << endl;
        }

        cout << "End of combat" << endl;

        return 0;
}