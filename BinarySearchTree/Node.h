/*******************************************************
* @file: Node.h
* @author: Dravid Joseph
* @date: 6/30/15
* @brief: Header file for Node class
********************************************************/

#ifndef NODE_H
#define NODE_H

template<typename T>
class Node{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
public:
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : None
	********************************************************/
	Node();
	
	/*******************************************************
	* @pre :  None
	* @post : Copy Constructor-creates deep copy of node
	* @return : None
	********************************************************/
	Node(const Node<T>& other);
	
	/*******************************************************
	* @pre :  none
	* @post : valid value
	* @return : T
	********************************************************/
	T getValue() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Valid node pointer
	* @return : Node<T>*
	********************************************************/
	Node<T>* getLeft() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes Node class
	* @return : Node<T>*
	********************************************************/
	Node<T>* getRight() const;
	
	/*******************************************************
	* @pre :  valid value
	* @post : sets value
	* @return : void
	********************************************************/
	void setValue(T value);
	
	/*******************************************************
	* @pre :  valid left pointer
	* @post : sets left pointer value
	* @return : void
	********************************************************/
	void setLeft(Node<T>* left);
	
	/*******************************************************
	* @pre :  valid right pointer
	* @post : sets right pointer value
	* @return : void
	********************************************************/
	void setRight(Node<T>* right);
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
	T m_value; //Value stored in node
	
	Node<T>* m_left; //pointer to left child
	
	Node<T>* m_right; //pointer to right child
		
	
};
#include "Node.hpp"
#endif