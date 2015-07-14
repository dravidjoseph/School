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
	Stack<FarmAnimal*>::~Stack();
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