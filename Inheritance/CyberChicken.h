/*******************************************************
* @file : CyberChicken.h
* @author : Dravid Joseph
* @date : 10/19/2015
* @brief : Header file for CyberChicken class
********************************************************/

#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H

#include "Chicken.h"

class CyberChicken : public Chicken{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
public:
	
	/*******************************************************
	* @pre :  None
	* @post : Initializes CyberChicken
	* @return : None
	********************************************************/
	
	CyberChicken();
	
	/*******************************************************
	* @pre :  None
	* @post : retrieves number of cybereggs laid
	* @return : int
	********************************************************/
	
	int getCyberEggs() const;
	
	/*******************************************************
	* @pre :  valid number of eggs (>0)
	* @post : sets number of cyber eggs
	* @return : void
	********************************************************/
	
	void setCyberEggs(int eggs);

};
#endif