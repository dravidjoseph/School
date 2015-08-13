/*******************************************************
* @file: MazeReader.h
* @author: Dravid Joseph
* @date: 8/12/15
* @brief: Header file for MazeReader Class
********************************************************/

#ifndef MAZEREADER_H
#define MAZEREADER_H

#include <iostream>
#include <fstream>

#include "MazeCreationException.h"

class MazeReader{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
public:
	
	/*******************************************************
	* @pre :  None
	* @post : Binary Search Tree initialized
	* @return : None
	********************************************************/
	
	MazeReader(std::string file) throw (MazeCreationException);
	
	/*******************************************************
	* @pre :  None
	* @post : Binary Search Tree initialized
	* @return : None
	********************************************************/
	
	~MazeReader();
	
	/*******************************************************
	* @pre :  None
	* @post : Binary Search Tree initialized
	* @return : None
	********************************************************/
	
	char** getMaze() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Binary Search Tree initialized
	* @return : None
	********************************************************/
	
	int getCols() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Binary Search Tree initialized
	* @return : None
	********************************************************/
	
	int getRows() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Binary Search Tree initialized
	* @return : None
	********************************************************/
	
	int getStartCol() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Binary Search Tree initialized
	* @return : None
	********************************************************/
	
	int getStartRow() const;
	
	/*******************************************************
	* PROTECTED METHODS
	********************************************************/
	
protected:
	
	/*******************************************************
	* @pre :  None
	* @post : Binary Search Tree initialized
	* @return : None
	********************************************************/
	
	void readMaze() throw (MazeCreationException);
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
	
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