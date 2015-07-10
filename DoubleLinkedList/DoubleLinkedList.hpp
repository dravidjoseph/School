/*******************************************************
* @file: DoubleLinkedList.hpp
* @author: Dravid Joseph
* @date: 7/8/15
* @brief: Implementation for DoubleLinkedList class
********************************************************/

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList():m_front(nullptr),m_back(nullptr),m_size(0){
	
}

template<typename T>
DoubleLinkedList<T>::~DoubleLinkedList(){
	
	//while the list is empty
	
	while(!isEmpty()){
		/*
		*move m_front list pointer to next item in list
		*isolating the node to be deleted
		*/
		Node<T>* traverse = m_front;
		m_front = m_front->getNext();
		
		
		//delet node, reducing size of list
		delete traverse;
		traverse = nullptr;
		m_size--;
	}
	
	//now list is empty, so remove pointer references.
	m_front = nullptr;
	m_back = nullptr;
	m_size = 0;		//should already be zero, but just a check
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
	
	else{
		//temp node pointer to hold place
		Node<T>* temp = m_front;
		
		//connect list pointer to new node.  DO NOT DO THE REVERSE
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
	
	//If the list is empty, link to list pointers
	if(isEmpty()){
		m_front = newNode;
		m_back = newNode;
	}
	//otherwise connect new node to back of list
	else{
		//temp node pointer to hold place
		Node<T>* temp = m_back;
		
		//connect list pointer to new node 
		m_back = newNode;
		
		//Connect new node to list
		newNode->setPrevious(temp);
		temp->setNext(newNode);
	}
	
	m_size++;
}

template<typename T>
bool DoubleLinkedList<T>::remove(T value){
	
	//If list is empty or the value isn't in the list, let user handle
	if(isEmpty() || (find(value) == nullptr)){
			return false;
		}
		
	//removal	
	else{
		//hand of pointer to specified value
			Node<T>* traverse = find(value);
			
			
			//if there is one node
			if(size() == 1){
				m_front = nullptr;
				m_back = nullptr;
			}
			else{
				//if value is at the beginning of the list
				if(traverse == m_front){
					//advance list pointer.traverse holds the node
					m_front = m_front->getNext();
					
					//set the m_front pointer to nullptr
					m_front->setPrevious(nullptr);
				}
				//if value is at the end of the list
				else if(traverse == m_back){
					//reverse list pointer.traverse holds the node
					m_back = m_back->getPrevious();
					
					//set the m_back pointer of the node to nullptr
					m_back->setNext(nullptr);
				}
				
				//if value is anywhere else in the list
				else{
					//Create pointers to the adjacent nodes of the target
					Node<T>* prev = traverse->getPrevious();
					Node<T>* next = traverse->getNext();
					
					//Link the adjacent nodes so the target node can be removed
					prev->setNext(next);
					next->setPrevious(prev);
				}
			}
			
			//can include outside the conditionals since this is common
			delete traverse;
			traverse = nullptr;
			
			
			m_size--;	//decrement
			return true;
		
	}
}

template<typename T>
void DoubleLinkedList<T>::insertAhead(T listValue,T newValue) throw (std::runtime_error){
	
	Node<T>* traverse = find(listValue);
	
	//Can't insert if the pointer isn't pointing
	if(traverse == nullptr){
		throw std::runtime_error("Value not found.\n");		//executed in catch block of main
	}
	else{
		
		//Create new Node and store value
		Node<T>* newNode = new Node<T>();
		newNode->setValue(newValue);
		
		//if node is at the front of the list
		if(traverse == m_front){
			m_front = newNode;
			newNode->setNext(traverse);
			traverse->setPrevious(newNode);
		}
		else{
			
			//pointer to node previous to the list
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
	
		//Can't insert if the pointer isn't pointing
		if(traverse == nullptr){
			throw std::runtime_error("Value not found.");	//executed in catch block of main
		}
		else{
		
			//Create new Node and store value
			Node<T>* newNode = new Node<T>();
			newNode->setValue(newValue);
		
			//if node is at the front of the list
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
	
	//nothing to find
	if(isEmpty()){
		return nullptr;
	}
	//traverse through list
	else{
		Node<T>* traverse = m_front;
		
		//while search pointer isn't pointing at the end of the list
		while(traverse->getNext() != nullptr){
			//if you find pointer, return it.
			if(traverse->getValue() == value){
				return traverse;
			}
			//otherwise, advance to next node
			else{
				traverse = traverse->getNext();
			}
		}
		//end of list comparison
		if(traverse->getValue() == value){
			return traverse;
		}
		//only executed if traversal doesn't find node.
		return nullptr;
	}
	
}

template<typename T>
void DoubleLinkedList<T>::printList() const{
	
	Node<T>* traverse = m_front;
	//moves until last node, but doesn't print last node.
	while(traverse->getNext()!= nullptr){
		std::cout<<traverse->getValue()<<", ";
	
		traverse = traverse->getNext();
	}
	
	//prints last node's value
	std::cout<<traverse->getValue()<<" ";
	
}