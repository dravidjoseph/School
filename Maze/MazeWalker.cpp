/*******************************************************
* @file: MazeWalker.cpp
* @author: Dravid Joseph
* @date: 11/16/15
* @brief: Header file for Position Class
********************************************************/

#include "MazeWalker.h"

MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice):m_curPos(Position(startRow,startCol)),m_startPos(Position(startRow,startCol)){
	
	
	//initializes all local variables
	m_maze = mazePtr;
	m_rows = rows;
	m_cols = cols;
	m_curStep = 1;
	m_searchType = searchChoice;
	
	
	
	
	//Initialize m_visited, a 2D integer array
	m_visited = new int*[m_rows];
	
	//initialize each row to an integer array
	for(int i = 0;i<m_rows;i++){
		m_visited[i] = new int[m_cols];
	}
	
	//Populate the array with zeros
	for(int i = 0;i < m_rows;i++){
		for(int j = 0; j < m_cols; j++){
			m_visited[i][j] = 0;
		}
	}
	
	//Replace zero at the starting location with 1.
	m_visited[startRow][startCol] = m_curStep;
	m_curStep++;	//increment for future use.
}

MazeWalker::~MazeWalker(){
	//m_maze is handled by maze reader
	
	//delete integer arrays each pointer holds
	for(int i = 0; i < m_rows; i++){
		delete m_visited[i];
		m_visited[i] = nullptr;
	}
	//delete the pointers (is this technically necessary?)
	delete m_visited;
	m_visited = nullptr;
}

bool MazeWalker::walkMaze(){
	
	//Do DFS
	if(m_searchType == Search::DFS){
		//Load starting position into stack
		m_moveStack.push(m_startPos);
		
		//keep this going until either the stack is empty or the goal is reached
		while(!(m_moveStack.empty() || isGoalReached())){
			//store valid moves from start or last iteration
			storeValidMoves();
			//move m_curPos to the top of stack 
			move(m_moveStack.top());
			
			//pop the position from the stack
			m_moveStack.pop();
			
		}	
	}
	else{
		//Load starting position into queue
		m_moveQueue.push(m_startPos);
		
		//keep going until queue is empty or goal is reached
		while(!(m_moveQueue.empty() || isGoalReached())){
			
			//store valid moves at the end of the queue
			storeValidMoves();
			//Remove from the front of the queue
  		  	m_moveQueue.pop();
			
			//Ensures that once the queue is empty no moves will be made.
			if(!m_moveQueue.empty()){
				move(m_moveQueue.front());
			}
		}
	}
	return isGoalReached();		//either it's reached or it isn't
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
	*Assumes m_curPos is valid to begin with
	***************************************************/
	bool up = m_curPos.getRow() - 1 >= 0;
	bool down = m_curPos.getRow() + 1 < m_rows;
	bool left = m_curPos.getCol() - 1 >= 0;
	bool right = m_curPos.getCol() + 1 < m_cols;
	
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
	
	if(m_searchType == Search::DFS){
		if(up){
			if(m_maze[rowAbove][col] != 'W' && m_visited[rowAbove][col] == 0){
				m_moveStack.push(Position(rowAbove,col));
			}
		}
		if(right){
			if(m_maze[row][colRight] != 'W' && m_visited[row][colRight] == 0){
				m_moveStack.push(Position(row,colRight));
			}
		}
		if(down){
			if(m_maze[rowBelow][col] != 'W' && m_visited[rowBelow][col] == 0){
				m_moveStack.push(Position(rowBelow,col));
			}
		}
		if(left){
			if(m_maze[row][colLeft] != 'W' && m_visited[row][colLeft] == 0){
				m_moveStack.push(Position(row,colLeft));
			}
		}
	}
	//BFS
	else{
		if(up){
			if(m_maze[rowAbove][col] != 'W' && m_visited[rowAbove][col] == 0){
				m_moveQueue.push(Position(rowAbove,col));
			}
		}
		if(right){
			if(m_maze[row][colRight] != 'W' && m_visited[row][colRight] == 0){
				m_moveQueue.push(Position(row,colRight));
			}
		}
		if(down){
			if(m_maze[rowBelow][col] != 'W' && m_visited[rowBelow][col] == 0){
				m_moveQueue.push(Position(rowBelow,col));
			}
		}
		if(left){
			if(m_maze[row][colLeft] != 'W' && m_visited[row][colLeft] == 0){
				m_moveQueue.push(Position(row,colLeft));
			}
			
		}
	}
}

void MazeWalker::move(Position& p){
	//Change m_curPos to p
	m_curPos = p;
	//mark step ONLY if the move hasn't been visited.
	if(m_visited[m_curPos.getRow()][m_curPos.getCol()] == 0){
		m_visited[m_curPos.getRow()][m_curPos.getCol()] = m_curStep;
		m_curStep++;
	}
}

bool MazeWalker::isGoalReached() const{
	return m_maze[m_curPos.getRow()][m_curPos.getCol()]=='E';
}