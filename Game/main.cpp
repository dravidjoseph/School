/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 8/31/15
* @brief: Driver class for main program
********************************************************/

#include <iostream>

#include "Pokemon.h"
#include "Colosseum.h"

//local helper method to eliminate some redundancy
void build(Pokemon& p1,Pokemon& p2,Colosseum& arena){
	
    //signal user to build pokemon
	std::cout<<"Player 1, build your Pokemon!\n";
    std::cout<<"=====================\n";

    //Use Colosseum instance to build Pokemon
    arena.userBuild(p1);

    std::cout<<"Player 2, build your Pokemon!\n";
    std::cout<<"=====================\n";

    //Use Colosseum instance to build Player 2's pokemon
    arena.userBuild(p2);
	
}
//runs game
void run(Pokemon& p1,Pokemon& p2,Colosseum& arena){
	
    //determine whether the user still wants to play
    std::string flag = "y";
 
	while(flag.compare("y")){
		  
		build(p1,p2,arena);

    	//start and run an entire round until complete
		arena.play(p1,p2);
		  
      	std::cout<<"Do you want to play again? (y/n): ";
      	//store user input
      	std::cin>>flag;
	
	}	
    //runs after games are over.
    std::cout<<"\nThanks for playing!\n\n";
	
}

int main(){
	
    //Declaration of stack-allocated Pokemon instances
    Pokemon p1 = Pokemon();
    Pokemon p2 = Pokemon();

    //declaration of stack-allocated Colosseum instance
    Colosseum arena = Colosseum();
	
	run(p1,p2,arena);
	
    return 0;
}