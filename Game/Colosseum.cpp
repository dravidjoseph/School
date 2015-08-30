/*******************************************************
* @file: Colosseum.cpp
* @author: Dravid Joseph
* @date: 8/31/15
* @brief: Implementation file for Colosseum class
********************************************************/

#include "Colosseum.h"

Colosseum::Colosseum():d20(Dice(20)),d6(Dice(6)){
	
}

void Colosseum::userBuild(Pokemon& p){

      //name pokemon
	std::cout<<"Please name your Pokemon: ";
    std::string name = "";
    std::cin>>name;
      //check name
    while(!name.compare("")){
		
          std::cout<<"Your name must be at least one character long: ";
          std::cin>>name;
	}
    //sets name after check
    p.setName(name);

    //temp variable to hold integers
    int temp = 0;

      //hp
    std::cout<<"How many hit points will it have? (1-50): ";
    std::cin>>temp;
	//check hp
    while(temp<1 || temp>50){
          std::cout<<"Sorry.  The hit points must be between 1-50:";
          std::cin>>temp;
    }
	//sets hp after check
    p.setHP(temp);
    std::cout<<"Split 50 points between your attack and defense level\n";
	
    //attack level
    std::cout<<"Enter your attack level (1-49): ";
    std::cin>>temp;
	//checks attack level
    while(temp<1 || temp>49){
          std::cout<<"Sorry.  The attack level must be between 1-49:";
          std::cin>>temp;
    }
	//sets attack level after check
    p.setAttackLevel(temp);

    //defense level
    std::cout<<"Enter your defense level (1-"<<50-p.getAttackLevel()<<"): ";
    std::cin>>temp;
	
	//checks defense level
    while(temp<1 || temp>50-p.getAttackLevel()){
    	std::cout<<"Sorry.  The defense level must be between 1 and "<<50-p.getAttackLevel()<<": ";
		std::cin>>temp;
    }
	p.setDefenseLevel(temp);
}

//Attacks pokemon
bool Colosseum::attack(const Pokemon& attacker,Pokemon& defender){
	
	std::cout<<attacker.getName()+" is attacking "+defender.getName()+"\n";
    //sets up bonuses
    int attackBonus = d20.roll();
    int defenseBonus = d20.roll();

    //prints bonuses
    std::cout<<attacker.getName()+" rolls an attack bonus of "<<attackBonus<<"\n";
    std::cout<<defender.getName()+" rolls a defense bonus of "<<defenseBonus<<"\n";

    //if damage
    if(attacker.getAttackLevel()+attackBonus>defender.getDefenseLevel()+defenseBonus){
          std::cout<<"The attack hits dealing 3-D6 damage!\n";
          //Calculate damage
		  int roll1 = d6.roll();
          int roll2 = d6.roll();
          int roll3 = d6.roll();
          int damage = roll1+roll2+roll3;
          
		  std::cout<<"The rolls are "<<roll1<<", "<<roll2<<", and "<<roll3<< " totaling: "<<
          damage<<" damage!\n";
          
		  defender.reduceHP(damage);

    }
    //otherwise attack misses
    else{
          std::cout<<"The attack missed!\n";
    }
    //if defender dies
    if(defender.getHP()<=0){
          std::cout<<defender.getName()<<" has been defeated!\n";
          return true;
    }
    else{
          std::cout<<defender.getName()<<" has "<<defender.getHP()<<" hit points left\n";
          return false;
    }
}

//handles play
void Colosseum::play(Pokemon& p1, Pokemon& p2){
	
	std::cout<<"Choosing which player to go first: \n";
    Dice d2 = Dice(2);

	bool flag = false;		//terminates round early if necessary
	
    if(d2.roll() == 1){
          //p1 goes first
          std::cout<<"Player 1 will go first.";
          
    }
    else{
          std::cout<<"Player 2 will go first.";
    }
	
    for(int i = 1;i<=10 || flag;i++){
          
		std::cout<<"\n\nRound "<<i<<"!\n\n";
		
          flag = attack(p1,p2);
		if(flag){
			break;
		}
          flag = attack(p2,p1);      
    }
}
