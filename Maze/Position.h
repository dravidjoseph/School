/*******************************************************
* @file: Position.h
* @author: Dravid Joseph
* @date: 8/12/15
* @brief: Header file for Position Class
********************************************************/

#include POSITION_H
#define POSITION_H

class Position{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
public:
	
	/*******************************************************
	* @pre :  Nonzero row and column values
	* @post : Position object initialized
	* @return : None
	********************************************************/
	
	Position(int row, int col);
	
	/*******************************************************
	* @pre :  None
	* @post : Return m_row
	* @return : int
	********************************************************/
	
	int getRow() const;
	
	/*******************************************************
	* @pre :  None
	* @post : Return m_col
	* @return : int
	********************************************************/
	
	int getCol() const;
	
	
private:
	
	int m_row;
	int m_col;
	
	
	
	
};
#endif