/*******************************************************
* @file : Cow.h
* @author : Dravid Joseph
* @date : 10/19/2015
* @brief : Header file for cow class
********************************************************/

#ifndef COW_H
#define COW_H

#include "FarmAnimal.h"

class Cow : public FarmAnimal{
	
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
public:
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes cow
	* @return : none
	********************************************************/
	
	Cow();
	
	/*******************************************************
	* @pre :  None
	* @post : gets amound of milk produced
	* @return : double
	********************************************************/
	
	double getMilkProduced() const;
	
	/*******************************************************
	* @pre :  valid amount of milk
	* @post : sets new value milk produced
	* @return : void
	********************************************************/
	
	void setMilkProduced(double gallons);
	
	
	
	/*******************************************************
	* PROTECTED MEMBERS
	********************************************************/
		
protected: 
	
	/*******************************************************
	*Name of animal
	********************************************************/
	
	double m_milkProduced;

};
#endif