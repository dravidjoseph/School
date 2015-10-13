/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 10/26/15
* @brief: Driver for Sorts program
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

void printArray(int* arr, int size){
	std::cout<<"[";
	for(int i = 0;i<size-1;i++){
		std::cout<<arr[i];
		std::cout<<",";
	}
	std::cout<<arr[size-1];
	std::cout<<"]\n";
}



int main(){
	
	//Declare all necessary local variables
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;
	
	std::string confirm = "";
	bool flag = false;
	int choice = 0;
	int size = 0;
	int min = 0;
	int max = 0;
	
	while(!flag){
		
		printMenu();
		std::cin>>choice;
		
		std::cout<<"Input a size for the random array: ";
		std::cin>>size;
		
		std::cout<<"Input a lower bound on the range of random numbers: ";
		std::cin>>min;
		
		std::cout<<"Input an upper bound on the range of random numbers: ";
		std::cin>>max;
		
		int* arr = createRandomIntArray(size,min,max);
		
		std::cout<<"Do you want to print the unsorted array? (y/n): ";
		std::cin>>confirm;
		if((confirm.compare("y") == 0)){
			printArray(arr,size);
		} 
		
		if(choice == 1){
			std::cout<<"Sorting with bubble sort...\n";
			
			start = std::chrono::system_clock::now();
			Sorts<int>::bubbleSort(arr,size);
			end = std::chrono::system_clock::now();
			
		}
		else if(choice == 2){
			std::cout<<"Sorting with insertion sort...\n";
			
			start = std::chrono::system_clock::now();
			Sorts<int>::insertionSort(arr,size);
			end = std::chrono::system_clock::now();
		}
		else if(choice == 3){
			std::cout<<"Sorting with selection sort...\n";
			
			start = std::chrono::system_clock::now();
			Sorts<int>::selectionSort(arr,size);
			end = std::chrono::system_clock::now();
		}
		else if(choice == 4){
			std::cout<<"Sorting with bogo sort...\n";
			
			start = std::chrono::system_clock::now();
			Sorts<int>::bogoSort(arr,size);
			end = std::chrono::system_clock::now();
		}
		else{
			std::cout<<"Invalid choice";
		}
		if(choice == 1 || choice == 2 || choice == 3 || choice == 4){
			
			std::cout<<"Do you want to print the sorted array? (y/n): ";
			std::cin>>confirm;
			if((confirm.compare("y") == 0)){
				printArray(arr,size);
			} 
			
			elapsed = end - start;
		
			std::cout<<size<<" numbers were sorted in "<<elapsed.count()<<" seconds.";
		}
		
		
		std::cout<<"\nDo you want to quit? (y/n): ";
		std::cin>>confirm;
		
		if(confirm.compare("y") == 0){
			flag = true;
		}
		
		delete[] arr;
		arr = nullptr;
		
		
	}
	
}