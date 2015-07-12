/*******************************************************
* @file : Node.h
* @author : Dravid Joseph
* @date : 7/12/2015
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
	* @pre :  valid newEntry
	* @post : pushes new entry onto stack
	* @return : void
	********************************************************/
	
	void push(const T newEntry);
	
	/*******************************************************
	* @pre :  None
	* @post : removes value at top of stack, returning value
	* @return : T
	* @throw : PreconditionViolationException
	********************************************************/
	
	T pop() throw(PreconditionViolationException);
	
	/*******************************************************
	* @pre :  None
	* @post : returns value at top of stack
	* @return : T
	********************************************************/
	
	T peek() const throw(PreconditionViolationException);
	
	/*******************************************************
	* @pre :  None
	* @post : size of stack
	* @return : int
	********************************************************/
	
	int size() const;
	
	/*******************************************************
	* @pre :  None
	* @post : prints all node values in stack
	* @return : void
	********************************************************/
	
	void print() const;
	
	/*******************************************************
	* @pre :  valid stack reference
	* @post :  Returns true if Stack 1 size < Stack 2 size
	* @return : bool
	********************************************************/
	
	bool operator < (const StackInterface<T>& rhs) const;
	
	/*******************************************************
	* @pre :  valid stack references
	* @post :  Returns true if Stack 1 size <= Stack 2 size
	* @return : bool
	********************************************************/
	
	bool operator <= (const StackInterface<T>& rhs) const;
	
	/*******************************************************
	* @pre :  valid stack references
	* @post :  Returns true if Stack 1 size > Stack 2 size
	* @return : bool
	********************************************************/
	
	bool operator > (const StackInterface<T>& rhs) const;
	
	/*******************************************************
	* @pre :  valid stack references
	* @post : Returns true if Stack 1 size >= Stack 2 size
	* @return : bool
	********************************************************/
	
	bool operator >= (const StackInterface<T>& rhs) const;
	
	/*******************************************************
	* @pre :  valid stack references
	* @post : Returns true if the size of the two stacks are equal
	* @return : bool
	********************************************************/
	
	bool operator == (const StackInterface<T>& rhs) const;
	
	/*******************************************************
	* @pre :  valid stack references
	* @post : Returns true if the size of the two stacks aren't equal
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