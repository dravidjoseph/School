/*******************************************************
* @file : AnimalPen.h
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Header file for AnimalPen class
********************************************************/

#ifndef ANIMAL_PEN_H
#define ANIMAL_PEN_H

#include "Stack.h"
#include "FarmAnimal.h"

class AnimalPen : public Stack<FarmAnimal*>{
	
	
public: 
	
	AnimalPen();
	
	~AnimalPen();
	
	void addAnimal(FarmAnimal* animal);
	
	FarmAnimal* peekAtNextAnimal();
	
	void releaseAnimal();
	
	bool isPenEmpty();
	
};
#endif