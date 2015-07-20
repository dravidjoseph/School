/*******************************************************
* @file : main.cpp
* @author : Dravid Joseph
* @date : 7/12/2015
* @brief : Driver for Inheritance program
********************************************************/

#include <iostream>
#include "Stack.h"
#include "Node.h"
#include "PreconditionViolationException.h"
#include "AnimalPen.h"
#include "Cow.h"
#include "Chicken.h"
#include "CyberChicken.h"



void goodByeMessage(const FarmAnimal& animal){
      std::cout<<"Upon release the "<<animal.getName()<<" said "<<animal.getSound()<<".\n";
}


int main(){

      AnimalPen pen;


      bool flag = false;
      int choice = 0;
      double value = 0.0;
      double totalMilk = 0.0;
      double totalEggs = 0.0;
      std::string done = "";
      Cow* cow = nullptr;
      Chicken* chicken = nullptr;
      CyberChicken* cyber = nullptr;
      FarmAnimal *animal = nullptr;

      while(!flag){
            std::cout<<"Select an animal to add to the pen: \n";
            std::cout<<"1.) Cow (produces milk)\n";
            std::cout<<"2.) Chicken (cannot lay eggs)\n";
            std::cout<<"3.) Cyber Chicken (seems dangerous, but lays eggs)";
            std::cout<<"\n---------------------------------------------------\n";

            std::cout<<"choice: ";
            std::cin>>choice;

            if(choice == 1){
                  cow = new Cow();

                  std::cout<<"How many gallons of milk did this cow produce?: ";
                  std::cin>>value;
                  cow->setMilkProduced(value);
                  pen.addAnimal(cow);
                  totalMilk = totalMilk + value;

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
                  totalEggs = totalEggs + value;

            }
            std::cout<<"Done adding animals? (y/n):";
            std::cin>>done;
            if(done == "y"){
                  flag = true;
            }



      }

      std::cout<<"Releasing all animals!\n";
      std::cout<<"-------------------------\n";
      while(!pen.isPenEmpty()){

            animal = pen.peekAtNextAnimal();
            done = animal->getName();


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

            goodByeMessage(*pen.peekAtNextAnimal());
            std::cout<<done<< " destructor called.\n";
            pen.releaseAnimal();
      }


      std::cout<<"Your farm produced "<<totalMilk<<" gallons of milk and "<<totalEggs<<" eggs.\n";


return 0;


}