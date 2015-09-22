/*******************************************************
* @file : Stack.hpp
* @author : Dravid Joseph
* @date : 9/28/15
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
	
	//if stack is empty, have m_top point to newNode
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
T Stack<T>::pop() throw(PreconditionViolationException){
	//throws exception if list is empty
	if(isEmpty()){
		throw PreconditionViolationException("Pop attempted on empty stack.\n");
	}
	
	else{
		//temporary pointer that moves
		Node<T>* traverse = m_top;
		
		//move m_top pointer so traverse is the only pointer holding node to be deleted
		m_top = m_top->getNext();
		
		//create temp value to return
		T value = traverse->getValue();
		
		//delete node and set traverse to nullptr
		delete traverse;
		traverse = nullptr;
		
		//decrement to reflect that one fewer node exists
		m_size--;
		
		return value;
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

template<typename T>
void Stack<T>::print() const{
	
	//if no nodes exist
	if(isEmpty()){
		std::cout<<"List empty";
	}
	else{
		//moving node pointer
		Node<T>* traverse = m_top;
	
		//traverses, then prints first n-1 nodes
		while(traverse->getNext() != nullptr){
			std::cout<<traverse->getValue()<<", ";
			traverse = traverse->getNext();
		}
		
		//prints nth node.
		std::cout<<traverse->getValue();
	}
}

template<typename T>
bool Stack<T>::operator < (const StackInterface<T>& rhs) const{
	//use dot operator since not dealing with pointer
	return rhs.size() < size();
}

template<typename T>
bool Stack<T>::operator <= (const StackInterface<T>& rhs) const{
	//use dot operator since not dealing with pointer
	
	return rhs.size() <= size();
}

template<typename T>
bool Stack<T>::operator > (const StackInterface<T>& rhs) const{
	//use dot operator since not dealing with pointer
	return rhs.size() > size();
}


template<typename T>
bool Stack<T>::operator >= (const StackInterface<T>& rhs) const{
	//use dot operator since not dealing with pointer
	return rhs.size() >= size();
}

template<typename T>
bool Stack<T>::operator == (const StackInterface<T>& rhs) const{
	//use dot operator since not dealing with pointer
	return rhs.size() == size();
}

template<typename T>
bool Stack<T>::operator != (const StackInterface<T>& rhs) const{
	//use dot operator since not dealing with pointer
	return rhs.size() != size();
}