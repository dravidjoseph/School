/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 9/14/15
* @brief: Driver for LinkedList Program
********************************************************/

#include "LinkedList.h"
#include "Test.h"

#include <iostream>



/*******************************************************
* @pre :  None
* @post : Prints Menu (does not do anything else)
* @return : void
********************************************************/

void printMenu(){
	std::cout << "\n\nSelect from the following menu:\n"
			<< "1) Add to the front of the list\n"
			<< "2) Add to the end of the list\n"
			<< "3) Remove from front of the list\n"
			<< "4) Remove from back of the list\n"
			<< "5) Print the list\n"
			<< "6) Search for value\n"
			<< "7) Exit\n"
			<< "8) Run tests\n"
			<< "9) Reverse the list\n"
			<< "Enter your choice: ";
}

int main(){
	
	//local variables needed to run program
	bool flag = false;
	int choice = 0;
	int val = 0;
	
	//Pointer to list
	LinkedList* list = new LinkedList();
	
	//allows for repetition
	while(!flag){
		
		//initial user input
		printMenu();
		std::cin>>choice;
		std::cout<<"You chose: "<<choice;
		
		//Add to front of list
		if(choice == 1){
			std::cout<<"\nInput a value to add: ";
			std::cin>>val;
			
			std::cout<<"\nAdding "<<val<<" to the front of list.\n";
			
			list->addFront(val);
			
		}
		//Add to back of list
		else if(choice == 2){
			std::cout<<"\nInput a value to add: \n";
			std::cin>>val;
			
			std::cout<<"\nAdding "<<val<<" to the back of list.\n";
			
			list->addBack(val);
		}
		//Remove from front of list
		else if(choice == 3){
			std::cout<<"\nAttempting removal from front of list.\n";
			if(list->removeFront()){
				std::cout<<"Removal successful\n";
			}
			else{
				std::cout<<"Removal failed\n";
			}
		}
		//Remove from back of list
		else if(choice == 4){
			std::cout<<"\nAttempting removal from back of list.\n";
			if(list->removeBack()){
				std::cout<<"Removal successful\n";
			}
			else{
				std::cout<<"Removal failed\n";
			}
		}
		//Print list
		else if(choice == 5){
			std::cout<<"\nPrinting list:";
			list->printList();
		}
		//Searches list for value
		else if(choice == 6){
			std::cout<<"\nEnter a value to search for: \n";
			std::cin>>val;
			if(list->search(val)){
				std::cout<<val<<" is in the list\n";
			}
			else{
				std::cout<<val<<" is not in the list\n";
			}
		}
		//Exits
		else if(choice == 7){
			std::cout<<"\nExiting...\n";
			flag = true;
		}
		//Runs tests
		else if(choice == 8){
			Test testers(std::cout);	//declares test instance
			testers.runTests();
		}
		else if(choice == 9){
			list->reverse();
		}
		
		else{
			std::cout<<"\nInvalid choice.\n";
		}	
		
	}
	
	delete list;
	list = nullptr;

}