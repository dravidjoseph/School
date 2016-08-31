lab2: main.o
	g++ -g -std=c++11 -Wall main.o -o lab2
	
main.o: main.cpp LinkedList.h LinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -Wall -c main.cpp
	
clean:
	rm *.o lab2
	echo clean done