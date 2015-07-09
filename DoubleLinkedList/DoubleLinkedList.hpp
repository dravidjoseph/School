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
	m_size = 0;
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
		
	//Create new node
	Node<T>* newNode = new Node<T>();
	
	//store value in node
	newNode->setValue(value);
	
	//if empty list, link to list pointers
	if(isEmpty()){
		
		//link list pointers to newNode
		m_front = newNode;
		m_back = newNode;
		
	}
	//otherwise, link to m_front and node m_front is next to
	else{
		//temp node pointer to hold place
		Node<T>* temp = m_front;
		
		//connect list pointer to new node and back
		m_front = newNode;
		
		//connect new node to rest of list
		newNode->setNext(temp);
		temp->setPrevious(newNode);
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
	}
	else{
		
		Node<T>* temp = m_back;
		m_back = newNode;
		newNode->setPrevious(temp);
		temp->setNext(newNode);
	}
	
	m_size++;
}

template<typename T>
bool DoubleLinkedList<T>::remove(T value){
	if(isEmpty() || (find(value) == nullptr)){
		std::cout<<isEmpty();
		std::cout<<m_size;
			return false;
		}
	else{
		
			Node<T>* traverse = find(value);
			
			if(size() == 1){
				m_front = nullptr;
				m_back = nullptr;
			}
			else{
				if(traverse == m_front){
					m_front = m_front->getNext();
					m_front->setPrevious(nullptr);
				}
				else if(traverse == m_back){
					m_back = m_back->getPrevious();
					m_back->setNext(nullptr);
				}
				else{
					Node<T>* prev = traverse->getPrevious();
					Node<T>* next = traverse->getNext();
					
					prev->setNext(next);
					next->setPrevious(prev);
				}
			}
			
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
		
		//Create new Node
		Node<T>* newNode = new Node<T>();
		newNode->setValue(newValue);
		
		if(traverse == m_front){
			m_front = newNode;
			newNode->setNext(traverse);
			traverse->setPrevious(newNode);
		}
		else{
			Node<T>* prev = traverse->getPrevious();
			newNode->setPrevious(prev);
			newNode->setNext(traverse);
			
			prev->setNext(newNode);
			traverse->setPrevious(newNode);
			
		}
		
		
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
		
			//Create new Node
			Node<T>* newNode = new Node<T>();
			newNode->setValue(newValue);
		
			if(traverse == m_back){
				m_back = newNode;
				newNode->setPrevious(traverse);
				traverse->setNext(newNode);
			}
			else{
				Node<T>* next = traverse->getNext();
				newNode->setNext(next);
				newNode->setPrevious(traverse);
			
				next->setPrevious(newNode);
				traverse->setNext(newNode);
			
			}
		
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
			else{
				traverse = traverse->getNext();
			}
		}
		if(traverse->getValue() == value){
			return traverse;
		}
		return nullptr;
	}
	
}

template<typename T>
void DoubleLinkedList<T>::printList() const{
	
	Node<T>* traverse = m_front;
	
	while(traverse->getNext()!= nullptr){
		std::cout<<traverse->getValue()<<", ";
	
		traverse = traverse->getNext();
	}
	
	std::cout<<traverse->getValue()<<" ";
	
}