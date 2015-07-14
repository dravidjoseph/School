/*******************************************************
* @file : Cow.h
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Header file for cow class
********************************************************/

#ifndef COW_H
#define COW_H

#include "FarmAnimal.h"

class Cow : public FarmAnimal{
	
public:
	
	Cow();
	
	double getMilkProduced() const;
	
	void setMilkProduced(double gallons);
		
protected: 
	
	double m_milkProduced;

};
#endif