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
	* @return : bool
	********************************************************/
	
	bool add(T value);
	
	/*******************************************************
	* @pre :  None
	* @post : prints tree inorder
	* @return : bool
	********************************************************/
	bool search(T value) const;
	
	void printTree(Order order) const;
	
	virtual void sortedPrint() const;
	
	/*******************************************************
	* @pre :  valid order
	* @post : prints tree in specified order
	* @return : vector
	********************************************************/
	std::vector<T> treeToVector(Order order) const; 
	
	/*******************************************************
	* PRIVATE MEMBERS
	********************************************************/
private:
	
	Node<T>* m_root;	//pointer that is always looking at the root of the tree
	
	
	/*******************************************************
	* PRIVATE METHODS
	********************************************************/
	
	/*******************************************************
	* @pre :  valid value, valid subTree
	* @post : true if value added successfully, false otherwise
	* @return : bool
	********************************************************/
	
	bool add(T value, Node<T>* subTree);
	
	/*******************************************************
	* @pre :  valid subTree
	* @post : deletes Tree
	* @return : void
	********************************************************/
	
	void deleteTree(Node<T>* subTree);
	
	/*******************************************************
	* @pre :  valid value, valid tree
	* @post : returns true if value in tree
	* @return : true
	********************************************************/
	bool search(T value, Node<T>* subTree) const;
	
	/*******************************************************
	* @pre :  valid order, valid tree
	* @post : prints tree in specified order
	* @return : void
	********************************************************/
	void printTree(Node<T>* subTree, Order order) const;
	
	/*******************************************************
	* @pre :  valid order
	* @post : prints tree in specified order
	* @return : vector
	********************************************************/
	void treeToVector(Order order,Node<T>* subTree, std::vector<T>& vec) const; 
	
};
#include "BinarySearchTree.hpp"
#endif