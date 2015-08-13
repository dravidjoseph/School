/*******************************************************
* @file: Position.cpp
* @author: Dravid Joseph
* @date: 8/12/15
* @brief: Implementation file for Position Class
********************************************************/

#include "Position.h"

Position::Position(int row, int col):m_row(0),m_col(0){
	
}

int Position::getRow() const{
	
	return m_row;
	
}

int Position::getCol() const{
	
	return m_col;
	
}