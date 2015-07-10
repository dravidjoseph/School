/*******************************************************
* @file : Node.hpp
* @author : Dravid Joseph
* @date : 7/9/2015
* @brief : Implementation file for Node class
********************************************************/

template<typename T>
Node<T>::Node():m_value(T()),m_next(nullptr){
	
}

template<typename T>
void setValue(T val){
	m_value = val;
}

template<typename T>
T getValue() const{
	return m_value;
}

template<typename T>
void setNext(Node<T>* prev){
	m_next = prev;
}

template<typename T>
Node<T>* getNext() const{
	return m_next;
}