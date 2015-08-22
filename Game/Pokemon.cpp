/*******************************************************
* @file: Pokemon.cpp
* @author: Dravid Joseph
* @date: 8/22/15
* @brief: Implementation file for Pokemon class
********************************************************/

#include "Pokemon.h"

Pokemon::Pokemon():m_hp(0),m_attackLevel(0),m_defenseLevel(0),m_name(""){
	
}

void Pokemon::reduceHP(int amount){
	
	m_hp -= amount;
	
}

int Pokemon::getHP() const{
	
	return m_hp;
	
}

int Pokemon::getAttackLevel() const{
	
	return m_attackLevel;
	
}

int Pokemon::getDefenseLevel() const{
	
	return m_defenseLevel;
	
}

std::string Pokemon::getName() const{
	
	return m_name;
	
}

void Pokemon::setHP(int hp){
	
	m_hp = hp;
	
}

void Pokemon::setAttackLevel(int attackLevel){
	
	m_attackLevel = attackLevel;
	
}

void Pokemon::setDefenseLevel(int defenseLevel){
	
	m_defenseLevel = defenseLevel;
	
}

void Pokemon::setName(std::string name){
	
	m_name = name;
	
}