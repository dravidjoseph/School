/*******************************************************
* @file: MazeCreationException.h
* @author: Dravid Joseph
* @date: 11/16/15
* @brief: Header file for MazeCreationException Class
********************************************************/

#ifndef MAZE_CREATION_EXCEPTION_H
#define MAZE_CREATION_EXCEPTION_H

#include <stdexcept>

class MazeCreationException:public std::runtime_error{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/

public: 
	/*******************************************************
	* @pre :  None
	* @post : Initializes MazeCreationException object
	* @return : None
	********************************************************/	
	MazeCreationException(const char* message);
	
};
#endif

