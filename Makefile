LinkedList: main.o Node.o
	g++ -g -std=c++11 main.o Node.o -o LinkedList
	
main.o: main.cpp Node.h
	g++ -g -std=c++11 -c main.cpp
	
Node.o: Node.h Node.cpp
	g++ -g -std=c++11 -c Node.cpp
	
clean:
	rm *.o LinkedList
	echo clean done