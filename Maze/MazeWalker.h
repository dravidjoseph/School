/*******************************************************
* @file: MazeWalker.h
* @author: Dravid Joseph
* @date: 11/16/15
* @brief: Header file for MazeWalker Class
********************************************************/

#ifndef MAZE_WALKER_H
#define MAZE_WALKER_H

#include <iostream>
#include <stack>
#include <queue>

#include "Position.h"

enum class Search {DFS,BFS};

class MazeWalker{


	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
public:
	
	/*******************************************************
	* @pre :  mazePtr is a valid maze
	* @post : Allocates mazewalker
	* @return : None
	********************************************************/
	
	MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice);
	
	/*******************************************************
	* @pre :  Visited array still exists
	* @post : Deallocates visited array
	* @return : None
	********************************************************/
	
	~MazeWalker();
	
	/*******************************************************
	* @pre :  valid maze
	* @post : returns true if exit is reached, false otherwise
	* @return : bool
	********************************************************/
	
	bool walkMaze();
	
	/*******************************************************
	* @pre :  None
	* @post : access visited array
	* @return : const int ptr
	********************************************************/
	
	const int* const* getVisited() const;
	
	/*******************************************************
	* @pre :  valid filename
	* @post : Allocates 2D char array with maze information
	* @return : None
	********************************************************/
	
	int getVisitedRows() const;
	
	/*******************************************************
	* @pre :  valid filename
	* @post : Allocates 2D char array with maze information
	* @return : None
	********************************************************/
	
	int getVisitedCols() const;
	
	/*******************************************************
	* @pre :  valid filename
	* @post : Allocates 2D char array with maze information
	* @return : None
	********************************************************/
	
	const char* const* getMaze() const;
	
protected:
	
	/*******************************************************
	* @pre :  Valid m_curPos
	* @post : Data structures loaded with moves
	* @return : None
	********************************************************/
	
	void storeValidMoves();
	
	/*******************************************************
	* @pre :  Valid Position
	* @post : Current position set to P
	* @return : None
	********************************************************/
	
	void move(Position& p);
	
	/*******************************************************
	* @pre :  none
	* @post : determines if goal is reached
	* @return : bool
	********************************************************/
	
	bool isGoalReached() const;
	
	Search m_searchType;
	
	const char* const* m_maze;
	
	int** m_visited;
	
	int m_rows;
	int m_cols;
	
	Position m_curPos;
	Position m_startPos;
	
	std::stack<Position> m_moveStack;
	std::queue<Position> m_moveQueue;
	
	int m_curStep;
};
#endif