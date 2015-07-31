/*******************************************************
* @file: NumberFileDriver.h
* @author: Dravid Joseph
* @date: 7/24/15
* @brief: header for NumberFileDriver class
********************************************************/

#ifndef NUMBER_FILE_DRIVER_H
#define NUMBER_FILE_DRIVER_H

class NumberFileDriver{
	
public:
	
	static void run(int argc, char** argv);
	
	static void printHelpMenu();
	
private:
	
	static bool isValidOption(std::string option);
	
};
#endif