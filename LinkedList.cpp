/*******************************************************
* @file: LinkedList.cpp
* @author: Dravid Joseph
* @date: 6/28/15
* @brief: Implementation file for LinkedList.h
********************************************************/

#include "LinkedList.h"

LinkedList::LinkedList():m_front(nullptr),m_size(0){
	
}

LinkedList::~LinkedList(){
	
}

bool LinkedList::isEmpty() const{
	return m_size == 0;
}

int LinkedList::size() const{
	return m_size;
}

bool LinkedList::search(int value) const{
	return true;
}

void LinkedList::printList() const{
	
}

void LinkedList::addBack(int value){
	
}

void LinkedList::addFront(int value){
	
}

bool LinkedList::removeBack(){
	return true;
}

bool LinkedList::removeFront(){
	return true;
}



