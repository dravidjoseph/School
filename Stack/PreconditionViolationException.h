/*******************************************************************
* @file : Node.h
* @author : Dravid Joseph
* @date : 7/9/2015
* @brief : Header file for PreconditionViolationException class
********************************************************************/

#ifndef PRECONDITION_VIOLATION_EXCEPTION_H
#define PRECONDITION_VIOLATION_EXCEPTION_H

#include <stdexcept>

class PreconditionViolationException : public std::runtime_error{
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
	
	PreconditionViolationException(const char* msg);

};
#endif