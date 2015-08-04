prog: main.o NumberFileDriver.o NumberFileGenerator.o SortDriver.o
	g++ -g -std=c++11 -Wall main.o NumberFileDriver.o NumberFileGenerator.o SortDriver.o -o prog
	
main.o: main.cpp Sorts.h Sorts.hpp NumberFileDriver.h NumberFileGenerator.h SortDriver.h
	g++ -g -std=c++11 -Wall -c main.cpp
	
NumberFileDriver.o: NumberFileDriver.h NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -g -std=c++11 -Wall -c main.cpp NumberFileDriver.cpp
	
NumberFileGenerator.o: NumberFileGenerator.h NumberFileGenerator.cpp
	g++ -g -std=c++11 -Wall -c main.cpp NumberFileGenerator.cpp
	
SortDriver.o: NumberFileGenerator.h SortDriver.h Sorts.h Sorts.hpp SortDriver.cpp
	g++ -g -std=c++11 -Wall -c main.cpp SortDriver.cpp
	
clean:
	rm *.o prog
	echo clean done