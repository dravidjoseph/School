/*******************************************************
* @file : Node.h
* @author : Dravid Joseph
* @date : 7/9/2015
* @brief : Header file for Node class
********************************************************/

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node{
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
public:
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Initialized Node
	********************************************************/
	Node();
	
	/*******************************************************
	* @pre :  valid integer value
	* @post : None
	* @return : void
	********************************************************/
	void setValue(int val);
	
	/*******************************************************
	* @pre :  None
	* @post : valid integer
	* @return : integer value
	********************************************************/
	int getValue() const;
	
	/*******************************************************
	* @pre :  Valid Node reference
	* @post : sets Node pointer to valid node reference
	* @return : void
	********************************************************/
	void setNext(Node* prev);
	
	/*******************************************************
	* @pre :  None
	* @post : Valid Node reference
	* @return : Node*
	********************************************************/
	Node* getNext() const;
	
	
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
private: 
	
	/*******************************************************
	*Value stored inside Node
	********************************************************/
	int m_value;
	
	
	/*******************************************************
	* Pointer to next node
	********************************************************/
	Node* m_next;
	
	
};
#include "Node.hpp"
#endif