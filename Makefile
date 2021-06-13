rpg : main.o Jeux.o Character.o Mage.o Barbarian.o Exceptions.o Potion.o Monstre.o
	g++ main.o Jeux.o Character.o Mage.o Barbarian.o Exceptions.o Potion.o Monstre.o -o rpg

main.o : main.cpp
	g++ -c main.cpp -o main.o

Jeux.o: Jeux.cpp Jeux.hpp
	g++ -c Jeux.cpp -o Jeux.o

Monstre.o : Monstre.cpp Monstre.hpp
	g++ -c Monstre.cpp -o Monstre.o

Character.o : Character.cpp Character.hpp
	g++ -c Character.cpp -o Character.o

Mage.o : Mage.cpp Mage.hpp
	g++ -c Mage.cpp -o Mage.o

Barbarian.o : Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp -o Barbarian.o

Exceptions.o : Exceptions.cpp Exceptions.hpp
	g++ -c Exceptions.cpp -o Exceptions.o

Potion.o : Potion.cpp Potion.hpp
	g++ -c Potion.cpp -o Potion.o

clean : 
	rm *.o
