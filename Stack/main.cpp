/*******************************************************
* @file : main.cpp
* @author : Dravid Joseph
* @date : 9/28/15
* @brief : Driver class for stack project
********************************************************/

#include "Stack.h"

/*******************************************************
* @pre :  None
* @post : Prints a menu of options
* @return : void
********************************************************/

void printMenu(){
	
	std::cout << 	"\n\nSelect an option\n"
			<<	"1) Add something to stack 1\n"
			<<	"2) Add something to stack 2\n"
			<<	"3) See what is at the top of stack 1\n"
			<<	"4) See what is at the top of stack 2\n"
			<<	"5) Print contents in stack 1\n"
			<<	"6) Print contents in stack 2\n"
			<<	"7) Pop stack 1\n"
			<<	"8) Pop stack 2\n"
			<<	"9) Compare stacks\n"
			<<	"10) Quit\n"
			<< 	"Enter choice: ";
}

/*******************************************************
* @pre :  two valid StackInterface references
* @post : Tests operator overloading
* @return : void
********************************************************/


template <typename T>
void compareStacks(const StackInterface<T>& s1, const StackInterface<T>& s2)
{
	std::cout 	<< "\nComparison of stacks:\n"
			<< "lane 1 < lane 2: " <<  (s1 <  s2) 	<< "\n"
			<< "lane 1 > lane 2: " <<  (s1 >  s2) 	<< "\n"
			<< "lane 1 >= lane 2: " << (s1 >= s2) 	<< "\n"
			<< "lane 1 <= lane 2: " << (s1 <= s2) 	<< "\n"
			<< "lane 1 == lane 2: " << (s1 == s2) 	<< "\n"
			<< "lane 1 != lane 2: " << (s1 != s2) 	<< "\n";
}


/*******************************************************
* @pre :  None
* @post : Driver method for program
* @return : int
********************************************************/

int main(){
	
	
	//Two StackInterface objects.
	//Remember, parent pointers can take child objects.
	StackInterface<std::string>* lane1 = new Stack<std::string>();
	StackInterface<std::string>* lane2 = new Stack<std::string>();
	
	//Helper variables for main
	int choice = 0;
	std::string entry = "";
	bool flag = false;
	
	while(!flag){
		
		printMenu();
		
		std::cin>>choice;
		std::cout<<"You chose: "<<choice<<"\n";
		
		
		//push to stack 1
		if(choice == 1){
			
			std::cout<<"\nWhat is going on in stack 1?: \n";
			
			std::cin>>entry;
		
			lane1->push(entry);
			
			std::cout<<""<<entry<<" successfully added to stack 1";
		}
		//push to stack 2
		else if(choice == 2){
			
			std::cout<<"What is going on in stack 2?: ";
			
			std::cin>>entry;
			
			lane2->push(entry);
			
			std::cout<<"\n"<<entry<<" successfully added to stack 2";
			
		}
		//peek stack 1, with exception handling
		else if(choice == 3){
			std::cout<<"What is at the top of stack 1?: ";
			try{
				std::cout<<lane1->peek();
			}
			catch(std::runtime_error& e){
				std::cout<<e.what()<<std::endl;
			}
			
		}
		//peek stack 2, with exception handling
		else if(choice == 4){
			
			std::cout<<"\nWhat is at the top of stack 2?: ";
		
			try{
				std::cout<<lane2->peek();
			}
			catch(std::runtime_error& e){
				std::cout<<e.what()<<std::endl;
			}
			
			
		}
		//print stack 1
		else if(choice == 5){
			lane1->print();
		}
		//print stack 2
		else if(choice == 6){
			lane2->print();
		}
		
		//remove from stack 1, with exception handling
		else if(choice == 7){
			
			try{
				std::cout<<lane1->pop()<< " removed from stack 1";
			}
			catch(std::runtime_error& e){
				std::cout<<e.what()<<std::endl;
			}
			
		}
		//remove from stack 2, with exception handling
		else if(choice == 8){
			
			try{
				std::cout<<lane2->pop()<< " removed from stack 2";
			}
			catch(std::runtime_error& e){
				std::cout<<e.what()<<std::endl;
			}
			
		}
		//calls compareStacks references, uses dereferenced pointers
		else if(choice == 9){
			compareStacks(*lane1,*lane2);
		}
		
		//ends program
		else if(choice == 10){
			std::cout<<"Program ending";
			flag = true;
		}
		//last case to handle
		else{
			std::cout<<"Invalid choice.\n";
		}	
		
	}
	
	delete lane1;
	delete lane2;
	lane1 = nullptr;
	lane2 = nullptr;
	
	return 0;
	
}