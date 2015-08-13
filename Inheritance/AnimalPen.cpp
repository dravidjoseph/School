/*******************************************************
* @file : AnimalPen.cpp
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Implementation file AnimalPen class
********************************************************/


#include "AnimalPen.h"

AnimalPen::AnimalPen(){
	Stack<FarmAnimal*>::Stack();
}

AnimalPen::~AnimalPen(){
	
	Node<FarmAnimal*>* temp = Stack::m_top;
	while(m_top != nullptr){
		temp = m_top;
		m_top = m_top -> getNext();
		
		delete temp;
		temp = nullptr;
	}
	
	delete m_top;
	m_top = nullptr;
	
}

void AnimalPen::addAnimal(FarmAnimal* animal){
	Stack<FarmAnimal*>::push(animal);
}

FarmAnimal* AnimalPen::peekAtNextAnimal(){
	return Stack<FarmAnimal*>::peek();
}

void AnimalPen::releaseAnimal(){
	Stack<FarmAnimal*>::pop();
}

bool AnimalPen::isPenEmpty(){
	return Stack<FarmAnimal*>::isEmpty();
}