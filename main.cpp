/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 6/28/15
* @brief: Implementation file for LinkedList.h
********************************************************/

#include "LinkedList.h"
#include <iostream>

void printMenu(){
	std::cout << "\n\nSelect from the following menu:\n"
			<< "1) Add to the front of the list\n"
			<< "2) Add to the end of the list\n"
			<< "3) Remove from front of the list\n"
			<< "4) Remove from back of the list\n"
			<< "5) Print the list\n"
			<< "6) Search for value\n"
			<< "7) Exit\n"
			<< "Enter your choice: ";
}

int main(){
	
	bool flag = false;
	int choice = 0;
	int val = 0;
	LinkedList* list = new LinkedList();

	while(!flag){
		
		printMenu();
		std::cin>>choice;
		std::cout<<"You chose: "<<choice;
		
		if(choice == 1){
			std::cout<<"Input a value to add: ";
			std::cin>>val;
			
			std::cout<<"Adding "<<val<<" to the front of list.";
			
			list->addFront(val);
			
		}
		else if(choice == 2){
			std::cout<<"Input a value to add: ";
			std::cin>>val;
			
			std::cout<<"Adding "<<val<<" to the back of list.";
			
			list->addBack(val);
		}
		else if(choice == 3){
			std::cout<<"Attempting removal from front of list.\n";
			if(list->removeFront()){
				std::cout<<"Removal successful\n";
			}
			else{
				std::cout<<"Removal failed\n";
			}
		}
		else if(choice == 4){
			std::cout<<"Attempting removal from back of list.\n";
			if(list->removeBack()){
				std::cout<<"Removal successful\n";
			}
			else{
				std::cout<<"Removal failed\n";
			}
		}
		else if(choice == 5){
			std::cout<<"Printing list:";
			list->printList();
		}
		else if(choice == 6){
			std::cout<<"Enter a value to search for: ";
			std::cin>>val;
			if(list->search(val)){
				std::cout<<val<<" is in the list";
			}
			else{
				std::cout<<val<<" is not in the list";
			}
		}
		else if(choice == 7){
			std::cout<<"Exiting...";
			flag = true;
		}
		else{
			std::cout<<"Invalid choice.\n";
		}	
		
	}

}