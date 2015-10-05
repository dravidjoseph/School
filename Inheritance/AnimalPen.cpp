/*******************************************************
* @file : AnimalPen.cpp
* @author : Dravid Joseph
* @date : 10/19/2015
* @brief : Implementation file AnimalPen class
********************************************************/


#include "AnimalPen.h"

AnimalPen::AnimalPen(){
	
}

AnimalPen::~AnimalPen(){
	
	while(!isPenEmpty()){
		releaseAnimal();	
	}	
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