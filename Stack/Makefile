Stack: main.o PreconditionViolationException.o Test.o
	g++ -g -std=c++11 -Wall main.o PreconditionViolationException.o Test.o -o Stack
	
main.o: main.cpp Test.h StackInterface.h Stack.h Stack.hpp Node.h Node.hpp
	g++ -g -std=c++11 -Wall -c main.cpp

PreconditionViolationException.o: PreconditionViolationException.h PreconditionViolationException.cpp
	g++ -g -std=c++11 -Wall -c PreconditionViolationException.cpp
	
Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp
	
clean:
	rm *.o Stack
	echo clean done