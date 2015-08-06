/*******************************************************
* @file: SortDriver.h
* @author: Dravid Joseph
* @date: 8/5/15
* @brief: Header for SortDriver class
********************************************************/

#ifndef SORT_DRIVER_H
#define SORT_DRIVER_H

#include <iostream>
#include <fstream>

#include "Sorts.h"

class SortDriver{
	
public:
	
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
	
	/*******************************************************
	* @pre :  arguments is a valid 2-D array and the 
	* arguments contained within are valid
	* @post : A file is created containing the timing 
	* information of the chosen sort(s) on the supplied file.
	* @return : void
	********************************************************/
	
	static void run(int argc, char** argv);
	
	/*******************************************************
	* @pre :  None
	* @post : Contains helpful details
	* @return : void
	********************************************************/
	
	static void printHelpMenu();
	
private:
	
	/*******************************************************
	* PRIVATE METHDOS
	********************************************************/
	
	/*******************************************************
	* @pre :  The input file was created by a NumberFileGenerator
	* @post : returns true if file exists, false otherwise
	* @return : bool
	********************************************************/
	
	static bool isFileAccessible(std::string fileName);
	
	/*******************************************************
	* @pre :  None
	* @post : None
	* @return : bool
	********************************************************/
	
	static bool isSortValid(std::string sortParameter);
	
	/*******************************************************
	* @pre :  None
	* @post : None
	* @return : bool
	********************************************************/
	
	static bool areParametersValid(std::string sortName, std::string inputFileName);
	
	/*******************************************************
	* @pre :  The input file was created with the Number File Generator
	* @post :  The first line of the file is read in, containing the count.
	* @return : int
	********************************************************/
	
	static int getFileCount(std::ifstream& inputFile);
	
	/*******************************************************
	* @pre :  The input file was created with the Number File 
	* Generator, the size was read in, and that size if correct.
	* @post : TThe remainder of input file numbers are read in. File is NOT closed.
	* @return : double
	********************************************************/
	
	static int* createArray(std::ifstream& inputFile, int size);
	
	/*******************************************************
	* @pre :  Original and copy are valid arrays of the correct size.
	* @post : All values from original are copied into copy.
	* @return : void
	********************************************************/
	
	static void copyArray(int original[], int copy[], int size);
};
#endif