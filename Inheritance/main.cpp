/*******************************************************
* @file : main.cpp
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Driver for Inheritance program
********************************************************/

#include <iostream>
#include "AnimalPen.h"
#include "FarmAnimal.h"
#include "Stack.h"

/**
void goodbyeMessage(const FarmAnimal& animal){
	
	std::cout<<"Upon release the"<<animal.getName()<<" said "<<animal.getSound()<<".\n";
	
}
*/

void printMenu(){
	
	std::cout<<" Select an animal to add to the pen: \n";
	std::cout<<"1.) Cow (produces milk)\n";
	std::cout<<"Chicken (cannot lay eggs)\n";
	std::cout<<"CyberChicken (seems dangerous, but lays eggs)\n";
	std::cout<<"---------------------------------------------------\n";
}

int main(){
	
	printMenu();
/**	
	int choice = 0;
	bool flag = false;
	
	std::string done = "";
	
	double value = 0.0;
	int eggValue = 0;
	
	double totGallons = 0.0;
	int totEggs = 0;

	while(!flag){
	
		printMenu();
		std::cout<<"Choice: ";
		std::cin>>choice;
	
		if(choice == 1){
			std::cout<<"\nHow many gallons of milk did this cow produce?";
			std::cin>>value;
			totGallons += value;
		}
		else if(choice == 2){
			std::cout<<"\nAdd an eggless chicken to the pen? OK.  You're the boss." ;
			std::cin>>value;
		}
		else if (choice == 3){
			std::cout<<"How many eggs did this cyberchicken produce?";
		}
		else{
			std::cout<<"Invalid choice";
		}
		
		std::cout<<"Done adding animals? (y/n)";
		std::cin>>done;
		
		if(done == "y"){
			flag = true;
		}
	
	}	
*/
	
	return 0;	
}