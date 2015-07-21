/*******************************************************
* @file : Cow.cpp
* @author : Dravid Joseph
* @date : 7/20/2015
* @brief : Implementation file for Cow class
********************************************************/

#include "Cow.h"

Cow::Cow(){
	m_milkProduced = 0;
	FarmAnimal::m_name = "Cow";
	FarmAnimal::m_sound = "Moo";
}

double Cow::getMilkProduced() const{
	return m_milkProduced;
}

void Cow::setMilkProduced(double gallons){
	
	//if gallons is a positive value, set.
	if(gallons > 0){
		m_milkProduced = gallons;
	}
	//otherwise, set to zero.
	else{
		m_milkProduced = 0;
	}
	
}