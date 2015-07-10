/******************************************************************
* @file : Node.h
* @author : Dravid Joseph
* @date : 7/9/2015
* @brief : Implementation for PreconditionViolationException class.
*******************************************************************/

template<typename T>
PreconditionViolationException<T>::PreconditionViolationException(const char* msg):std::runtime_error(msg){
	
}