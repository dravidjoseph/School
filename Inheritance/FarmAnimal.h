/*******************************************************
* @file : FarmAnimal.h
* @author : Dravid Joseph
* @date : 7/20/2015
* @brief : Header file for FarmAnimal class.
********************************************************/

#ifndef FARM_ANIMAL_H
#define FARM_ANIMAL_H

#include <iostream>

class FarmAnimal{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
public:
	
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes FarmAnimal
	* @return : None
	********************************************************/
	FarmAnimal();
	
	
	/*******************************************************
	* @pre :  None
	* @post : retrieves name of animal
	* @return : std::string
	********************************************************/
	std::string getName() const;
	
	
	/*******************************************************
	* @pre :  valid name
	* @post : sets new value of name of animal
	* @return : void
	********************************************************/
	void setName(std::string name);
	
	
	/*******************************************************
	* @pre :  None
	* @post : retrieves sound animal makes
	* @return : std::string
	********************************************************/
	std::string getSound() const;
	
	/*******************************************************
	* @pre :  valid sound
	* @post : sets new value of animal sound
	* @return : void
	********************************************************/
	void setSound(std::string sound);
	
	
	/*******************************************************
	* PROTECTED MEMBERS
	********************************************************/
	
protected:
	
	/*******************************************************
	*Name of animal
	********************************************************/
	std::string m_name;
	
	/*******************************************************
	*Sound animal makes
	********************************************************/
	std::string m_sound;
	
};
#endif