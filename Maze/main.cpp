/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 11/16/15
* @brief: Driver for Maze Program
********************************************************/

#include <iostream>

#include "MazeReader.h"
#include "MazeWalker.h"
#include "MazeCreationException.h"
#include "Test.h"


int main(int argc, char** argv){
	
	if(argc != 3 && argc != 2){
		return 0;
	}
	std::string searchType = argv[1];
	if(argc == 2 && searchType.compare("-test") == 0){
		
		Test myTest;
		myTest.runTests();
		return 0;
	}
	
	
	std::string file = argv[2];
	
	
	if(!(searchType.compare("-dfs") == 0 || searchType.compare("-bfs") == 0)){
		return 0;
	}
	
	MazeReader* maze = nullptr;
	MazeWalker* walker = nullptr;
	
	try{
		maze = new MazeReader(file);
	}
	catch(MazeCreationException& e){
		std::cout<<e.what();
		return 0;
	}
	
	if(searchType.compare("-dfs") == 0){
		walker = new MazeWalker(maze->getMaze(),maze->getStartRow(),maze->getStartCol(),maze->getRows(),maze->getCols(),Search::DFS);
	}
	else{
		walker = new MazeWalker(maze->getMaze(),maze->getStartRow(),maze->getStartCol(),maze->getRows(),maze->getCols(),Search::BFS);
	}
	
	std::cout<<"Starting Position: "<<maze->getStartRow()<<","<<maze->getStartCol()<<"\n";
	std::cout<<"Size: "<<maze->getRows()<<","<<maze->getCols()<<"\n";
	
	bool goal = walker->walkMaze();
	
	const int* const* visited = walker->getVisited();
	
	for(int i = 0; i < maze->getRows(); i++){
		for(int j = 0; j < maze->getCols(); j++){
			std::cout<<visited[i][j]<<"\t";
		}
		std::cout<<"\n";
	}
	
	if(goal){
		std::cout<<"We escaped!\n";
	}
	else{
		std::cout<<"No way out!\n";
	}
	
	delete maze;
	delete walker;
	maze = nullptr;
	walker = nullptr;
	
	
	return 0;
}
