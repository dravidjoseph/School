/******************************************************************
* @file : Node.h
* @author : Dravid Joseph
* @date : 7/9/2015
* @brief : Implementation for PreconditionViolationException class.
*******************************************************************/

#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* msg):std::runtime_error(msg){
	
}