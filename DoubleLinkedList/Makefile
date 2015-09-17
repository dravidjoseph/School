DoubleLinkedList: main.o Test.o
	g++ -g -std=c++11 -Wall main.o Test.o -o DoubleLinkedList
	
main.o: main.cpp DoubleLinkedList.h DoubleLinkedList.hpp Node.h Node.hpp
	g++ -g -std=c++11 -Wall -c main.cpp
	
Test.o: Test.h Test.cpp
	g++ -g -std=c++11 -Wall -c Test.cpp
	
clean:
	rm *.o DoubleLinkedList
	echo clean done