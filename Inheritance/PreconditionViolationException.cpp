/******************************************************************
* @file : PreconditionViolationException.cpp
* @author : Dravid Joseph
* @date : 10/19/2015
* @brief : Implementation for PreconditionViolationException class.
*******************************************************************/

#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* msg):std::runtime_error(msg){
	
}