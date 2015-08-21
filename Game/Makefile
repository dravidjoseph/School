Game: main.o Pokemon.o Colosseum.o Dice.o
	g++ -g -std=c++11 main.o Pokemon.o Colosseum.o Dice.o -o Game
	
main.o: Pokemon.h Colosseum.h Dice.h main.cpp
	g++ -g -std=c++11 -c main.cpp

Pokemon.o: Pokemon.h Dice.h Pokemon.cpp
	g++ -g -std=c++11 -c Pokemon.cpp
	
Colosseum.o: Pokemon.h Colosseum.h Colosseum.cpp
	g++ -g -std=c++11 -c Colosseum.cpp
	
Dice.o: Dice.h Dice.cpp
	g++ -g -std=c++11 -c Dice.cpp
	
clean:
	rm *.o Game
	echo clean done
	
	