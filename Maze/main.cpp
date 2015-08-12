/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 8/10/15
* @brief: Driver for Maze Program
********************************************************/



int main(int argc, char** argv){
	
	if(argc != 3){
		std::cout<<"Please run the program again, using three arguments.\n";
		return 0;
	}
	
	std::string fileName = argv[1];
	std::string search = argv[2];
	bool searchFlag = false;
	
	if(!(search == "-dfs" && search == "-bfs")){
		std::cout<<"Not a valid search option.\n";
	}
	else if(search == "-dfs"){
		searchFlag = true;
	}
	
	
	try{
		MazeReader* reader = new MazeReader(fileName);
	}
	catch(MazeCreationException& e){
		std::cout<<e.what();
	}
	
	try{
		MazeWalker walker = new MazeWalker(reader->getMaze(),reader->getStartRow(),reader->getStartCol(),reader->getRows(),reader->getCols(),searchFlag);
	}
	catch(MazeCreationException& e){
		std::cout<<e.what()
	}
	
	walker->walkMaze();
	
	
	delete reader;
	delete walker;
	reader = nullptr;
	walker = nullptr;
	
	
	return 0;
}