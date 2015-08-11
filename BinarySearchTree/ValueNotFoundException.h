/*******************************************************
* @file: ValueNotFoundException.h
* @author: Dravid Joseph
* @date: 8/5/15
* @brief: Header file for ValueNotFoundException Class
********************************************************/

#ifndef VALUE_NOT_FOUND_EXCEPTION_H
#define VALUE_NOT_FOUND_EXCEPTION_H

#include <stdexcept>

class ValueNotFoundException: public std::runtime_error{
	
public:
	
	/*******************************************************
	* @pre :  Valid message
	* @post : Initializes Exception
	* @return : None
	********************************************************/
	
	ValueNotFoundException(const char* message);
	
};
#endif