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
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
public: 
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes AnimalPen instance
	* @return : None
	********************************************************/
	
	AnimalPen();
	
	/*******************************************************
	* @pre :  None
	* @post : Deallocates FarmAnimals
	* @return : None
	********************************************************/
	~AnimalPen();
	
	
	/*******************************************************
	* @pre :  Valid FarmAnimal pointer
	* @post : Adds animal to pen
	* @return : void
	********************************************************/
	void addAnimal(FarmAnimal* animal);
	
	/*******************************************************
	* @pre :  None
	* @post : Returns pointer to animal at top of pen
	* @return : None
	********************************************************/
	FarmAnimal* peekAtNextAnimal();
	
	/*******************************************************
	* @pre :  None
	* @post : releases animal at top of pen
	* @return : void
	********************************************************/
	void releaseAnimal();
	
	/*******************************************************
	* @pre :  None
	* @post : returns true if pen is empty, false otherwise
	* @return : bool
	********************************************************/
	bool isPenEmpty();
	
};
#endif