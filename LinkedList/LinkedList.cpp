/*******************************************************
* @file: LinkedList.cpp
* @author: Dravid Joseph
* @date: 9/14/15
* @brief: Implementation file for LinkedList class
********************************************************/

#include "LinkedList.h"

LinkedList::LinkedList():m_front(nullptr),m_size(0){
	
}

LinkedList::~LinkedList(){
	
	if(!isEmpty()){
		
		//temp node to hold node to delete
		Node* deletePtr = m_front;
		
		//move m_front to next node, or nullptr if last node
		m_front = m_front->getNext();
		 
		//delete the node pointed at by deletePtr
		delete deletePtr;
		//just to remove reference, not strictly necessary
		deletePtr = nullptr;
		
		m_size--;
		
	}
}

bool LinkedList::isEmpty() const{
	return m_size == 0;
}

int LinkedList::size() const{
	return m_size;
}

bool LinkedList::search(int value) const{
	
	//If empty list, automatically return false
	if(isEmpty()){
		return false;
	}
	//search list
	else{
		//Temp node to traverse
		Node* traverse = m_front;
		//while the next pointer doesn't point to NULL
		while(traverse->getNext() != nullptr){
			//If match, return true
			if(traverse->getValue() == value){
				return true;
			}
			//else, advance
			else{
				traverse = traverse->getNext();
			}
		}
		
		//If method is still executing here, it's on last node
		//Do final comparison
		if(traverse->getValue() == value){
			return true;
		}
		//at this point, value doesn't exist in list
		return false;
	}
	
}

void LinkedList::printList() const{
	//As long as the list isn't empty
	if(!isEmpty()){
	
		Node* traverse = m_front;
	
		while(traverse->getNext() != nullptr){
			std::cout<<traverse->getValue()<<" ";
			traverse = traverse->getNext();
		}
		//prints last value
		std::cout<<traverse->getValue();
	}
	//print empty string if list is empty
	else{
		std::cout<<"";
	}
	
}

void LinkedList::addBack(int value){
	
	//Just add to m_front if list is empty
	if(isEmpty()){
		m_front = new Node();
		m_front->setValue(value);
	}
	else{
		//create node and stuff value in it.
		Node* newNode = new Node();
		newNode->setValue(value);
		
		//create node pointer to traverse to end of list
		Node* traverse = m_front;
		
		while(traverse->getNext()!=nullptr){
			traverse = traverse->getNext();
		}
		//traverse is now pointing to last node in list
		//setNext makes the traverse node point at newNode
		traverse->setNext(newNode);
		//Now we're done.
	}
	m_size++;
}

void LinkedList::addFront(int value){
	
	if(isEmpty()){
		//same as with addBack
		m_front = new Node();
		m_front->setValue(value);
	}
	else{
		
		//create node and stuff value in it.
		Node* newNode = new Node();
		newNode->setValue(value);
		newNode->setNext(m_front);
		//move m_front to point at newNode
		m_front = newNode;
	}
	
	m_size++;
	
}

bool LinkedList::removeBack(){
	
	//Can't remove from empty list
	if(isEmpty()){
		return false;
	}

	Node* endPtr = m_front;
	//m_front node being held by endPtr
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
	//Can't remove from empty list
	if(isEmpty()){
		return false;
	}
	//Works for any nonzero list
	else{
		
		//create traverse node
		Node* traverse = m_front;
		//move m_front to next node
		m_front = m_front->getNext();
		//delete node that was previously at front
		delete traverse;
		traverse = nullptr;
		
		m_size--;
		
		return true;
	}
}



