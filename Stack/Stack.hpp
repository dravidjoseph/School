/*******************************************************
* @file : Stack.hpp
* @author : Dravid Joseph
* @date : 7/9/2015
* @brief : Implementation file for Stack class.
********************************************************/

template<typename T>
Stack<T>::Stack():m_top(nullptr),m_size(0){
	
}

template<typename T>
Stack<T>::~Stack(){
	while(!isEmpty()){
		pop();
	}
	m_top = nullptr;
	m_size = 0;
}

template<typename T>
bool Stack<T>::isEmpty() const{
	return m_size == 0;
}

template<typename T>
void Stack<T>::push(const T newEntry){
	
	Node<T>* newNode = new Node<T>();
	newNode->setValue(newEntry);
	
	if(isEmpty()){
		m_top = newNode;
	}
	else{
		newNode->setNext(m_top);
		m_top = newNode;
	}
	m_size++;
}

template<typename T>
T Stack<T>::pop() throw(PreconditionViolationException){
	if(isEmpty()){
		throw PreconditionViolationException("Pop attempted on empty stack.");
	}
	else{
		Node<T>* traverse = m_top;
		m_top = m_top->getNext();
		T value = traverse->getValue();
		
		delete traverse;
		traverse = nullptr;
		
		m_size--;
		
		return value;
	}
}

template<typename T>
T Stack<T>::peek() const throw(PreconditionViolationException){
	
	if(isEmpty()){
		throw PreconditionViolationException("Peek attempted on empty stack.");
	}
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
	
	if(isEmpty()){
		std::cout<<"List empty";
	}
	else{
		Node<T>* traverse = m_top;
	
		while(traverse->getNext() != nullptr){
			std::cout<<traverse->getValue()<<", ";
			traverse = traverse->getNext();
		}
		std::cout<<traverse->getValue();
	}
}

template<typename T>
bool Stack<T>::operator < (const StackInterface<T>& rhs) const{
	if(rhs.size() < size()){
		return true;
	}
	else{
		return false;
	}
}

template<typename T>
bool Stack<T>::operator <= (const StackInterface<T>& rhs) const{
	if(rhs.size() <= size()){
		return true;
	}
	else{
		return false;
	}
}

template<typename T>
bool Stack<T>::operator > (const StackInterface<T>& rhs) const{
	if(rhs.size() > size()){
		return true;
	}
	else{
		return false;
	}
}


template<typename T>
bool Stack<T>::operator >= (const StackInterface<T>& rhs) const{
	if(rhs.size() >= size()){
		return true;
	}
	else{
		return false;
	}
}

template<typename T>
bool Stack<T>::operator == (const StackInterface<T>& rhs) const{
	if(rhs.size() == size()){
		return true;
	}
	else{
		return false;
	}
}

template<typename T>
bool Stack<T>::operator != (const StackInterface<T>& rhs) const{
	if(rhs.size() != size()){
		return true;
	}
	else{
		return false;
	}
}