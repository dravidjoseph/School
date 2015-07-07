/*******************************************************
* @file: DoubleLinkedList.hpp
* @author: Dravid Joseph
* @date: 6/30/15
* @brief: Implementation for DoubleLinkedList class
********************************************************/

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList():m_front(nullptr),m_back(nullptr),m_size(0){
	
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
	while(!isEmpty()){
		Node<T>* traverse = m_front;
		m_front = m_front->getNext();
		
		delete traverse;
		traverse = nullptr;
		m_size--;
	}
	m_front = nullptr;
	m_back = nullptr;
}

template<typename T>
bool DoubleLinkedList<T>::isEmpty() const{
	return m_size == 0;
}

template<typename T>
int DoubleLinkedList<T>::size() const{
	return m_size;
}

template<typename T>
void DoubleLinkedList<T>::pushFront(T value){
	//create new node
	Node<T>* newNode = new Node<T>();
	
	//store value
	newNode->setValue(value);
	if(isEmpty()){
		//list pointers point to new node
		m_front = newNode;
		m_back = newNode;
		
		//new node points back to list pointers
		newNode->setPrevious(m_front);
		newNode->setNext(m_back);
		
	}
	else{
		
		Node<T>* traverse = m_front->getNext();
		
		newNode->setNext(traverse);
		newNode->setPrevious(m_front);
		m_front = newNode;
		traverse->setPrevious(newNode);
	}
	m_size++;
}

template<typename T>
void DoubleLinkedList<T>::pushBack(T value){
	
	Node<T>* newNode = new Node<T>();
	
	newNode->setValue(value);
	
	if(isEmpty()){
		m_front = newNode;
		m_back = newNode;
		
		newNode->setPrevious(m_front);
		newNode->setNext(m_back);
	}
	else{
		
		Node<T>* traverse = m_back->getPrevious();
		
		newNode->setNext(m_back);
		newNode->setPrevious(traverse);
		m_back = newNode;
		traverse->setNext(newNode);
	}
	
	
	m_size++;
	
}

template<typename T>
bool DoubleLinkedList<T>::remove(T value){
	if(isEmpty()){
		return false;
	}
	else{
		
		Node<T>* traverse = find(value);
		Node<T>* prev = traverse->getPrevious();
		Node<T>* next = traverse->getNext();
		
		prev->setNext(next);
		next->setPrevious(prev);
		
		delete traverse;
		traverse = nullptr;
		
		m_size--;
		
		return true;
		
	}
}

template<typename T>
void DoubleLinkedList<T>::insertAhead(T listValue,T newValue) throw (std::runtime_error){
	
	Node<T>* traverse = find(listValue);
	
	if(traverse == nullptr){
		throw std::runtime_error("Value not found\n");
	}
	else{
		Node<T>* previous = traverse->getPrevious();
		
		//Create new Node
		Node<T>* newNode = new Node<T>();
		newNode->setValue(newValue);
		
		newNode->setPrevious(previous);
		newNode->setNext(traverse);
		
		previous->setNext(newNode);
		traverse->setPrevious(newNode);
		
		m_size++;
		
		
	}
}

template<typename T>
void DoubleLinkedList<T>::insertBehind(T listValue,T newValue) throw (std::runtime_error){
	
	Node<T>* traverse = find(listValue);
	
	if(traverse == nullptr){
		throw std::runtime_error("Value not found");
	}
	else{
		Node<T>* next = traverse->getNext();
		
		//Create new node
		Node<T>* newNode = new Node<T>();
		newNode->setValue(newValue);
		
		newNode->setPrevious(traverse);
		newNode->setNext(next);
		
		traverse->setNext(newNode);
		next->setPrevious(newNode);
		
		m_size++;
	}
	
}

template<typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const{
	
	if(isEmpty()){
		return nullptr;
	}
	else{
		
		Node<T>* traverse = m_front;
		while(traverse->getNext() != nullptr){
			if(traverse->getValue() == value){
				return traverse;
			}
			traverse = traverse->getNext();
		}
		return nullptr;
	}
	
	
}

template<typename T>
void DoubleLinkedList<T>::printList() const{
	if(isEmpty()){
		std::cout<<"List Empty\n";
	}
	else{
		Node<T>* traverse = m_front;
		
		while(traverse->getNext() != nullptr){
			std::cout<<traverse->getValue()<<" ";
			traverse = traverse->getNext();
		}
		
		std::cout<<traverse->getValue()<<"\n";
	}
}