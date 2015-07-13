/*******************************************************
* @file : AnimalPen.cpp
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Implementation file AnimalPen class
********************************************************/


#include "AnimalPen.h"

AnimalPen::AnimalPen(){
	Stack();
}

AnimalPen::~AnimalPen(){
	~Stack();
}

void AnimalPen::addAnimal(FarmAnimal* animal){
	push(animal);
}

FarmAnimal* AnimalPen::peekAtNextAnimal(){
	peek()
}

void AnimalPen::releaseAnimal(){
	pop();
}

bool AnimalPen::isPenEmpty(){
	return isEmpty();
}