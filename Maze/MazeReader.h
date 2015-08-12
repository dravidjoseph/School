/*******************************************************
* @file: MazeReader.h
* @author: Dravid Joseph
* @date: 8/10/15
* @brief: Header file for MazeReader Class
********************************************************/

#ifndef MAZEREADER_H
#define MAZEREADER_H

#include <iostream>
#include <fstream>

class MazeReader{
	
	
public:
	
	
	MazeReader(std::string file) throw (MazeCreationException);
	
	~MazeReader();
	
	char** getMaze() const;
	
	int getCols() const;
	
	int getRows() const;
	
	int getStartCol() const;
	
	int getStartRow() const;
	
	
protected:
	
	void readMaze() throw (MazeCreationException);
	
	
private:
	
	int m_rows;
	
	int m_cols;
	
	int m_startRow;
	
	int m_startCol;
	
	std::ifstream input;
	
	std::string fileName;
	
	char** maze;
	
	
};
#endif