/*******************************************************
* @file : Chicken.cpp
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Implementation of Chicken class
********************************************************/

#include "Chicken.h"

Chicken::Chicken():m_name("Chicken"),m_sound("Cluck"){
	
}

int Chicken::getEggs() const{
	return m_eggs;
}

void Chicken::setEggs(int eggs){
	m_eggs = eggs;
}