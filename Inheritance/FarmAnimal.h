/*******************************************************
* @file : FarmAnimal.h
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Header file for FarmAnimal class.
********************************************************/

#ifndef FARM_ANIMAL_H
#define FARM_ANIMAL_H

#include <iostream>

class FarmAnimal{
	
public:
	
	FarmAnimal();
	
	std::string getName() const;
	
	void setName(std::string name);
	
	std::string getSound() const;
	
	void setSound(std::string sound);
	
	
protected:
	
	std::string m_name;
	
	std::string m_sound;
	
};
#endif