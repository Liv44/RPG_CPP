#include <cstdlib>
#include <ctime>
#include <iostream>
#include "./Character.hpp"
#include "./Barbarian.hpp"
#include "./Mage.hpp"
#include "./Potion.hpp"
#include "./Exceptions.hpp"
#include "./Priest.hpp"
#include "./Jeux.hpp"


using namespace std;

int main(int argc, char const *argv[])
{
    // Jeux jeux;

    // while (jeux.getPlaying()) {

        // jeux.menuPrincipale();

        try {

            srand(time(NULL));

            Mage gandalf("Gandalf");
            Barbarian conan("Conan");
            conan.enterFury();
            conan.attack(gandalf);

            conan.attack(gandalf);
            // cout << "Gandalf a " << gandalf.getCurrentHp() << " PV" << endl;

            cout << "Statut personnage:\n " << "Name: " << gandalf.name << "\n Class: " << gandalf.job <<"\n PV: "<< gandalf.hp << " / " << gandalf.maxHp  << endl;

            // gandalf.heal(rand()%201 + 200);

            // cout << "Gandalf a " << gandalf.getCurrentHp() << " PV" << endl;
            
            conan.enterFury();

            Potion small(3,100);
        
            gandalf += small;
            gandalf += small;
            gandalf += small;
            gandalf += small;
            cout << "All potions were drunk !" << endl;

        }
        catch(IllegalFury& illegalF){
            cout << "An illegal barbarian fury operation occured : " << illegalF.what() << endl;
        }
        catch(EmptyPotion& ep){
            cout << "An illegal barbarian fury operation occured : " << ep.what() << endl;
        }
        catch(std::exception& e){
            cout << "An exception occured : " << e.what() << endl;
        }

        cout << "End of combat" << endl;
    // }

    return 0;
}