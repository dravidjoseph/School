/*******************************************************
* @file : Node.hpp
* @author : Dravid Joseph
* @date : 10/19/2015
* @brief : Implementation file for Node class
********************************************************/

template<typename T>
Node<T>::Node():m_value(T()),m_next(nullptr){
	
}

template<typename T>
void Node<T>::setValue(T val){
	m_value = val;
}

template<typename T>
T Node<T>::getValue() const{
	return m_value;
}

template<typename T>
void Node<T>::setNext(Node<T>* prev){
	m_next = prev;
}

template<typename T>
Node<T>* Node<T>::getNext() const{
	return m_next;
}