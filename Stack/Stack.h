/*******************************************************
* @file : Node.h
* @author : Dravid Joseph
* @date : 7/9/2015
* @brief : Header file for Stack class.
********************************************************/

#ifndef STACK_H
#define STACK_H


#include <iostream>
#include "PreconditionViolationException.h"
#include "Node.h"
#include "StackInterface.h"

template<typename T>


class Stack : public StackInterface<T>{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
public: 
	/*******************************************************
	* @pre :  None
	* @post : Initializes Stack
	* @return : None
	********************************************************/
	Stack();
	
	/*******************************************************
	* @pre :  None
	* @post : Deallocates stack
	* @return : None
	********************************************************/
	
	~Stack();
	
	/*******************************************************
	* @pre :  None
	* @post : returns true if stack is empty, fasle otherwise
	* @return : bool
	********************************************************/
	
	bool isEmpty() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : void
	********************************************************/
	
	void push(const T newEntry);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : T
	********************************************************/
	
	T pop() throw(PreconditionViolationException);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : T
	********************************************************/
	
	T peek() const throw(PreconditionViolationException);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : int
	********************************************************/
	
	int size() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : void
	********************************************************/
	
	void print() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	bool operator < (const StackInterface<T>& rhs) const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	bool operator <= (const StackInterface<T>& rhs) const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	bool operator > (const StackInterface<T>& rhs) const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	bool operator >= (const StackInterface<T>& rhs) const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	bool operator == (const StackInterface<T>& rhs) const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	
	bool operator != (const StackInterface<T>& rhs) const;
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
	
private:
	
	/*******************************************************
	*Pointer for Stack
	********************************************************/
	Node<T>* m_top;
	
	/*******************************************************
	*Size of Stack
	********************************************************/
	int m_size;
	
	
};
#include "Stack.hpp"
#endif