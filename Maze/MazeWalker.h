/*******************************************************
* @file: MazeWalker.h
* @author: Dravid Joseph
* @date: 8/10/15
* @brief: Header file for MazeWalker Class
********************************************************/

#ifndef MAZEWALKER_H
#define MAZEWALKER_H

#include <stack>
#include <queue>
#include <iostream>

#include "Position.h"

class MazeWalker{
	
public:
	
	MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols);
	
	~MazeWalker();
	
	void walkMaze();
	
protected:
	
	void storeValidMoves();
	
	void move(Position& p);
	
	bool isGoalReached() const;
	
	bool m_isDFS;
	
	char** m_maze;
	
	bool** m_visited;
	
	int m_rows;
	
	int m_cols;
	
	Position m_curPos;
	
	Position m_startPos;
	
	std::stack<Position> m_moveStack;
	
	std::queue<Position> m_moveQueue;
	
	
};
#endif