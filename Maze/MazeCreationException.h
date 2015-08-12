/*******************************************************
* @file: MazeCreationException.h
* @author: Dravid Joseph
* @date: 8/10/15
* @brief: Header file for MazeCreationException Class
********************************************************/

#ifndef MAZE_CREATION_EXCEPTION_H
#define MAZE_CREAETION_EXCEPTION_H

#include <stdexcept>

class MazeCreationException: public std::runtime_error{
	
public:
	
	MazeCreationException(const char* message);
	
	
};
#endif