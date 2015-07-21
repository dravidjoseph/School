/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 7/20/15
* @brief: Header file for DoubleLinkedList class
********************************************************/

#include <iostream>
#include <random>
#include <chrono>

#include "Sorts.h"



int* createRandomIntArray(int size, int min, int max){
	
	//declares and seeds the generator
	std::default_random_engine generator(time(nullptr));
	
	//creates a uniform distribution of integers from min to max.
	std::uniform_int_distribution<int> distribution(min,max);
	
	//declare the array pointer
	int* arr = new int[size];
	
	//insert entries into array
	for(int i = 0;i<size;i++){
		arr[i] = distribution(generator);
	}
	
	return arr;
	
}

void printMenu(){
	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
			<< "Enter choice: ";
}

void printArray(bool flag){
	
	std::string confirm = "";
	if(!flag){
		std::cout<<"Do you want to print the unsorted array? (y/n): ";
	}
	else{
		std::cout<<"Do you want to print the sorted array? (y/n): ";
	}
	std::cin>>confirm;
	if(confirm == "y"){
		
		if(!flag){
			std::cout<<"Here is the unsorted array: \n";
		}
		else{
			std::cout<<"Here is the sorted array: \n";
		}
		
		std::cout<<"["
		for(int i = 0;i<size;i++){
			std::cout<<arr[i];
			
			if(i != size-1){
				std::cout<<",";
			}
			else{
				std::cout<<"]\n\n";
			}
		}
	}
}

int main(){
	
	bool flag = false;
	bool flag2 = false;
	int choice = 0;
	int size = 0;
	int min = 0;
	int max = 0;
	
	
	
	
	while(!flag){
		
		printMenu();
		
		std::cin>>choice;
		
		std::cout<<"\nInput a size for the random array: ";
		std::cin>>size;
		
		std::cout<<"\nInput a lower bound of on the range of random integers: ";
		std::cin>>min;
		
		std::cout<<"\nInput an upper bound on the range of random integers: ";
		std::cin>>max;
		
		int* arr = createRandomIntArray(size,min,max);
		
		printArray(flag2);
		
		if(choice == 1){
			std::cout<<"Sorting with bubble sort...\n";
		}
		else if(choice == 2){
			
			std::cout<<"Sorting with insertion sort...\n";
			
		}
		else if(choice == 3){
			
			std::cout<<"Sorting with selection sort...\n";
			
		}
		else if(choice == 4){
			
			std::cout<<"Sorting with bogo sort...\n";
			
		}
		
		flag2 = true;
		
		printArray(flag2);
		
		
		
		
		
	}
	
	
	
	return 0;
}