/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 11/2/15
* @brief: header for NumberFileDriver class
********************************************************/


//Defined libraries
#include <iostream>

//User-defined classes
#include "NumberFileDriver.h"
#include "SortDriver.h"
#include "Test.h"



int main(int argc, char** argv){
	
	//If fewer than 5 command line arguements
	if(argc < 5 && argc != 2){
		
		std::cout<<"Do it again.  This isn't sufficient for anything.\n";
	}
	
	else{
		std::string mode = argv[1];
		
		//passes command line arguments to number file driver to create the file.
		if(mode.compare("-create") == 0){
			NumberFileDriver::run(argc,argv);
		} 
		//passes command line arguments to sort driver to do timing-related things
		else if(mode.compare("-sort") == 0){
			SortDriver::run(argc,argv);
		}
		//not valid
		else{
		}
	}
	if(argc == 2){
		std::string mode = argv[1];
		if(mode.compare("-test") == 0){
			Test myTest(std::cout);
			myTest.runTests();
		}
		else{
			std::cout<<"Invalid arguments";
		}
	}
	
	return 0;
	
}

//Talk about a short driver, eh?