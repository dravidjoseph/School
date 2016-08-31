/*******************************************************
* @file: MazeReader.cpp
* @author: Dravid Joseph
* @date: 11/16/15
* @brief: Implementation file for MazeReader Class
********************************************************/

#include "MazeReader.h"

MazeReader::MazeReader(std::string file) throw (MazeCreationException){
	
	fileName = file;	//stores filename in instance variable for readMaze
	//Open filestream object
	input.open(fileName);
	
	//if file isn't accessible, throw exception
	if(!input.good()){
		throw MazeCreationException("Invalid filename");
	}
	
	//File accessible, read metadata
	input >> m_rows;
	input >> m_cols;
	input >> m_startRow;
	input >> m_startCol;
	
	//Check for bad metadata and throw exceptions as necessary
	if(m_rows < 1 || m_cols < 1){
		throw MazeCreationException("Invalid dimensions");
	}
	
	if(m_startRow < 0 || m_startRow >= m_rows || m_cols < 0 || m_startCol >= m_cols){
		throw MazeCreationException("Invalid Starting Position");
	}
	
	//initialize character pointer array
	maze = new char*[m_rows];
	//initialize each character pointer as a character array
	for(int i = 0;i < m_rows; i++){
		maze[i] = new char[m_cols];
	}
	
	//Let readMaze actually store the characters
	try{
		readMaze();
	}
	catch(MazeCreationException& e){
		std::cout<<e.what();
	}
}

MazeReader::~MazeReader(){
	
	for(int i = 0; i < m_rows;i++){
		delete maze[i];
		maze[i] = nullptr;
	}
	
	delete maze;
	maze = nullptr;
	
	//let stack-allocated variables be deleted automatically
}

const char* const* MazeReader::getMaze() const{
	return maze;
}

int MazeReader::getCols() const{
	return m_cols;
}

int MazeReader::getRows() const{
	return m_rows;
}

int MazeReader::getStartCol() const{
	return m_startCol;
}

int MazeReader::getStartRow() const{
	return m_startRow;
}

//assume properly formatted file
void MazeReader::readMaze() throw (MazeCreationException){
	

	for(int i = 0; i < m_rows; i++){
		for (int j = 0; j < m_cols; j++){
			input >> maze[i][j];
		}
	}
		
	//close file
	input.close();
	
}