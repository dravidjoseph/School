/*******************************************************
* @file : FarmAnimal.cpp
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Implementation of FarmAnimal class
********************************************************/

#include "FarmAnimal.h"

FarmAnimal::FarmAnimal():m_name(""),m_sound(""){
	
}

std::string FarmAnimal::getName() const{
	return m_name;
}

void FarmAnimal::setName(std::string name){
	m_name = name;
}

std::string FarmAnimal::getSound() const{
	return m_sound;
}

void FarmAnimal::setSound(std::string sound){
	m_sound = sound;
}