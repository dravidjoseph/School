/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 6/28/15
* @brief: Implementation file for LinkedList.h
********************************************************/

#include "Node.h"
#include <iostream>

int main(){
	
	Node* newNode1 = new Node();
	Node* newNode2 = new Node();
	
	Node* traverse;
	
	newNode1->setValue(35);
	newNode2->setValue(25);
	newNode1->setNext(newNode2);
	
	std::cout<<newNode1->getValue()<<"\n";
	std::cout<<newNode2->getValue()<<"\n";
	
	traverse = newNode1;
	
	std::cout<<traverse->getValue()<<"\n";
	
	traverse = traverse->getNext();
	
	std::cout<<traverse->getValue()<<"\n";
	
	
	
	
	
}