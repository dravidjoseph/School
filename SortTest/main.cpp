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

void printMenu(){
	std::cout 	<< "\n\nSelect a sort:\n"
			<< "1) Bubble Sort\n"
			<< "2) Insertion Sort\n"
			<< "3) Selection Sort\n"
			<< "4) Bogo Sort (use only with very small arrays!)\n"
			<< "5) Merge Sort\n"
			<< "6) Quick Sort with Median\n"
			<< "7) Quick Sort\n"
			<< "Enter choice: ";
}

void printArray(int* arr, int size){
	//prints opening bracket
	std::cout<<"[";
	
	//prints first n-1 elements with comma following
	for(int i = 0;i<size-1;i++){
		std::cout<<arr[i];
		std::cout<<",";
	}
	//prints last element, no comma needed
	std::cout<<arr[size-1];
	//prints closing brackert
	std::cout<<"]\n";
}



int main(){
	
	//Local variables
	
	
	bool flag = false;
	
	
	while(!flag){
		
		//local variables
		int choice = 0;		
		std::string confirm = "";
		
		
		printMenu();
		std::cin>>choice;
		
		
		//run the individual tests
		if(choice > 0 && choice <=7){
			
			//local  variables
			int size = 0;
			int min = 0;
			int max = 0;
			double time = 0.0;
			std::string print = "";
			
			//creates an array with appropriate parameters
			std::cout<<"Input a size for the random array: ";
			std::cin>>size;
			
			std::cout<<"Input a lower bound on the range of random numbers: ";
			std::cin>>min;
			
			std::cout<<"Input an upper bound on the range of random numbers: ";
			std::cin>>max;
			
			int* arr = Sorts<int>::createTestArray(size,min,max);
			
			
			//prints unsorted array
			std::cout<<"Do you want to print the unsorted array? (y/n): ";
			std::cin>>print;
			
			if(print.compare("y") == 0){
				std::cout<<"Here is the unsorted array: \n";
				printArray(arr,size);
			}
			
			
			//performs sort depending on user preference
			switch(choice){
				
				case 1:
				
					std::cout<<"Sorting with bubble sort...\n";
					time = Sorts<int>::sortTimer(Sorts<int>::bubbleSort,arr,size);
				
				break;
				
				case 2:
				
					std::cout<<"Sorting with insertion sort...\n";
					time = Sorts<int>::sortTimer(Sorts<int>::insertionSort,arr,size);
					
				break;
				
				case 3:
				
					std::cout<<"Sorting with selection sort...\n";
					time = Sorts<int>::sortTimer(Sorts<int>::selectionSort,arr,size);
					
				break;
				
				case 4:
				
					std::cout<<"Sorting with bogo sort...\n";
					time = Sorts<int>::sortTimer(Sorts<int>::bogoSort,arr,size);
					
				break;
				
				case 5:
				
					std::cout<<"Sorting with merge sort...\n";
					time = Sorts<int>::sortTimer(Sorts<int>::mergeSort,arr,size);
					
				break;
				
				case 6:
				
					std::cout<<"Sorting with quicksort with median...\n";
					time = Sorts<int>::sortTimer(Sorts<int>::quickSortMedian,arr,size);
					
				break;
				
				case 7: 
				
					std::cout<<"Sorting with quicksort without median...\n";
					time = Sorts<int>::sortTimer(Sorts<int>::quickSort,arr,size);
				
				break;	
				
			}
			
			//prints now sorted array
			std::cout<<"Do you want to print the sorted array? (y/n): ";
			std::cin>>print;
			
			if(print.compare("y") == 0){
				std::cout<<"Here is the sorted array: \n";
				printArray(arr,size);
			}
			
			
			//prints sorted time
			std::cout<<size<<" numbers were sorted in "<<time<<" seconds.\n\n";
			
			
			//deallocates the array before it falls out of scope
			delete[] arr;
			arr = nullptr;
			
		}
		//invalid choice
		else{
			std::cout<<"Invalid choice.\n";
		}
		
		std::cout<<"\n\nDo you want to quit? (y/n): \n";
		std::cin>>confirm;
		
		if(confirm.compare("y") == 0){
			flag = true;
		}		
	}
	
	return 0;
}