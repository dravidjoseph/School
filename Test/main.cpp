/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 9/4/16
* @brief: Driver file for Linked List
********************************************************/

#include <iostream>
#include <fstream>

#include "LinkedList.h"

/*******************************************************
* @pre :  None
* @post : Prints Menu for User to interact
* @return : void
********************************************************/
void printMenu(){
	
	std::cout<<"Please choose one of the following commands: \n";
	std::cout<<"1. Insert\n";
	std::cout<<"2. Delete\n";
	std::cout<<"3. Reverse\n";
	std::cout<<"4. Concatenate\n";
	std::cout<<"5. Print\n";
	std::cout<<"6. Exit\n\n";
	std::cout<<">";
	
	
}


/*******************************************************
* @pre :  None
* @post : builds initial list for user to interact with
* @return : LinkedList pointer
********************************************************/
LinkedList<int>* build(int data){
	
	//List to be created
	LinkedList<int>* ll = new LinkedList<int>();
	
	//Open a file object
	std::ifstream input;
	//
	if(data == 1){
		input.open("data.txt");
	}
	else{
		input.open("data2.txt");
	}
	
	int value;
	
	//Read file and insert value into linked list using insert method
	while(input >> value){
		ll->insert(value);
	}
	//close file
	input.close();
	
	//return list
	return ll;
	
}


/*******************************************************
* @pre :  None
* @post : Driver of program
* @return : int, but really end of program
********************************************************/
int main(){
	
	//List
	LinkedList<int>* ll = build(1);
	LinkedList<int>* l2 = build(2);
	
	//flag for program loop
	bool flag = false;
	//user choice
	int choice = 0;
	//value to be inserted
	int val = 0;
	
	
	//run program
	while(!flag){
		//print menu
		printMenu();
		//take user input
		std::cin>>choice;
		
		//insert, print, or signal exit
		switch(choice){
			//insert
			case 1:
				std::cout<<"Choose a number to be inserted into the list: \n";
				std::cin>>val;
				ll->insert(val);
			
			break;
			//delete
			case 2:
				std::cout<<"Choose a number to be deleted from the list: \n";
				std::cin>>val;
				std::cout<<ll->erase(val);
			break;
			//reverse
			case 3: 
				std::cout<<"Reversing the list...\n";
				ll->reverse();
			break;
			//concatenate
			case 4:
					std::cout<<"Concatenating...";
					ll->concatenate(l2);
			break;
			//print
			case 5:
			
				std::cout<<"List: ";
				ll->print();
			
			break;
			//exit
			case 6:
			
				flag = true;
			
			break;
			//other choices
			default:
				std::cout<<"Sorry, not a valid choice.\n";
			
			break;
			
		}
		
		std::cout<<"..................................\n";
	}
	
	//call destructor-otherwise memory leaks
	delete ll;
	delete l2;
	ll = nullptr;
	l2 = nullptr;
	
	return 0;
}