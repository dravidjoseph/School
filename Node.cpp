/*******************************************************
* @file: Node.cpp
* @author: Dravid Joseph
* @date: 6/28/15
* @brief: Implementation file for Node class
********************************************************/

#include "Node.h"

Node::Node():m_value(0),m_next(nullptr){

}

void Node::setValue(int val){
	m_value = val;
}

int Node::getValue() const{
	return m_value;
}

void Node::setNext(Node* prev){
	m_next = prev;
}

Node* Node::getNext() const{
	return m_next;
}

