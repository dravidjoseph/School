/*******************************************************
* @file: Colosseum.h
* @author: Dravid Joseph
* @date: 8/31/15
* @brief: Header file for Colosseum class
********************************************************/

#ifndef COLOSSEUM_H
#define COLOSSEUM_H

#include <iostream>

#include "Pokemon.h"
#include "Dice.h"

class Colosseum{
	
	/*******************************************************
	PUBLIC METHODS
	*******************************************************/
	
public:
	
	/*******************************************************
	*  @pre None
	*  @post Creates and initializes a Colosseum instance
	*  @return Initialzed Colosseum with 2 dice initialized
	*******************************************************/
	
	Colosseum();
	
	/*******************************************************
	*  @pre None
	*  @post Builds Pokemon
	*  @return void
	*******************************************************/
	
	void userBuild(Pokemon& p);
	
	/*******************************************************
	*  @pre Two valid pokemon references
	*  @post does an attack
	*  @return bool
	*******************************************************/
	
	bool attack(const Pokemon& attacker, Pokemon& defender);
	
	/*******************************************************
	*  @pre two valid pokemon references
	*  @post Handles 10 round fight
	*  @return void
	*******************************************************/
	
	void play(Pokemon& p1, Pokemon& p2);
	
	
	/*******************************************************
	PRIVATE MEMBERS
	*******************************************************/
	
private:
	
	Dice d20;	//20-sided die
	
	Dice d6;	//6-sided die
	
	
};
#endif