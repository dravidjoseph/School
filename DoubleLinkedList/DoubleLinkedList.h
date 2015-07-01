/*******************************************************
* @file: DoubleLinkedList.h
* @author: Dravid Joseph
* @date: 6/30/15
* @brief: Header file for DoubleLinkedList class
********************************************************/

#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

//User-defined libraries
#include <stdexcept>


template<typename T>;

class DoubleLinkedList{
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
	
public:
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes DoubleLinkedList class
	* @return : Initialized Node
	********************************************************/
	DoubleLinkedList();
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	~DoubleLinkedList();
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	bool isEmpty() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	int size() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	void pushFront(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	void pushBack(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	bool remove(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	void insertAhead(T listValue,T newValue) throw (std::runtime_error);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	void printList() const;
	
	
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
	
private:
	
	/*******************************************************
	*Pointer to front of list
	********************************************************/
	Node<T>* m_front;
	
	/*******************************************************
	*Pointer to back of list
	********************************************************/
	Node<T>* m_back;
	
	/*******************************************************
	*Size of list
	********************************************************/
	int m_size;
	
	
};
#include "DoubleLinkedList.hpp"
#endif