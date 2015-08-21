/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 8/21/15
* @brief: Driver class for main program
********************************************************/


#include <iostream>

#include "Pokemon.h"
#include "Colosseum.h"

int main(){
      //Declaration of stack-allocated Pokemon instances
      Pokemon p1 = Pokemon();
      Pokemon p2 = Pokemon();

      //declaration of stack-allocated Colosseum instance
      Colosseum arena = Colosseum();

      //signal user to build pokemon
      std::cout<<"Player 1, build your Pokemon!\n";
      std::cout<<"=====================\n";

      //Use Colosseum instance to build Pokemon
      arena.userBuild(p1);

      std::cout<<"Player 2, build your Pokemon!\n";
      std::cout<<"=====================\n";

      //Use Colosseum instance to build Player 2's pokemon
      arena.userBuild(p2);

      //start and run an entire round until complete
      arena.play(p1,p2);

      //determine whether the user still wants to play
      std::string flag = "";

      std::cout<<"Do you want to play again? (y/n): ";
      //store user input
      std::cin>>flag;

      //runs for as many games as the user chooses.
      while(!flag.compare("y")){
            std::cout<<"Player 1, build your Pokemon!\n";
            std::cout<<"=================\n";
            arena.userBuild(p1);

            std::cout<<"Player 2, build your Pokemon!\n";
            std::cout<<"=================\n";
            arena.userBuild(p2);

            arena.play(p1,p2);
            std::cout<<"Do you want to play again? (y/n): ";
            std::cin>>flag;
      }

      //runs after games are over.
      std::cout<<"\nThanks for playing!\n\n";

      return 0;
}