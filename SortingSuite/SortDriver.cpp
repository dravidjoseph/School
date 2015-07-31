/*******************************************************
* @file: SortDriver.h
* @author: Dravid Joseph
* @date: 7/24/15
* @brief: Implementation file for SortDriver class
********************************************************/

#include "SortDriver.h"
	
void SortDriver::run(int argc, char** argv){
	
	
}
	
void SortDriver::printHelpMenu(){
	
	std::cout << "\nSorting is done one of the following ways:\n\n"
				<< "./prog -sort -bubble inputFile outputFile\n"
				<< "./prog -sort -selection inputFile outputFile\n"
				<< "./prog -sort -insertion inputFile outputFile\n"
				<< "./prog -sort -quick inputFile outputFile\n"
				<< "./prog -sort -quick3 inputFile outputFile\n"
				<< "./prog -sort -merge inputFile outputFile\n"
				<< "./prog -sort -all inputFile outputFile\n"
				<< "Option explainations:\n"
				<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
				<< "\t-selection to time selection sort and store all timing results in outputFile\n"
				<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
				<< "\t-quick to time quick sort and store all timing results in outputFile\n"
				<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
				<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
				<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
				<< "\tinputFile must be file created by a NumberFileGenerator\n"
				<< "\toutputFile must be to a valid path. It will hold the timing results\n";
	
}
	
bool SortDriver::isFileAccessible(std::string fileName){
	
	
	
}
	
bool SortDriver::isSortValid(std::string sortParameter){
	
	
}
	
bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName){
	
}
	
int SortDriver::getFileCount(std::ifstream& inputFile){
	
}
	
int* SortDriver::createArray(std::ifstream& inputFile, int size){
	
	
}
	
void SortDriver::copyArray(int original[], int copy[], int size){
	
	
	
}