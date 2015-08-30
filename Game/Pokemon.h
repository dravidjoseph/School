/*******************************************************
* @file: Pokemon.h
* @author: Dravid Joseph
* @date: 8/31/15
* @brief: Header file for Pokemon Class
********************************************************/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon{
	
	/*******************************************************
	PUBLIC METHODS
	*******************************************************/
	
public:
	
	/*******************************************************
	*  @pre None
	*  @post Creates and initializes a Pokemon instance
	*  @return Initialzed Pokemon with 6 sides
	*******************************************************/
	
	Pokemon();
	
	/*******************************************************
	*  @pre positive amount
	*  @post reduces m_hp by amount. Doesn't prevent negative values
	*  @return void
	*******************************************************/
	
	void reduceHP(int amount);
	
	/*******************************************************
	*  @pre None
	*  @post returns HP
	*  @return int
	*******************************************************/
	
	int getHP() const;
	
	/*******************************************************
	*  @pre None
	*  @post returns attackLevel
	*  @return int
	*******************************************************/
	
	int getAttackLevel() const;
	
	/*******************************************************
	*  @pre None
	*  @post returns defense Level
	*  @return int
	*******************************************************/
	
	int getDefenseLevel() const;
	
	/*******************************************************
	*  @pre None
	*  @post returns name
	*  @return int
	*******************************************************/
	
	std::string getName() const;
	
	/*******************************************************
	*  @pre valid HP level
	*  @post modify HP
	*  @return void
	*******************************************************/
	void setHP(int hp);
	
	/*******************************************************
	*  @pre valid HP level
	*  @post modify HP
	*  @return void
	*******************************************************/
	void setAttackLevel(int attackLevel);
	
	/*******************************************************
	*  @pre valid HP level
	*  @post modify HP
	*  @return void
	*******************************************************/
	
	void setDefenseLevel(int hp);
	
	/*******************************************************
	*  @pre valid HP level
	*  @post modify HP
	*  @return void
	*******************************************************/
	
	void setName(std::string name);
	
	
	/*******************************************************
	PRIVATE MEMBERS
	*******************************************************/
	
private:
	
	int m_hp;		//health points of pokemon
	
	int m_attackLevel;		//attack level of pokemon
	
	int m_defenseLevel;		//defenese level of pokemon
	
	std::string m_name;		//name of pokemon
	
	
};
#endif