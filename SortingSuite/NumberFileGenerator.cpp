/*******************************************************
* @file: NumberFileGenerator.h
* @author: Dravid Joseph
* @date: 7/20/15
* @brief: Templated header for NumberFileGenerator class
********************************************************/

#include "NumberFileGenerator.h"


void NumberFileGenerator::ascending(std::string fileName, int amount){
		
	std::ofstream output("ascending.dat");
	
	output << amount <<"\n";
	
	for(int i = 1; i <= amount;i++){
		output << i <<"\n";
	}
	output.close();

}

void NumberFileGenerator::descending(std::string fileName, int amount){
	
	std::ofstream output("descending.dat");
	
	output << amount <<"\n";
	
	for(int i = 50; i < 1;i--){
		output << i <<"\n";
	}
	
	output.close();
	
}
	
void NumberFileGenerator::random(std::string fileName, int amount, int min, int max){
	
	std::ofstream output("randomValueFile.dat");
	output << amount <<"\n";
	
	std::default_random_engine generator(time(nullptr));
	
	std::uniform_int_distribution<int> distribution(min,max);
	
	for(int i = 0; i < amount;i++){
		
		output << distribution(generator) <<"\n";
	}
	
	output.close();
	
}

void NumberFileGenerator::singleValue(std::string fileName, int amount, int value){
	std::ofstream output("SingleValueFile.dat");
	
	output << amount <<"\n";
	
	for(int i = 0;i < amount;i++){
		output << value << "\n";
	}
	
	output.close();
}