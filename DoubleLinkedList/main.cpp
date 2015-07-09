/*******************************************************
* @file: Node.h
* @author: Dravid Joseph
* @date: 6/30/15
* @brief: Driver for DoubleLinkedList implementation
********************************************************/

#include <iostream>
#include <stdexcept>

#include "DoubleLinkedList.h"

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove value\n"
		<<	"6) print list\n"
		<<	"7) Quit\n"
		<< 	"Your choice: ";
}



int main(){
	
	DoubleLinkedList<int>* dll = new DoubleLinkedList<int>();
	bool flag = false;
	int choice = 0;
	int value = 0;
	int search = 0;
	
	while(!flag){
		
		printMenu();
		std::cin>>choice;
		
		std::cout<<"\nYou chose: "<<choice<<"\n";
		
		if(choice == 1){
			std::cout<<"Give a value: ";
			std::cin>>value;
			
			dll->pushFront(value);
			
			std::cout<<value<<" added to the front of list.";
		}
		else if(choice == 2){
			std::cout<<"Give a value: ";
			std::cin>>value;
			
			dll->pushBack(value);
			
			std::cout<<value<<" added to the front of list.";
		}
		else if(choice == 3){
			std::cout<<"Give a value to insert: ";
			std::cin>>value;
			
			std::cout<<"Pick a value to insert behind: ";
			std::cin>>search;
			
			std::cout<<"Attempting to insert "<<value<<" behind "<<search<<"\n";
			
			try{
				dll->insertBehind(search,value);
			}
			catch(std::runtime_error& e){
				std::cout<<e.what()<<std::endl;
			}
				
		}
		else if(choice == 4){
			std::cout<<"Give a value to insert: ";
			std::cin>>value;
			
			std::cout<<"Pick a value to insert ahead of: ";
			std::cin>>search;
			
			std::cout<<"Attempting to insert "<<value<<" ahead of "<<search<<"\n";
			
			try{
				dll->insertAhead(search,value);
			}
			catch(std::runtime_error& e){
				std::cout<<e.what()<<std::endl;
			}
		}
		else if(choice == 5){
			std::cout<<"Give a value to remove: ";
			std::cin>>value;
			std::cout<<"You gave "<<value<<"\n";
			
			if(dll->remove(value)){
				std::cout<<value<<" removed from list.";
			}
			else{
				std::cout<<value<<" could not be removed from list.";
			}
		}
		else if(choice == 6){
			dll->printList();
		}
		else if(choice == 7){
			std::cout<<"Program ending...";
			flag = true;
		}
		else{
			std::cout<<"Invalid choice.\n";
		}
	}
	
	
	
}