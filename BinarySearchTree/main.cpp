/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 8/5/15
* @brief: Driver for Binary Search Tree Class
********************************************************/


#include <iostream>
#include <climits>
#include <random>
#include <ctime>

#include "BSTI.h"
#include "BinarySearchTree.h"
#include "ValueNotFoundException.h"

void printMenu(){
	
	std::cout<<"\n\nInput a selection\n";
	std::cout<<"1) Add more values to original tree\n";
	std::cout<<"2) Copy the original tree\n";
	std::cout<<"3) Delete the original tree (one time only)\n";
	std::cout<<"4) Print original tree\n";
	std::cout<<"5) Print copy\n";
	std::cout<<"6) Search original tree\n";
	std::cout<<"7) Search copy\n";
	std::cout<<"8) Exit\n";
	std::cout<<"Your choice: ";
	
	
	
}

int main(int argc, char** argv){
	
	/*******************************************************
	* Local Primitive Variable Declaration
	********************************************************/
	int numNodes = atoi(argv[1]);
	int randomNumber = 0;
	int choice = 0;
	int choice2 = 0;
	int value = 0;
	
	
	bool flag = false;
	
	/*******************************************************
	* Tree Declarations
	********************************************************/
	BinarySearchTree<int>* original = new BinarySearchTree<int>();
	BinarySearchTree<int>* copy = nullptr;
	
	/*******************************************************
	* Random Number Declarations
	********************************************************/
	
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(INT_MIN,INT_MAX);
	
	
	/*******************************************************
	* INITIAL TREE POPULATION
	********************************************************/
	
	if(argc != 2){
		std::cout<<"Invalid number of arguments.  Program terminated.\n";
		return 0;
	}
	
	if(numNodes < 0){
		std::cout<<"Cannot make a tree with negative number of nodes.\n ";
		return 0;
	}
	
	std::cout<<"Filling original tree with "<<numNodes<<" values.\n";
	
	for(int i = 0;i < numNodes;i++){
		
		randomNumber = distribution(generator);
		if(original->add(randomNumber)){
			std::cout<<"Adding "<<randomNumber<<" to original tree.\n";
		}
		
	}
	
	/*******************************************************
	* TREE MODIFICATION
	********************************************************/
	while(!flag){
		
		printMenu();
		std::cin>>choice;
		
		std::cout<<"You chose: "<<choice<<"\n";
		
		if(choice == 1){
			std::cout<<"Input a value to add to the original: ";
			std::cin>>value;
			
			if(original->add(value)){
				std::cout<<"Adding "<<value<<" to the original tree.\n";
			}
			else{
				std::cout<<"Could not add value to the original tree.\n";
			}
		}
		else if(choice == 2){
			
			copy = new BinarySearchTree<int>(*original);
			std::cout<<"Original tree copied.\n";
			
		}
		else if(choice == 3){
			
			delete original;
			original = nullptr;
			
			std::cout<<"Original Tree deleted.\n";
			
		}
		else if(choice == 4){
			
			if(original == nullptr){
				std::cout<<"Original Tree no longer exists.  Cannot print.\n";
			}
			else{
				std::cout<<"Print order options: \n";
				std::cout<<"\t0 - pre-order\n";
				std::cout<<"\t1 - in-order\n";
				std::cout<<"\t2 - post-order\n";
			
				std::cin>>choice2;
			
				if(choice2 == 0){
					original->printTree(PRE_ORDER);
				}
				else if(choice2 == 1){
					original->sortedPrint();
				}
				else if(choice2 == 2){
					original->printTree(POST_ORDER);
				}
				else{
					std::cout<<"Not a valid option, sorry.\n";
				}
			}
			
		}
		else if(choice == 5){
			
			if(copy == nullptr){
				std::cout<<"Tree does not exist. Cannot print.\n";
			}
			else{
				std::cout<<"Print order options: ";
				std::cout<<"\t0 - pre-order\n";
				std::cout<<"\t1 - in-order\n";
				std::cout<<"\t2 - post-order\n";
			
				std::cin>>choice2;
			
				if(choice2 == 0){
					copy->printTree(PRE_ORDER);
				}
				else if(choice2 == 1){
					copy->sortedPrint();
				}
				else if(choice2 == 2){
					copy->printTree(POST_ORDER);
				}
				else{
					std::cout<<"Not a valid option, sorry.\n";
				}
			}
		}
		else if(choice == 6){
			
			if(original == nullptr){
				std::cout<<"Tree does not exist.  Cannot print.\n";
			}
			else{
			
				std::cout<<"Choose a value you wish to search for: \n";
				std::cin>>choice2;
			
				try{
					value = original->search(choice2);
					std::cout<<value<<" is in the list.\n";
				}
				catch(ValueNotFoundException& e){
					std::cout<<e.what();
				}
			}
			
		}
		else if(choice == 7){
			
			if(copy == nullptr){
				std::cout<<"Tree does not exist.  Cannot print.\n";
			}
			else{
				std::cout<<"Choose a value you wish to search for: \n";
				std::cin>>choice2;
			
				if(copy == nullptr){
					std::cout<<"This tree doesn't exist.  Cannot print.\n";
				}
				else{
					try{
						value = copy->search(choice2);
						std::cout<<value<<" is in the list.\n";
					}
					catch(ValueNotFoundException& e){
						std::cout<<e.what();
					}
				}
			}
		}
		else if(choice == 8){
			flag = true;
		}
		else{
			std::cout<<"Invalid choice.\n";
		}	
	}
	std::cout<<"Exiting...";
	
	if(original != nullptr){
		delete original;
		original = nullptr;
	}
	
	
	delete copy;
	copy = nullptr;
	

	return 0;

}