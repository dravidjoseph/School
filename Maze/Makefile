Maze: main.o MazeWalker.o MazeReader.o MazeCreationException.o Position.o
	g++ -g -std=c++11 main.o MazeWalker.o MazeReader.o MazeCreationException.o Position.o -o Maze
	
main.o: main.cpp MazeWalker.h MazeReader.h MazeCreationException.h
	g++ -g -std=c++11 -c main.cpp
	
MazeCreationException.o: MazeCreationException.h MazeCreationException.cpp
	g++ -g -std=c++11 -c MazeCreationException.cpp
	
MazeReader.o: MazeReader.h MazeCreationException.h MazeReader.cpp
	g++ -g -std=c++11 -c MazeReader.cpp
	
Position.o: Position.h Position.cpp
	g++ -g -std=c++11 -c Position.cpp
	
MazeWalker.o: MazeWalker.h MazeWalker.cpp
	g++ -g -std=c++11 -c MazeWalker.cpp
	
	
clean:
	rm *.o Maze
	echo clean done