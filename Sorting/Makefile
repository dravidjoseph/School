Sorts: main.o
	g++ -g -std=c++11 -Wall main.o -o Sorts
	
main.o: main.cpp Sorts.h Sorts.hpp
	g++ -g -std=c++11 -Wall -c main.cpp
	
clean:
	rm *.o Sorts
	echo clean done