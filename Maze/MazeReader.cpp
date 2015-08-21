/*******************************************************
* @file: MazeReader.cpp
* @author: Dravid Joseph
* @date: 8/12/15
* @brief: Implementation file for MazeReader Class
********************************************************/

#include "MazeReader.h"

MazeReader::MazeReader(std::string file) throw (MazeCreationException){
	
	fileName = file;
	
	try{
		readMaze();
	}
	catch(MazeCreationException& e){
		std::cout<<e.what();
	}
	
	
}
	
MazeReader::~MazeReader(){
	
	for(int i = 0;i < m_cols;i++){
		delete[] maze[i];
	}
	
	delete[] maze;
}
	
char** MazeReader::getMaze() const{
	return maze;
}
	
int MazeReader::getCols() const{
	return m_cols;
}
	
int MazeReader::getRows() const{
	return m_rows;
}
int MazeReader::getStartCol() const{
	return m_startRow;
}
	
int MazeReader::getStartRow() const{
	return m_startCol;
}

void MazeReader::readMaze() throw (MazeCreationException){
	
	input.open(fileName);
	
	if(!input.good()){
		throw MazeCreationException("File not accessible");
	}
	else{
		
		input >> m_rows;
		input >> m_cols;
		input >> m_startRow;
		input >> m_startCol;
	}
	
	if(m_rows <= 0 || m_cols <= 0 || m_startRow < 0 || m_startCol < 0 || m_startCol > m_cols || m_startRow > m_rows){
		throw MazeCreationException("Error with Parameters");
	}
	
	maze = new char*[m_rows];
	
	for(int i = 0;i < m_rows;i++){
		maze[i] = new char[m_cols];
	}
	
	for(int i = 0; i < m_rows;i++){
		
		for(int j = 0;j<m_cols;j++){
			input >> maze[i][j];
		}
		
	}
}