/*******************************************************
* @file: NumberFileGenerator.h
* @author: Dravid Joseph
* @date: 7/20/15
* @brief: Templated header for NumberFileGenerator class
********************************************************/

#ifndef NUMBER_FILE_GENERATOR_H
#define NUMBER_FILE_GENERATOR_H

class NumberFileGenerator{

public: 
	
	static void ascending(std::string fileName, int amount);
	
	static void descending(std::string fileName, int amount);
		
	static void random(std::string fileName, int amount, int min, int max);
	
	static void singleValue(std::string fileName, int amount, int value);
};
#endif
