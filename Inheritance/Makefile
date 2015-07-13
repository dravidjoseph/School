Animal: main.o PreconditionViolationException.o Cow.o Chicken.o CyberChicken.o FarmAnimal.o AnimalPen.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o Cow.o Chicken.o CyberChicken.o FarmAnimal.o AnimalPen.o -o Animal
	
main.o: main.cpp StackInterface.h Stack.h Stack.hpp AnimalPen.h Cow.h CyberChicken.h
	g++ -g -std=c++11 -Wall main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp
	
AnimalPen.o