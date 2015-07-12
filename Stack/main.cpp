/*******************************************************
* @file : main.cpp
* @author : Dravid Joseph
* @date : 7/9/2015
* @brief : Driver class for stack project
********************************************************/

#include "Stack.h"


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

int main(){
	
	StackInterface<std::string>* lane1 = new Stack<std::string>();
	StackInterface<std::string>* lane2 = new Stack<std::string>();
	
	int choice = 0;
	std::string entry = "";
	bool flag = false;
	
	while(!flag){
		
		printMenu();
		
		std::cin>>choice;
		std::cout<<"You chose: "<<choice<<"\n";
		
		if(choice == 1){
			
			std::cout<<"\nWhat is going on in stack 1?: ";
			
			std::cin>>entry;
		
			lane1->push(entry);
			
			std::cout<<""<<entry<<" successfully added to stack 1";
		}
		else if(choice == 2){
			
			std::cout<<"What is going on in stack 2?: ";
			
			std::cin>>entry;
			
			lane2->push(entry);
			
			std::cout<<"\n"<<entry<<" successfully added to stack 2";
			
		}
		else if(choice == 3){
			std::cout<<"What is at the top of stack 1?: ";
		
			std::cout<<lane1->peek();
			
		}
		else if(choice == 4){
			
			std::cout<<"\nWhat is at the top of stack 2?: ";
		
			std::cout<<lane2->peek();
			
		}
		else if(choice == 5){
			lane1->print();
		}
		else if(choice == 6){
			lane2->print();
		}
		else if(choice == 7){
			std::cout<<lane2->pop()<< "removed from stack 1";
			
		}
		else if(choice == 8){
			std::cout<<lane2->pop()<< "removed from stack 2";
		}
		else if(choice == 9){
			compareStacks(*lane1,*lane2);
		}
		else if(choice == 10){
			std::cout<<"Program ending";
			flag = true;
		}
		else{
			std::cout<<"Invalid choice.\n";
		}
		
		
		
		
		
		
		
		
		
	}
	
	return 0;
	
}