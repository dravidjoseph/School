/*******************************************************
* @file: LinkedList.hpp
* @author: Dravid Joseph
* @date: 9/4/16
* @brief: Implementation file for LinkedList Class
********************************************************/

/*******************************************************
* LAB 1 PUBLIC METHODS
********************************************************/

template<typename T>
LinkedList<T>::LinkedList():m_size(0),m_front(nullptr){
	
}

template<typename T>
LinkedList<T>::~LinkedList(){
	//ensure that nodes are deallocated until there are no nodes left
	while(m_front != nullptr){
		
		//temporary node pointer to hold node to be deleted
		Node<T>* deleteNode = m_front;
		
		//advance m_front
		m_front = m_front->getNext();
		
		//deallocate node
		delete deleteNode;
		
		//not strictly necessary, but avoids dangling pointers
		deleteNode = nullptr;
		
		//decrease size-mainly for debugging purposes
		m_size--;	
	}
}

template<typename T>
void LinkedList<T>::insert(T value){
	
	//Empty list is a special case that needs to be handled outside of recursion
	if(m_front == nullptr){
		
		//new node created and allocated
		Node<T>* newNode = new Node<T>();
		
		//set value for new node
		newNode->setValue(value);
		
		//m_front points to new node-now list has one element
		m_front = newNode;
		//increment size by one
		m_size++;
	}
	
	//If list has 1+ elements, insertion can be handled recursively
	else{
		//private method that recursively adds nodes
		insert(value,m_front,false);
	}
}

template<typename T>
void LinkedList<T>::print() const{
	
	//empty list is a special case that needs to be handled outside
	if(isEmpty()){
		//nothing needs to be done
		return;
	}
	else{
		//private method that recursively traverses list, printing each node
		print(m_front);
		
		//flushes buffer after printing is done
		std::cout<<std::endl;
	}
}



/*******************************************************
* LAB 2 PUBLIC METHODS
********************************************************/

template<typename T>
std::string LinkedList<T>::erase(T value){
	
	if(isEmpty()){
		return "List is empty.  Cannot erase.\n";
	}
	Node<T>* finder = find(value);
	
	if(finder == nullptr){
		return "Value does not exist in the list.  Cannot erase.\n";
	}
	
	while(finder != nullptr){
		
		//delete from front
		if(finder->getValue() == m_front->getValue()){
			m_front = m_front->getNext();
		}
		//delete from back
		else if(finder->getNext() == nullptr){
			Node<T>* traverse = m_front;
			
			while(traverse->getNext()->getValue() != finder->getValue()){
				traverse = traverse->getNext();
			}
			traverse->setNext(nullptr);
		}
		//delete from middle
		else{
			Node<T>* traverse = m_front;
			
			while(traverse->getNext()->getValue() != finder->getValue()){
				traverse = traverse->getNext();
			}
			Node<T>* backPtr = finder->getNext();
			traverse->setNext(backPtr);
		}
		delete finder;
		finder = find(value);
		m_size--;
	}
	return "Removal(s) successful.\n";
	
}

template<typename T>
bool LinkedList<T>::isEmpty() const{
	return m_size == 0;
}

template<typename T>
void LinkedList<T>::reverse(){
	//deal with empty list and one-list special cases
	if(m_size == 0 || m_size == 1){
		//do nothing, nothing to reverse
	}
	//otherwise, we can use our recursive method
	else{
		//see private reverse method for more info.
		reverse(m_front,m_front->getNext(),nullptr);
	}
	
}

template<typename T>
void LinkedList<T>::concatenate(LinkedList<T>* l2){
	while(!l2->isEmpty()){
		concatenate(l2->deleteFirst(),m_front);
	}
}

template<typename T>
T LinkedList<T>::deleteFirst(){
	
	
	Node<T>* holder = m_front;
	m_front = m_front->getNext();
	T val = holder->getValue();
	
	delete holder;
	holder = nullptr;
	m_size--;
	
	return val;
}


/*******************************************************
* PRIVATE METHODS
********************************************************/

/*******************************************************
* LAB 1 PRIVATE METHODS
********************************************************/

template<typename T>
void LinkedList<T>::insert(T value,Node<T>* front, bool dupExists){
	
	//if you've reached the end of the list, add node
	if(front->getNext() == nullptr && !dupExists){
		
		//check last node
		if(front->getValue() == value){
			
		}
		else{
			//create and allocate new node
			Node<T>* newNode = new Node<T>();
		
			//store value in node
			newNode->setValue(value);
		
			//connect node to list
			front->setNext(newNode);
		
			//increment size to reflect list
			m_size++;
		}
		
		
	}
	//deals with case where a duplicate is found and the end of the list is reached
	//otherwise, will keep trying to traverse.
	else if(front->getNext() == nullptr && dupExists){
		
	}
	//keep using recursion to traverse list
	else{
		//call method again with same value and next node.
		
		if(front->getValue() == value){
			dupExists = true;
		}
		insert(value,front->getNext(), dupExists);

		
		
	}
}

template<typename T>
void LinkedList<T>::print(Node<T>* front) const{
	
	//print list value followed by a space
	std::cout<< front->getValue() << " ";
	
	//if the node is not the end of the list, call print method with the next node
	if(front->getNext() != nullptr){
		print(front->getNext());
	}
}

/*******************************************************
* LAB 2 PRIVATE METHODS
********************************************************/
template<typename T>
Node<T>* LinkedList<T>::find(T value) const{
	
	//nothing to find in an empty list
	if(m_size == 0){
		return nullptr;
	}
	//call a function that can actually recurse
	else{
		return find(value,m_front);
		
	}
}

template<typename T>
Node<T>* LinkedList<T>::find(T value, Node<T>* front) const{
	
	//returns node containing specified value
	if(front->getValue() == value){
		return front;
	}
	//if you've reached the end of the list and the
	//if statement above didn't trigger, return nullptr
	else if(front->getNext() == nullptr){
		return nullptr;
	}
	//keep recursing until one of the above statements prove true
	else{
		return find(value,front->getNext());
	}
}


template<typename T>
void LinkedList<T>::reverse(Node<T>* first,Node<T>* second,Node<T>* prev){
	//Take first and point it back
	first->setNext(prev);
	
	//shift pointers
	prev = first;
	first = second;
	
	//if second is not pointing to end of the list, advance it and call again
	if(second->getNext() != nullptr){
		second = second->getNext();
		reverse(first,second,prev);
	}
	//otherwise, set it to the next node and reassign m_front
	else{
		second->setNext(prev);
		m_front = second;
	}
	
}

template<typename T>
void LinkedList<T>::concatenate(T value,Node<T>* front){
	if(front->getNext() == nullptr){
		Node<T>* newNode = new Node<T>();
		newNode->setValue(value);
		front->setNext(newNode);
	}
	else{
		concatenate(value,front->getNext());
	}
}

