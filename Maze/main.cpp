/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 8/12/15
* @brief: Driver for Maze Program
********************************************************/

#include <iostream>

#include "MazeWalker.h"
#include "MazeReader.h"
#include "MazeCreationException.h"

int main(int argc, char** argv){
	
	if(argc != 3){
		std::cout<<"Please run the program again, using three arguments.\n";
		return 0;
	}
	
	std::string fileName = argv[1];
	std::string search = argv[2];
	
	std::cout<<fileName<<"\n";
	std::cout<<search<<"\n";
	
	bool searchFlag;
	
	MazeReader* reader = nullptr;
	MazeWalker* walker = nullptr;
	
	if(search == "-dfs"){
		searchFlag = true;
	}
	else if(search == "-bfs"){
		searchFlag = false;
	}
	else{
		std::cout<<"Invalid search option.  Defaulting to bfs.";
	}
	
	std::cout<<searchFlag<<"\n";
	
	
	try{
		reader = new MazeReader(fileName);
	}
	catch(MazeCreationException& e){
		std::cout<<e.what();
	}
	
	
	try{
		walker = new MazeWalker(reader->getMaze(),reader->getStartRow(),reader->getStartCol(),reader->getRows(),reader->getCols(),searchFlag);
	}
	catch(MazeCreationException& e){
		std::cout<<e.what();
	}
	
	walker->walkMaze();
	
	
	delete reader;
	delete walker;
	reader = nullptr;
	walker = nullptr;
	
	
	return 0;
}