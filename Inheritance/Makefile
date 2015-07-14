Animal: main.o PreconditionViolationException.o  FarmAnimal.o AnimalPen.o Cow.o Chicken.o CyberChicken.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o  FarmAnimal.o AnimalPen.o Cow.o Chicken.o CyberChicken.o -o Animal
	
main.o: main.cpp AnimalPen.h FarmAnimal.h StackInterface.h Stack.h Stack.hpp Node.h Node.hpp
	g++ -g -std=c++11 -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp
	
AnimalPen.o: AnimalPen.h AnimalPen.cpp StackInterface.h Stack.h Stack.hpp Node.h Node.hpp
	g++ -g -std=c++11 -Wall -c AnimalPen.cpp
	
FarmAnimal.o: FarmAnimal.h FarmAnimal.cpp
	g++ -g -std=c++11 -Wall -c FarmAnimal.cpp
	
Cow.o: Cow.h FarmAnimal.h Cow.cpp
	g++ -g -std=c++11 -Wall -c Cow.cpp
	
Chicken.o: Chicken.h FarmAnimal.h Chicken.cpp
	g++ -g -std=c++11 -Wall -c Chicken.cpp
	
CyberChicken.o: Chicken.h CyberChicken.h CyberChicken.cpp
	g++ -g -std=c++11 -Wall -c CyberChicken.cpp
	
	
	
clean:
	rm *.o Animal
	echo clean done