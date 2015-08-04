/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 7/24/15
* @brief: header for NumberFileDriver class
********************************************************/

#include <iostream>
#include <random>
#include <chrono>
#include <functional>

#include "Sorts.h"
#include "NumberFileDriver.h"
#include "SortDriver.h"



int main(int argc, char** argv){
	
	if(argc < 5){
		
		std::cout<<"Do it again";
	}
	else{
		std::string mode = argv[1];
		
		if(mode == "-create"){
			NumberFileDriver::run(argc,argv);
		} 
		else if(mode == "-sort"){
			SortDriver::run(argc,argv);
		}
		else{
			std::cout<<"Invalid arguments";
		}
		
		
		
	}

	
	
}