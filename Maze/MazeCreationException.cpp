/*******************************************************
* @file: MazeCreationException.cpp
* @author: Dravid Joseph
* @date: 8/12/15
* @brief: Implementation for MazeCreationException Class
********************************************************/

#include "MazeCreationException.h"

MazeCreationException::MazeCreationException(const char* message):std::runtime_error(message){
	
}