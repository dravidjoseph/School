/*******************************************************
* @file : Node.h
* @author : Dravid Joseph
* @date : 7/9/2015
* @brief : Stack Interface
********************************************************/

#ifndef STACK_INTERFACE_H
#define STACK_INTERFACE_H

template<typename T>

class StackInterface{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
	/*******************************************************
	* @pre :  None
	* @post : Deallocates stack
	* @return : None
	********************************************************/
	
	virtual ~StackInterface() {};
	
	/*******************************************************
	* @pre :  None
	* @post : returns true if stack is empty, fasle otherwise
	* @return : bool
	********************************************************/
	
	virtual bool isEmpty() const = 0;
	
	/*******************************************************
	* @pre :  valid newEntry
	* @post : pushes new entry onto stack
	* @return : void
	********************************************************/
	
	virtual void push(const T newEntry) = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : T
	* @throw : PreconditionViolationException
	********************************************************/
	
	virtual T pop() throw(PreconditionViolationException) = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : T
	********************************************************/
	
	virtual T peek() const throw(PreconditionViolationException) = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : int
	********************************************************/
	
	virtual int size() const = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : void
	********************************************************/
	
	virtual void print() const = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	virtual bool operator < (const StackInterface<T>& rhs) const = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	virtual bool operator <= (const StackInterface<T>& rhs) const = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	virtual bool operator > (const StackInterface<T>& rhs) const = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	virtual bool operator >= (const StackInterface<T>& rhs) const = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	virtual bool operator == (const StackInterface<T>& rhs) const = 0;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	virtual bool operator != (const StackInterface<T>& rhs) const = 0;
	
};
#endif