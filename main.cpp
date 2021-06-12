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

        cout << "Nombre de joueurs : " << Character::getRegisteredNumber()<<endl;
        cout << "Nombre de monstres : " << Monstre::getRegisteredMonster()<<endl;

        cout << "Gandalf a " << gandalf.getCurrentHp() << " PV" << endl;
        cout << "Conan a " << conan.getCurrentHp() << " PV" << endl;
        cout << "monstre1 a " << monstre1.getCurrentHp() << " PV\n" << endl;

        monstre1.groupAttack();
        cout<<"GROUP ATTACK"<<endl;
        cout << "Gandalf a " << gandalf.getCurrentHp() << " PV" << endl;
        cout << "Conan a " << conan.getCurrentHp() << " PV" << endl;
        cout << "monstre1 a " << monstre1.getCurrentHp() << " PV\n" << endl;

        monstre1.attackMonster();
        cout<<"ATTACK MONSTER"<<endl;
        cout << "Gandalf a " << gandalf.getCurrentHp() << " PV" << endl;
        cout << "Conan a " << conan.getCurrentHp() << " PV" << endl;
        cout << "monstre1 a " << monstre1.getCurrentHp() << " PV\n" << endl;

        cout << "monstre1 a " << monstre1.getCurrentDef()<< " defense"<<endl;
        monstre1.upDefense();
        cout<<"UP DEFENSE"<<endl;
        cout << "monstre1 a " << monstre1.getCurrentDef() << " defense"<<endl;
        cout << "monstre2 a " << monstre2.getCurrentDef() << " defense"<<endl;


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