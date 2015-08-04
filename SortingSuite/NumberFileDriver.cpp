/*******************************************************
* @file: NumberFileDriver.cpp
* @author: Dravid Joseph
* @date: 7/24/15
* @brief: Implementation for NumberFileDriver class
********************************************************/

#include "NumberFileDriver.h"

void NumberFileDriver::run(int argc, char** argv){
	
	std::string flag = argv[2];
	std::string fileName = argv[3];
	std::string amt = argv[4];
	
	int amount = 0;
	amount = atoi(amt.c_str());
	
	
	int value = 0;
	int min = 0;
	int max = 0;
	
	if(argc == 6){
		std::string val = argv[5];
		value = atoi(val.c_str());
		
	}
	if(argc == 7){
		std::string mini = argv[5];
		min = atoi(mini.c_str());
		std::string maxi = argv[6];
		max = atoi(maxi.c_str());
	}
	
	if(isValidOption(flag)){
		if(flag == "-a"){
			NumberFileGenerator::ascending(fileName,amount);
		}
		else if(flag == "-d"){
			NumberFileGenerator::descending(fileName,amount);
		}
		else if(flag == "s"){
			NumberFileGenerator::random(fileName,amount,min,max);
		}
		else{
			NumberFileGenerator::singleValue(fileName,amount,value);
		}
	}
	else{
		printHelpMenu();
	}
	
	
}
	
void NumberFileDriver::printHelpMenu(){
	
	std::cout << "\nUse Number File Generator in one of the following ways:\n\n"
				<< "./prog -create -a filename amount\n"
				<< "./prog -create -d filename amount\n"
				<< "./prog -create -s filename amount value\n"
				<< "./prog -create -r filename amount min max\n"
				<< "Option explainations:\n"
				<< "\t-a for ascending\n"
				<< "\t-d for descending\n"
				<< "\t-s for a single value\n"
				<< "\t-r for random values\n"
				<< "\tfilename is the ouput file name\n"
				<< "\tamount is the amount of random numbers to place in the file\n"
				<< "\tvalue is the single number that will be written to file in -s mode\n"
				<< "\tmin is the low end of the range of random numbers\n"
				<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";
	
}

bool NumberFileDriver::isValidOption(std::string option){
	if(option == "-a" || option == "-d" || option == "-s" || option == "-r"){
		return true;
	}
	else{
		return false;
	}
}