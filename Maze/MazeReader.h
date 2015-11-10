/*******************************************************
* @file: MazeReader.h
* @author: Dravid Joseph
* @date: 11/16/15
* @brief: Header file for MazeReader Class
********************************************************/

#ifndef MAZE_READER_H
#define MAZE_READER_H

#include <iostream>
#include <fstream>

#include "MazeCreationException.h"

class MazeReader{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
public: 
	
	/*******************************************************
	* @pre :  valid filename
	* @post : Allocates 2D char array with maze information
	* @return : None
	* @throws : MazeCreationException
	********************************************************/
	
	MazeReader(std::string file) throw (MazeCreationException);
	
	/*******************************************************
	* @pre :  None
	* @post : Deallocates maze
	* @return : None
	********************************************************/
	
	~MazeReader();
	
	/*******************************************************
	* @pre :  None
	* @post : access maze pointer
	* @return : char*
	********************************************************/
	
	const char* const* getMaze() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Access number of columns
	* @return : int
	********************************************************/
	
	int getCols() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Access number of rows
	* @return : int
	********************************************************/
	
	int getRows() const;
	

	/*******************************************************
	* @pre : None
	* @post : Access starting column
	* @return : int
	********************************************************/
	
	int getStartCol() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Access starting row
	* @return : int
	********************************************************/
	
	int getStartRow() const;
	
	
	/*******************************************************
	* PROTECTED METHODS
	********************************************************/
	
protected:
	
	
	/*******************************************************
	* @pre :  valid file 
	* @post : reads file and store characters in array
	* @return : void
	* @throws : MazeCreationException
	********************************************************/
	
	void readMaze() throw (MazeCreationException);
	
private:
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
	
	char** maze;	//2D array that holds characters from file
	int m_rows;		//number of rows in maze
	int m_cols;		//number of columns in maze
	int m_startRow;	//starting row in maze
	int m_startCol;	//starting column in maze
	
	std::ifstream input;	//file object to read maze
	std::string fileName;	//holds name of file
};
#endif