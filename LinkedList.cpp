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
	bool flag = true;
	while(flag){
		flag = removeFront();
	}
}

bool LinkedList::isEmpty() const{
	return m_size == 0;
}

int LinkedList::size() const{
	return m_size;
}

bool LinkedList::search(int value) const{
	
	Node* traverse = m_front;
	bool flag = false;
	
	while(traverse->getNext() != nullptr || flag){
		if(traverse->getValue() == value){
			flag = true;
		}
		else{
			traverse = traverse->getNext();
		}
	}
	if(traverse->getValue() == value){
		flag = true;
	}
	
	return flag;
	
}

void LinkedList::printList() const{
	Node* traverse = m_front;
	
	while(traverse->getNext() != nullptr){
		std::cout<<traverse->getValue()<<" ";
		traverse = traverse->getNext();
	}
	std::cout<<traverse->getValue();
	
	
}

void LinkedList::addBack(int value){
	if(isEmpty()){
		m_front = new Node();
		m_front->setValue(value);
	}
	else{
		Node* newNode = new Node();
		newNode->setValue(value);
		Node* traverse = m_front;
		
		while(traverse->getNext()!=nullptr){
			traverse = traverse->getNext();
		}
		traverse->setNext(newNode);
	}
	m_size++;
}

void LinkedList::addFront(int value){
	
	if(isEmpty()){
		m_front = new Node();
		m_front->setValue(value);
	}
	else{
		Node* newNode = new Node();
		newNode->setValue(value);
		newNode->setNext(m_front);
		m_front = newNode;
	}
	
	m_size++;
	
}

bool LinkedList::removeBack(){
	if(isEmpty()){
		return false;
	}
	else{
		Node* traverse1 = m_front;
		Node* traverse2 = m_front->getNext();
		while(traverse2->getNext() != nullptr){
			traverse1 = traverse1->getNext();
			traverse2 = traverse2->getNext();
		}
		delete traverse2;
		traverse2 = nullptr;
		traverse1 = nullptr;
		
		m_size--;
		
		return true;
	}
}

bool LinkedList::removeFront(){
	if(isEmpty()){
		return false;
	}
	else{
		Node* traverse = m_front;
		m_front = m_front->getNext();
		
		delete traverse;
		traverse = nullptr;
		
		m_size--;
		
		return true;
	}
}



