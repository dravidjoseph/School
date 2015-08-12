/*******************************************************
* @file: MazeWalker.h
* @author: Dravid Joseph
* @date: 8/12/15
* @brief: Header file for MazeWalker Class
********************************************************/

#ifndef MAZEWALKER_H
#define MAZEWALKER_H

#include <stack>
#include <queue>
#include <iostream>

#include "Position.h"

class MazeWalker{
	
	/*******************************************************
	* PUBLIC METHODS
	********************************************************/
	
public:
	
	/*******************************************************
	* @pre :  Valid parameters
	* @post : MazeWalker Initialized
	* @return : None
	********************************************************/
	
	MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols);
	
	/*******************************************************
	* @pre :  None
	* @post : Deallocates MazeWalker
	* @return : None
	********************************************************/
	
	~MazeWalker();
	
	/*******************************************************
	* @pre :  None
	* @post : traverses maze searching for exit
	* @return : None
	********************************************************/
	
	void walkMaze();
	
	/*******************************************************
	* PROTECTED METHODS
	********************************************************/
	
protected:
	
	/*******************************************************
	* @pre :  None
	* @post : Stores valid moves in stack or queue
	* @return : void
	********************************************************/
	
	void storeValidMoves();
	
	/*******************************************************
	* @pre :  Valid position
	* @post : Moves based on position
	* @return : void
	********************************************************/
	
	void move(Position& p);
	
	/*******************************************************
	* @pre :  None
	* @post : Returns true if exit is reached, false otherwise.
	* @return : bool
	********************************************************/
	
	bool isGoalReached() const;
	
	/*******************************************************
	* PROTECTED MEMBERS
	********************************************************/
	
	bool m_isDFS;	//true if dfs, false if bfs
	
	char** m_maze;	//2D array which holds characters for maze
	
	bool** m_visited;	//2D boolean array.
	
	int m_rows;		//field to hold rows
	
	int m_cols;		//field to hold columns
	
	Position m_curPos;		//current position
	
	Position m_startPos;	//starting position
	
	std::stack<Position> m_moveStack;	//stack which holds positions
	
	std::queue<Position> m_moveQueue;	//queue which holds positions.
	
	
};
#endif