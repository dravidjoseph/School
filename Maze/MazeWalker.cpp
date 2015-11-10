/*******************************************************
* @file: MazeWalker.cpp
* @author: Dravid Joseph
* @date: 11/16/15
* @brief: Header file for Position Class
********************************************************/

#include "MazeWalker.h"

MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice):m_curPos(Position(startRow,startCol)),m_startPos(Position(startRow,startCol)){
	
	m_maze = mazePtr;
	m_rows = rows;
	m_cols = cols;
	m_curStep = 1;
	
	m_searchType = searchChoice;
	
	m_visited = new int*[m_rows];
	
	for(int i = 0;i<m_rows;i++){
		m_visited[i] = new int[m_cols];
	}
	
	for(int i = 0;i < m_rows;i++){
		for(int j = 0; j < m_cols; j++){
			m_visited[i][j] = 0;
		}
	}
	
	m_visited[startRow][startCol] = m_curStep;
	
}

MazeWalker::~MazeWalker(){
	//m_maze is handled by maze reader
	for(int i = 0; i < m_rows; i++){
		delete m_visited[i];
		m_visited[i] = nullptr;
	}
	delete m_visited;
	m_visited = nullptr;
}

bool MazeWalker::walkMaze(){
	
	m_visited[m_curPos.getRow()][m_curPos.getCol()]++;
	
	if(Search::DFS){
		//Load starting position into stack
		m_moveStack.push(m_startPos);
		
		
		//keep this going until either the stack is empty or the goal is reached
		while(!(m_moveStack.empty() || isGoalReached())){
			//store valid moves from start or last iteration
			storeValidMoves();
			//move m_curPos to the top of stack and go from there. 
			move(m_moveStack.top());
			
			//pop the position from the stack
			m_moveStack.pop();
			
		}
		
		
		
	}
	else{
		//Load starting position into queue
		m_moveQueue.push(m_startPos);
		
		while(!(m_moveQueue.empty() || isGoalReached())){
			//store valid moves from start or last iteration
			storeValidMoves();
			//move m_curPos to the top of queue and go from there.
  
			move(m_moveQueue.front());
			
			//pop the position from the end of the queue
			m_moveStack.pop();
			
		}
	}
	
	return isGoalReached();
}

const int* const* MazeWalker::getVisited() const{
	return m_visited;
}

int MazeWalker::getVisitedRows() const{
	return m_rows;
}

int MazeWalker::getVisitedCols() const{
	return m_cols;
}

const char* const* MazeWalker::getMaze() const{
	return m_maze;
}

void MazeWalker::storeValidMoves(){
	
	/***************************************************
	*local bools to check if move is even possible
	***************************************************/
	bool up = m_curPos.getRow() - 1 >= 0;
	bool down = m_curPos.getRow() + 1 <= m_rows;
	bool left = m_curPos.getCol() - 1 >= 0;
	bool right = m_curPos.getCol() + 1 <= m_cols;
	
	/***************************************************
	*local ints to check specific indices
	* Only used if the corresponding bool evaluates true
	***************************************************/
	int rowAbove = m_curPos.getRow() - 1;
	int rowBelow = m_curPos.getRow() + 1;
	int colLeft = m_curPos.getCol() - 1;
	int colRight = m_curPos.getCol() + 1;
	
	/***************************************************
	*For consistency, not strictly necessary
	***************************************************/
	int row = m_curPos.getRow();
	int col = m_curPos.getCol();
	
	if(Search::DFS){
		//valid up move
		if(up){
			//Check if up move is a wall
			if(m_maze[rowAbove][col] != 'W'){
				m_moveStack.push(Position(rowAbove,col));
			}
		}
		if(right){
			if(m_maze[row][colRight] != 'W'){
				m_moveStack.push(Position(row,colRight));
			}
		}
		if(down){
			if(m_maze[rowBelow][col] != 'W'){
				m_moveStack.push(Position(rowBelow,col));
			}
		}
		if(left){
			if(m_maze[rowAbove][col] != 'W'){
				m_moveStack.push(Position(row,colLeft));
			}
		}
		
	}
	//BFS
	else{
		if(up){
			//Check if up move is a wall
			if(m_maze[rowAbove][col] != 'W'){
				m_moveQueue.push(Position(rowAbove,col));
			}
		}
		if(right){
			if(m_maze[row][colRight] != 'W'){
				m_moveQueue.push(Position(row,colRight));
			}
		}
		if(down){
			if(m_maze[rowBelow][col] != 'W'){
				m_moveQueue.push(Position(rowBelow,col));
			}
		}
		if(left){
			if(m_maze[rowAbove][col] != 'W'){
				m_moveQueue.push(Position(row,colLeft));
			}
		}
	}
}

void MazeWalker::move(Position& p){
	m_curPos = p;
	m_visited[m_curPos.getRow()][m_curPos.getCol()] = m_curStep;
}

bool MazeWalker::isGoalReached() const{
	return m_maze[m_curPos.getRow()][m_curPos.getCol()]=='E';
}