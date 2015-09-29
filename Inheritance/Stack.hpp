/*******************************************************
* @file : Stack.hpp
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Implementation file for Stack class.
********************************************************/

template<typename T>
Stack<T>::Stack():m_top(nullptr),m_size(0){
	
}

template<typename T>
Stack<T>::~Stack(){
	//remove from top of Stack while the stack isn't empty.
	while(!isEmpty()){
		pop();
	}
	
	//reset Stack members
	m_top = nullptr;
	m_size = 0;
}

template<typename T>
bool Stack<T>::isEmpty() const{
	return m_size == 0;
}

template<typename T>
void Stack<T>::push(const T newEntry){
	
	//Create new node
	Node<T>* newNode = new Node<T>();
	newNode->setValue(newEntry);
	
	//if node is empty, have m_top point to newNode
	if(isEmpty()){
		m_top = newNode;
	}
	//otherwise, have newNode point to m_top and move m_top forward.
	else{
		newNode->setNext(m_top);
		m_top = newNode;
	}
	//increment size by one
	m_size++;
}

template<typename T>
void Stack<T>::pop() throw(PreconditionViolationException){
	//throws exception if list is empty
	if(isEmpty()){
		throw PreconditionViolationException("Pop attempted on empty stack.\n");
	}
	
	else{
		//temporary pointer that moves
		Node<T>* traverse = m_top;
		
		//move m_top pointer so traverse is the only pointer holding node to be deleted
		m_top = m_top->getNext();
		
		//delete node and set traverse to nullptr
		delete traverse;
		traverse = nullptr;
		
		//decrement to reflect that one fewer node exists
		m_size--;
	}
}

template<typename T>
T Stack<T>::peek() const throw(PreconditionViolationException){
	
	//throw exception if list is empty
	if(isEmpty()){
		throw PreconditionViolationException("Peek attempted on empty stack.\n");
	}
	//return top value of the stack
	else{
		return m_top->getValue();
	}
}

template<typename T>
int Stack<T>::size() const{
	return m_size;
}
