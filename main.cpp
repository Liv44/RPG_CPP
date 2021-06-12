#include <cstdlib>
#include <ctime>
#include <iostream>
#include "./Character.hpp"
#include "./Barbarian.hpp"
#include "./Mage.hpp"
#include "./Potion.hpp"
#include "./Exceptions.hpp"
#include "./Monstre.hpp"


using namespace std;

int main(int argc, char const *argv[])
{
    
    
    try {
        srand(time(NULL));
        Mage gandalf("Gandalf");
        Barbarian conan("Conan");
        Monstre monstre1("monstre1");
        Monstre monstre2("monstre2");

        monstre1.groupAttack();
        conan.attack(gandalf);
        conan.attack(gandalf);
        monstre1.attack(gandalf);
        gandalf.attack(monstre1);
        cout << "Nombre de joueurs : " << Character::getRegisteredNumber()<<endl;
        cout << "Nombre de monstres : " << Monstre::getRegisteredMonster()<<endl;
        // cout << "test :"<<gandalf.getOneCharacter()->name<<endl;



        cout << "Gandalf a " << gandalf.getCurrentHp() << " PV" << endl;
        cout << "monstre1 a " << monstre1.getCurrentHp() << " PV" << endl;
        monstre1.groupAttack();
        cout << "Gandalf a " << gandalf.getCurrentDef() << " DEF" << endl;

        cout << "monstre1 a " << monstre1.getCurrentDef()<< " defense"<<endl;
        monstre1.upDefense();
        cout << "monstre1 a " << monstre1.getCurrentDef()<< " defense"<<endl;

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


    
    return 0;
}