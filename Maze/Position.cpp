/*******************************************************
* @file: Position.cpp
* @author: Dravid Joseph
* @date: 8/10/15
* @brief: Implementation file for Position Class
********************************************************/

#include "Position.h"

Position::Position(int row, int col):row(0),col(0){
	
}

int Position::getRow() const{
	
	return m_row;
	
}

int Position::getCol() const{
	
	return m_col;
	
}