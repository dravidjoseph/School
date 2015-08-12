/*******************************************************
* @file: Position.h
* @author: Dravid Joseph
* @date: 8/10/15
* @brief: Header file for Position Class
********************************************************/

#include POSITION_H
#define POSITION_H

class Position{
	
	
	
public:
	
	Position(int row, int col);
	
	int getRow() const;
	
	int getCol() const;
	
	
private:
	
	int m_row;
	int m_col;
	
	
	
	
};
#endif