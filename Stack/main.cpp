/*******************************************************
* @file : main.cpp
* @author : Dravid Joseph
* @date : 9/28/15
* @brief : Driver class for stack project
********************************************************/

#include "Stack.h"
#include "Test.h"

/*******************************************************
* @pre :  None
* @post : Prints a menu of options
* @return : void
********************************************************/

void printMenu(){
	
	std::cout << 	"\n\nSelect an action: \n"
			<<	"1) Add something to stack\n"
			<<	"2) See what is at the top of stack\n"
			<<	"3) Print contents in stack\n"
			<<	"4) Pop stack\n"
			<<	"5) Quit\n"
			<<	"6) Run tests\n"
			<< 	"Enter choice: ";
}

/*******************************************************
* @pre :  None
* @post : Driver method for program
* @return : int
********************************************************/

int main(){
	
	
	//Two StackInterface objects.
	//Remember, parent pointers can take child objects.
	StackInterface<int>* lane1 = new Stack<int>();
	
	//Helper variables for main
	int choice = 0;
	int entry = 0;
	bool flag = false;
	
	while(!flag){
		
		printMenu();
		
		std::cin>>choice;
		std::cout<<"You chose: "<<choice<<"\n";
		
		
		if(choice == 1){
			
			std::cout<<"Add integer to stack: \n";
			std::cin>>entry;
			lane1->push(entry);
			std::cout<<entry<<" successfully added to stack.";
		}
		else if(choice == 2){
			
			std::cout<<"What is going on top of the stack?\n";
		
			try{
				entry = lane1->peek();
			}
			catch(PreconditionViolationException& e){
				std::cout<<e.what()<<std::endl;
			}
			
		}
		else if(choice == 3){
			lane1->print();
		}
		else if(choice == 4){
			try{
				lane1->pop();
			}
			catch(PreconditionViolationException& e){
				std::cout<<e.what()<<std::endl;
			}
		}	
		else if(choice == 5){
			std::cout<<"Quitting...\n";
			flag = true;
		}
		else if(choice == 6){
			Test myTest(std::cout);
			myTest.runTests();
		}	
		else{
			std::cout<<"Invalid choice.\n";
		}
		
	}
	
	delete lane1;
	lane1 = nullptr;
	
	return 0;
	
}