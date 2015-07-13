/*******************************************************
* @file : Cow.h
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Header file for cow class
********************************************************/

#ifndef COW_H
#define COW_H

#include "AnimalPen.h"

class Cow : public AnimalPen{
	
public:
	
	Cow();
	
	double getMilkProduced() const;
	
	void setMilkProduced(double gallons
		
protected: 
	
	double m_milkProduced;

};
#endif