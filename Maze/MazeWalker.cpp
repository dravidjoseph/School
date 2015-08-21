/*******************************************************
* @file: MazeWalker.cpp
* @author: Dravid Joseph
* @date: 8/12/15
* @brief: Header file for Position Class
********************************************************/

#include "MazeWalker.h"


MazeWalker::MazeWalker(char** mazePtr, int startRow, int startCol, int rows, int cols,bool dfs):m_curPos(Position(startRow,startCol)),m_startPos(Position(startRow,startCol)){
	
	m_isDFS = dfs;
	
	m_maze = mazePtr;
	
	m_visited = nullptr;
	
	m_rows = rows;		
	
	m_cols = cols;		
	
	m_visited = new bool*[m_rows];	
	
	//initialize all values in boolean array to false
	
	for(int i = 0;i < m_rows;i++){
		
		m_visited[i] = new bool[m_cols];
		
	}
	
	for(int i = 0;i<m_rows;i++){
		
		for(int j = 0;j< m_cols;j++){
			
			m_visited[i][j] = false;
			
		}
		
	}
	
	//initialize start position as true
	m_visited[m_startPos.getRow()][m_startPos.getCol()] = true;
	
	
	
	
}

MazeWalker::~MazeWalker(){
	
	for(int i = 0; i < m_cols; i++){
		delete[] m_visited[i];
		m_visited[i] = nullptr;
	}
	
	delete[] m_visited;
	m_visited = nullptr;
	
}
	
void MazeWalker::walkMaze(){
	
	storeValidMoves();
	
	if(m_isDFS){
		//do dfs
	
		while(!m_moveStack.empty()){
			
			std::cout << "Visiting Position ("<<m_curPos.getRow() <<", "<<m_curPos.getCol()<<")\n";
			std::cout<<"---------------------------\n\n";
			
			printVisited();
			
			storeValidMoves();
			
			move(m_moveStack.top());
			
			m_moveStack.pop();
			
			if(isGoalReached()){
				std::cout<<"Found exit!\n";
				return;
			}
			
			
			
			
		}
		
		std::cout<<"No exit";
		
	}
	else{
		
		//do bfs
		while(!m_moveQueue.empty()){
			
			std::cout << "Visiting Position ("<<m_curPos.getRow() <<", "<<m_curPos.getCol()<<")\n";
			std::cout<<"---------------------------\n\n";
			
			printVisited();
			
			storeValidMoves();
			
			move(m_moveQueue.front());
			
			m_moveQueue.pop();
			
			if(isGoalReached()){
				std::cout<<"Found exit!\n";
				return;
			}
			
			
		}	
		
		std::cout<<"No exit";	
	}	
}


	
void MazeWalker::storeValidMoves(){
		
		//Created local variables for readability
		bool up = m_curPos.getRow() - 1 >= 0;
		bool down  = m_curPos.getRow() + 1 < m_rows;
		bool left = m_curPos.getCol() - 1 >= 0;
		bool right = m_curPos.getCol() + 1 < m_cols;
		
		int rowBelow = m_curPos.getRow()+1;
		int rowAbove = m_curPos.getRow()-1;
		int colRight = m_curPos.getCol()+1;
		int colLeft = m_curPos.getCol()-1;
		
		int row = m_curPos.getRow();
		int col = m_curPos.getCol();
	
	
		if(m_isDFS){
			if(up){
				if(m_maze[rowAbove][col] != 'W' && !m_visited[rowAbove][col]){
					m_moveStack.push(Position(rowAbove,col));
				}
			}
			if(down){
				if(m_maze[rowBelow][col] != 'W' && !m_visited[rowBelow][col]){
					m_moveStack.push(Position(rowBelow,col));
				}
			}
			if(left){
				if(m_maze[row][colLeft] != 'W' && !m_visited[row][colLeft]){
					m_moveStack.push(Position(row,colLeft));
				}
			}
			if(right){
				if(m_maze[row][colRight] != 'W' && !m_visited[row][colRight]){
					m_moveStack.push(Position(row,colRight));
				}
			}
		}
		else{
			if(up){
				if(m_maze[rowAbove][col] != 'W' && !m_visited[rowAbove][col]){
					m_moveQueue.push(Position(rowAbove,col));
				}
			}
			if(down){
				if(m_maze[rowBelow][col] != 'W' && !m_visited[rowBelow][col]){
					m_moveQueue.push(Position(rowBelow,col));
				}
			}
			if(left){
				if(m_maze[row][colLeft] != 'W' && !m_visited[row][colLeft]){
					m_moveQueue.push(Position(row,colLeft));
				}
			}
			if(right){
				if(m_maze[row][colRight] != 'W' && !m_visited[row][colRight]){
					m_moveQueue.push(Position(row,colRight));
				}
			}
		}
	
}
	
void MazeWalker::move(Position& p){
	
	m_curPos = p;
	m_visited[m_curPos.getRow()][m_curPos.getCol()] = true;
	
}

void MazeWalker::printVisited() const{
	
	for(int i = 0; i < m_rows; i++){
		
		for(int j = 0; j < m_cols; j++){
			
			std::cout<<m_visited[i][j];
			
		}
		std::cout<<"\n";
		
	}
	std::cout<<"\n";
	
}
	
bool MazeWalker::isGoalReached() const{
	return m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E';
}