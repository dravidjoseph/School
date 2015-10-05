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
	push(animal);
}

FarmAnimal* AnimalPen::peekAtNextAnimal(){
	return peek();
}

void AnimalPen::releaseAnimal(){
	pop();
}

bool AnimalPen::isPenEmpty(){
	return isEmpty();
}