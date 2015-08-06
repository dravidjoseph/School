/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 8/5/15
* @brief: header for NumberFileDriver class
********************************************************/


//Defined libraries
#include <iostream>



//User-defined classes
#include "NumberFileDriver.h"
#include "SortDriver.h"



int main(int argc, char** argv){
	
	//If fewer than 5 command line arguements
	if(argc < 5){
		
		std::cout<<"Do it again.  This isn't sufficient for anything.\n";
	}
	else{
		std::string mode = argv[1];
		
		//passes command line arguments to number file driver to create the file.
		if(mode == "-create"){
			NumberFileDriver::run(argc,argv);
		} 
		//passes command line arguments to sort driver to do timing-related things
		else if(mode == "-sort"){
			SortDriver::run(argc,argv);
		}
		//not valid
		else{
			std::cout<<"Invalid arguments";
		}
			
	}
}

//Talk about a short driver, eh?