/*******************************************************
* @file: MazeReader.h
* @author: Dravid Joseph
* @date: 8/10/15
* @brief: Header file for MazeReader Class
********************************************************/

#ifndef MAZEREADER_H
#define MAZEREADER_H


class MazeReader{
	
	
public:
	
	
	MazeReader(std::stringn file) throw (MazeCreationException);
	
	~MazeReader();
	
	char** getMaze() const;
	
	int getCols() const;
	
	int getRows() const;
	
	int getStartCol() const;
	
	int getStartRow() const;
	
	
protected:
	
	void readMaze() throw (MazeCreationException);
	
	
	
	
	
};
#endif