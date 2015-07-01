/*******************************************************
* @file: Node.hpp
* @author: Dravid Joseph
* @date: 6/30/15
* @brief: Implementation file for Node class
********************************************************/


template<typename T>
Node::Node():m_value(T()),m_previous(nullptr),m_next(nullptr){
	
}

template<typename T>
T Node::getValue() const{
	return m_value;
}

template<typename T>
void Node::setValue(T val){
	m_value = val;
}

template<typename T>
Node<T>* Node::getPrevious() const{
	return m_previous;
	
}

template<typename T>
void Node::setPrevious(Node<T>* prev){
	m_previous = prev;
}

template<typename T>
Node<T>* Node::getNext() const{
	return m_next;
}

template<typename T>
void Node::setNext(Node<T>* next){
	m_next = next;
}