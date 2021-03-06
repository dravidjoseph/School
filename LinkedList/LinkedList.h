/*******************************************************
* @file: LinkedList.h
* @author: Dravid Joseph
* @date: 9/14/15
* @brief: Header file for LinkedList class
********************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Standard libraries
#include <iostream>

//User-defined libraries
#include "Node.h"

class LinkedList{
	
public:	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes LinkedList class
	* @return : Initialized LinkedList
	********************************************************/
	LinkedList();
	
	/*******************************************************
	* @pre :  None
	* @post : Deletes all Nodes in list
	* @return : None
	********************************************************/
	virtual ~LinkedList();
	
	/*******************************************************
	* @pre :  None
	* @post : state of list size
	* @return : bool
	********************************************************/
	bool isEmpty() const;
	
	/*******************************************************
	* @pre :  valid size
	* @post : returns size of list
	* @return : int
	********************************************************/
	int size() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	bool search(int value) const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : void
	********************************************************/
	void printList() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : void
	********************************************************/
	void addBack(int value);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : void
	********************************************************/
	void addFront(int value);
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	bool removeBack();
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : bool
	********************************************************/
	bool removeFront();
	
	/*******************************************************
	* @pre :  None
	* @post : Reverses list
	* @return : void
	********************************************************/
	void reverse();
	
	
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
	
private:
	
	/*******************************************************
	*Points to the front of the list linked
	********************************************************/
	Node* m_front;
	
	/*******************************************************
	*Size of the list.
	********************************************************/
	int m_size;
	
	
	
	
};
#endif