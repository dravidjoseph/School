/*******************************************************
* @file: LinkedList.h
* @author: Dravid Joseph
* @date: 9/4/16
* @brief: Header file for LinkedList Class
********************************************************/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <fstream>

#include "Node.h"


template<typename T>
class LinkedList{



	/*******************************************************
	* PUBLIC METHODS
	********************************************************/

public:
	
	/*******************************************************
	* LAB 1 METHODS
	********************************************************/
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes LinkedList class
	* @return : None
	********************************************************/
	LinkedList();
	
	
	/*******************************************************
	* @pre :  None
	* @post : Deallocates Nodes in LinkedList class
	* @return : None
	********************************************************/
	~LinkedList();
	
	/*******************************************************
	* @pre :  valid value of type T
	* @post : public-facing method for insert
	* @return : void
	********************************************************/
	void insert(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : public-facing method for printing list
	* @return : None
	********************************************************/
	void print() const;
	
	/*******************************************************
	* LAB 2 METHODS
	********************************************************/
	
	/*******************************************************
	* @pre :  T is a valid value.
	* @post : using find(value), remove value from list, otherwise return message
	* @return : Node<T>*
	********************************************************/
	std::string erase(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : Checks if list is empty
	* @return : bool
	********************************************************/
	bool isEmpty() const;
	
	/*******************************************************
	* @pre :  None
	* @post : reverse list recursively
	* @return : void
	********************************************************/
	void reverse();
	
	
	/*******************************************************
	* @pre :  None
	* @post : concatenate existing list with numbers in data2.txt
	* @return : void
	********************************************************/
	void concatenate(LinkedList<T>* l2);
	
	/*******************************************************
	* @pre :  None
	* @post : deletes first element in list
	* @return : T
	********************************************************/
	T deleteFirst();
	
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
	
private:
	
	/*******************************************************
	* LAB 1 PRIVATE MEMBERS AND METHODS
	********************************************************/
	
	/*******************************************************
	* @brief :  Size of list
	********************************************************/
	int m_size;
	
	
	/*******************************************************
	* @brief :  pointer to the front of the list
	********************************************************/
	Node<T>* m_front;
	
	/*******************************************************
	* PRIVATE METHODS
	********************************************************/
	
	/*******************************************************
	* @pre :  valid value of type T, valid node pointer
	* @post : recursively traverses the list until the end
	* @post : if duplicate is found, trigger flag
	* @post : then inserts at end of list if no duplicate is found
	* @return : None
	********************************************************/
	void insert(T value,Node<T>* front,bool dupExists);
	
	
	/*******************************************************
	* @pre : valid node pointer
	* @post : recursively traverses the list, printing each value
	* @post : until end is reached
	* @return : None
	********************************************************/
	void print(Node<T>* front) const;
	
	/*******************************************************
	* LAB 2 PRIVATE MEMBERS AND METHODS
	********************************************************/

	
	/*******************************************************
	* @pre :  T is a valid value.
	* @post : find value in list and returns pointer to it
	* @return : Node<T>*
	********************************************************/
	Node<T>* find(T value) const;
	
	/*******************************************************
	* @pre :  T is a valid value.
	* @post : recursively finds node with value
	* @return : Node<T>*
	********************************************************/
	Node<T>* find(T value, Node<T>* front) const;
	
	/*******************************************************
	* @pre :  valid node pointers
	* @post : reverses the list recursively
	* @return : void
	********************************************************/
	void reverse(Node<T>* first,Node<T>* second,Node<T>* prev);
	
	
	/*******************************************************
	* @pre :  valid value and valid node pointer
	* @post : concatenates the list recursively
	* @return : void
	********************************************************/
	void concatenate(T value,Node<T>* front);
	
	
};
#include "LinkedList.hpp"
#endif