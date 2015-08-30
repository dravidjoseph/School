/*******************************************************
* @file : main.cpp
* @author : Dravid Joseph
* @date : 7/20/2015
* @brief : Driver for Inheritance program
********************************************************/

#include <iostream>

//user-defined libraries
#include "Stack.h"
#include "Node.h"
#include "PreconditionViolationException.h"
#include "AnimalPen.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"


/*******************************************************
* @pre :  valid FarmAnimal reference (NOT pointer)
* @post : prints a message
* @return : void
********************************************************/


void goodByeMessage(const FarmAnimal& animal){
      std::cout<<"Upon release the "<<animal.getName()<<" said "<<animal.getSound()<<".\n";
}

/*******************************************************
* @pre : None
* @post : prints a menu
* @return : void
********************************************************/
void printMenu(){
	
    std::cout<<"Select an animal to add to the pen: \n";
    std::cout<<"1.) Cow (produces milk)\n";
    std::cout<<"2.) Chicken (cannot lay eggs)\n";
    std::cout<<"3.) Cyber Chicken (seems dangerous, but lays eggs)";
    std::cout<<"\n---------------------------------------------------\n";

    std::cout<<"choice: ";
	
}

/*******************************************************
* @pre :  None
* @post : Drives Inheritance program
* @return : int
********************************************************/
int main(){

     
	  //Pen
	  AnimalPen pen;
	  
	  //Pointers to different farm animals
      Cow* cow = nullptr;
	  Chicken* chicken = nullptr;
	  CyberChicken* cyber = nullptr;
      FarmAnimal* animal = nullptr;
	  
	  
	  //local variables needed for program
      bool flag = false;
      int choice = 0;
      double value = 0.0;
      double totalMilk = 0.0;
      double totalEggs = 0.0;
      std::string done = "";

      while(!flag){	
			
		 	printMenu();
			
			//user input
            std::cin>>choice;


			//selects cow
            if(choice == 1){
                  cow = new Cow();

                  std::cout<<"How many gallons of milk did this cow produce?: ";
                  std::cin>>value;
                  cow->setMilkProduced(value);
                  pen.addAnimal(cow);
                  totalMilk += value;

            }
            else if(choice == 2){
                  chicken = new Chicken();

                  std::cout<<"Add eggless chicken to the pen? OK. You're the boss.\n ";
                  pen.addAnimal(chicken);

            }
            else if(choice == 3){
                  cyber = new CyberChicken();

                  std::cout<<"How many eggs did this cyber chicken produce?: ";
                  std::cin>>value;
                  cyber->setCyberEggs(value);
                  pen.addAnimal(cyber);
                  totalEggs += value;

            }
            std::cout<<"Done adding animals? (y/n):";
            std::cin>>done;
            if(done == "y"){
                  flag = true;
            }
      }


	  //Release all animals

      std::cout<<"Releasing all animals!\n";
      std::cout<<"-------------------------\n";
	  
	  //Keep releasing until pen is empty
      while(!pen.isPenEmpty()){
		  	
			
		  //stores animal's name locally while minimizing function calls
            animal = pen.peekAtNextAnimal();
            done = animal->getName();
			
			
			//depending on animal, static_cast to child class in order to use appropriate methods

            if(done == "Cow"){
                  cow = static_cast<Cow*>(animal);
                  std::cout<<"This "<<done<<" produced "<<cow->getMilkProduced()<<" gallons of milk\n";

            }
            else if(done == "Chicken"){
                  chicken = static_cast<Chicken*>(animal);
                  std::cout<<"Chicken unable to lay eggs.  Perhaps Cybornetic implants will help?\n";
            }
            else{
                  cyber = static_cast<CyberChicken*>(animal);
                  std::cout<<"This "<<done<<" produced "<<cyber->getCyberEggs()<<" eggs\n";
            }
			
			//deference in order to use goodByeMessage
            goodByeMessage(*pen.peekAtNextAnimal());
            std::cout<<done<< " destructor called.\n";
            pen.releaseAnimal();
      }


      std::cout<<"Your farm produced "<<totalMilk<<" gallons of milk and "<<totalEggs<<" eggs.\n";
	  
	  delete cow;
	  delete chicken;
	  delete cyber;
	  delete animal;
	  cow = nullptr;
	  chicken = nullptr;
	  cyber = nullptr;
	  animal = nullptr;


return 0;


}