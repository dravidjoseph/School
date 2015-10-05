/*******************************************************************
* @file : PreconditionViolationException.h
* @author : Dravid Joseph
* @date : 10/19/2015
* @brief : Header file for PreconditionViolationException class
********************************************************************/

#ifndef PRECONDITION_VIOLATION_EXCEPTION_H
#define PRECONDITION_VIOLATION_EXCEPTION_H

#include <stdexcept>

class PreconditionViolationException : public std::runtime_error{
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
public: 
		
		
	/*******************************************************
	* @pre :  valid message
	* @post : calls runtime_error constructor
	* @return : None
	********************************************************/	
		
	PreconditionViolationException(const char* msg);

};
#endif