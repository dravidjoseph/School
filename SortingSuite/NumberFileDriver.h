/*******************************************************
* @file: NumberFileDriver.h
* @author: Dravid Joseph
* @date: 10/26/15
* @brief: header for NumberFileDriver class
********************************************************/

#ifndef NUMBER_FILE_DRIVER_H
#define NUMBER_FILE_DRIVER_H

#include <iostream>
#include "NumberFileGenerator.h"

class NumberFileDriver{
	
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
	
	
public:
	
	
	/*******************************************************
	* @pre :  Valid arguments
	* @post : Runs number file generator
	* @return : void
	********************************************************/
	
	static void run(int argc, char** argv);
	
	
	/*******************************************************
	* @pre :  None
	* @post : Prints helpful menu
	* @return : void
	********************************************************/
	
	static void printHelpMenu();
	
	
	
	/*******************************************************
	* PRIVATE METHDOS
	********************************************************/
	
private:
	
	
	/*******************************************************
	* @pre :  valid option
	* @post : returns true if it is valid option, false otherwise
	* @return : bool
	********************************************************/
	
	static bool isValidOption(std::string option);
	
};
#endif