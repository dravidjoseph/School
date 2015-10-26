/*******************************************************
* @file: NumberFileGenerator.h
* @author: Dravid Joseph
* @date: 10/26/15
* @brief: Templated header for NumberFileGenerator class
********************************************************/

#ifndef NUMBER_FILE_GENERATOR_H
#define NUMBER_FILE_GENERATOR_H

#include <fstream>
#include <random>
#include <ctime>

class NumberFileGenerator{

public: 
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
	
	/*******************************************************
	* @pre :  fileName is valid path/filename. Amount is greater than zero
	* @post : A file is created with the amount of number is ascending order. 
	* The amount of numbers in the file is the first number in the file
	* @return : void
	********************************************************/
	
	static void ascending(std::string fileName, int amount);
	
	/*******************************************************
	* @pre :  fileName is valid path/filename. Amount is greater than zero
	* @post : A file is created with the amount of number is descending order. 
	* The amount of numbers in the file is the first number in the file
	* @return : void
	********************************************************/
	
	static void descending(std::string fileName, int amount);
		
	/*******************************************************
	* @pre :  fileName is valid path/filename. Amount is greater than zero
	* @post : A file is created with the specified amount of numbers
	* The amount of numbers in the file is the first number in the file
	* @return : void
	********************************************************/
		
	static void random(std::string fileName, int amount, int min, int max);
	
	
	/*******************************************************
	* @pre :  fileName is valid path/filename. Amount is greater than zero
	* @post : File created wiht single number amount of times
	* The amount of numbers in the file is the first number in the file
	* @return : void
	********************************************************/
	static void singleValue(std::string fileName, int amount, int value);
};
#endif
