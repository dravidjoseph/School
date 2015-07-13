/*******************************************************
* @file : CyberChicken.cpp
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Implementation of CyberChicken class
********************************************************/

#include "CyberChicken.h"

CyberChicken::CyberChicken():m_name("CyberChicken"),m_sound("Resistance is futile"){
	
}

int CyberChicken::getCyberEggs() const{
	return m_eggs;
}

void CyberChicken::setCyberEggs(int eggs){
	m_eggs = eggs;
}