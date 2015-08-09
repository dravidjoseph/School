/*******************************************************
* @file: BinarySearchTree.h
* @author: Dravid Joseph
* @date: 8/5/15
* @brief: Header file for BinarySearchTree class
********************************************************/


#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>

#include "BSTI.h"
#include "Node.h"


template<typename T>
class BinarySearchTree : public BSTI<T>{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
public: 
	
	/*******************************************************
	* @pre :  None
	* @post : Binary Search Tree initialized
	* @return : None
	********************************************************/
	
	BinarySearchTree();
	
	/*******************************************************
	* @pre :  None
	* @post : deep copy of other
	* @return : None
	********************************************************/
	
	BinarySearchTree(const BinarySearchTree<T>& other);
	
	/*******************************************************
	* @pre :  valid tree
	* @post : deletes tree
	* @return : None
	********************************************************/
	
	~BinarySearchTree();
	
	/*******************************************************
	* @pre :  None
	* @post : Returns pointer to deep copy of this
	* @return : pointer to this
	********************************************************/
	
	BSTI<T>* clone();
	
	/*******************************************************
	* @pre :  None
	* @post : bool if tree is empty
	* @return : bool
	********************************************************/
	
	bool isEmpty() const;
	
	/*******************************************************
	* @pre :  None
	* @post : prints tree
	* @return : void
	********************************************************/
	
	bool add(T value);
	
	
	/*******************************************************
	* @pre :  None
	* @post : prints tree
	* @return : void
	********************************************************/
	void printTree(Order order) const;
	
	
	/*******************************************************
	* @pre :  None
	* @post : prints tree inorder
	* @return : void
	********************************************************/
	void sortedPrint() const;
	
	/*******************************************************
	* @pre :  None
	* @post : prints tree inorder
	* @return : void
	********************************************************/
	T search(T value) const throw (ValueNotFoundException);
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
private:
	
	Node<T>* m_root;	//pointer that is always looking at the root of the tree
	
	
	/*******************************************************
	* PRIVATE METHODS
	********************************************************/
	
	/*******************************************************
	* @pre :  None
	* @post : prints tree inorder
	* @return : void
	********************************************************/
	
	bool add(T value, Node<T>* subTree);
	
	/*******************************************************
	* @pre :  None
	* @post : prints tree inorder
	* @return : void
	********************************************************/
	
	void deleteTree(Node<T>* subTree);
	
	/*******************************************************
	* @pre :  None
	* @post : prints tree inorder
	* @return : void
	********************************************************/
	T search(T value, Node<T>* subTree) const throw (ValueNotFoundException);
	
	/*******************************************************
	* @pre :  None
	* @post : prints tree inorder
	* @return : void
	********************************************************/
	void printTree(Node<T>* subTree, Order order) const;
	
	
	
	
};
#include "BinarySearchTree.hpp"
#endif