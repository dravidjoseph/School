/*******************************************************
* @file : Chicken.cpp
* @author : Dravid Joseph
* @date : 7/20/2015
* @brief : Implementation of Chicken class
********************************************************/

#include "Chicken.h"

Chicken::Chicken(){
	
	m_eggs = 0;
	FarmAnimal::m_name = "Chicken";
	FarmAnimal::m_sound = "Cluck";
	
}

int Chicken::getEggs() const{
	return m_eggs;
}

void Chicken::setEggs(int eggs){
	m_eggs = eggs;
}