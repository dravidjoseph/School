/*******************************************************
* @file : Chicken.h
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Header file for Chicken class
********************************************************/

#ifndef CHICKEN_H
#define CHICKEN_H

#include "FarmAnimal.h"

class Chicken : public FarmAnimal{
	
public:
	
	Chicken();
	
	
protected:
	
	int getEggs() const;
	
	void setEggs(int eggs);
	
	int m_eggs;
	
	
};
#endif