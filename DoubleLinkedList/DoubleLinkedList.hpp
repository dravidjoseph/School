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
		newNode->setNext(m_front->getNext());
		newNode->setPrevious(m_front);
		m_front = newNode;
	}
}

template<typename T>
void DoubleLinkedList<T>::pushBack(T value){
	
}

template<typename T>
bool DoubleLinkedList<T>::remove(T value){
	return true;
}

template<typename T>
void DoubleLinkedList<T>::insertAhead(T listValue,T newValue) throw (std::runtime_error){
	
}

template<typename T>
void DoubleLinkedList<T>::insertBehind(T listValue,T newValue) throw (std::runtime_error){
	
}

template<typename T>
Node<T>* DoubleLinkedList<T>::find(T value) const{
	return nullptr;
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