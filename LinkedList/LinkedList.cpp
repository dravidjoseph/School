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
	
	while(removeFront()){
	}
	m_front = nullptr;
	m_size = 0;
	
}

bool LinkedList::isEmpty() const{
	return m_size == 0;
}

int LinkedList::size() const{
	return m_size;
}

bool LinkedList::search(int value) const{
	
	
	if(isEmpty()){
		return false;
	}
	else{
		Node* traverse = m_front;
		while(traverse != nullptr){
			if(traverse->getValue() == value){
				return true;
			}
			else{
				traverse = traverse->getNext();
			}
		}
		
		return false;
	}
	
}

void LinkedList::printList() const{
	
	if(!isEmpty()){
	
		Node* traverse = m_front;
	
		while(traverse->getNext() != nullptr){
			std::cout<<traverse->getValue()<<" ";
			traverse = traverse->getNext();
		}
		std::cout<<traverse->getValue();
	}
	else{
		std::cout<<"List empty.\n";
	}
	
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
	
	Node* endPtr = m_front;
	
	if(m_size == 1){
		m_front = nullptr;
	}
	//2+ node list
	else{
		//endPtr is one node ahead of firstPtr
		Node* penPtr = m_front;
		endPtr = m_front -> getNext();
		
		//advance until secondPtr is at end of list
		while(endPtr->getNext() != nullptr){
			penPtr = penPtr->getNext();
			endPtr = endPtr->getNext();
		}
		//now endPtr points to the last node in list	
		penPtr->setNext(nullptr);
	}
	
	delete endPtr;
	endPtr = nullptr;
	m_size--;
	
	return true;
	
	
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



