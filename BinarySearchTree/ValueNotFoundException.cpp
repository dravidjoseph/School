/*******************************************************
* @file: ValueNotFoundException.cpp
* @author: Dravid Joseph
* @date: 8/5/15
* @brief: Implementation file for ValueNotFoundException class
********************************************************/

#include "ValueNotFoundException.h"

//pass the message the the std::runtime_error constructor

ValueNotFoundException::ValueNotFoundException(const char* message):std::runtime_error(message){
	
}

