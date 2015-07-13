/*******************************************************
* @file : CyberChicken.h
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Header file for CyberChicken class
********************************************************/

#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H

#include "Chicken.h"

class CyberChicken : public Chicken{
	
public:
	
	CyberChicken();
	
	int getCyberEggs() const;
	
	void setCyberEggs(int eggs);

};
#endif