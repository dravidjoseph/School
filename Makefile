LinkedList: main.o 
	g++ -g -std=c++11 main.o -o LinkedList
	
main.o: main.cpp 
	g++ -g -std=c++11 main.cpp
	
clean:
	rm *.o LinkedList
	echo clean done