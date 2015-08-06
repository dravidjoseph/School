/*******************************************************
* @file: main.cpp
* @author: Dravid Joseph
* @date: 8/5/15
* @brief: Driver for Binary Search Tree Class
********************************************************/


#include <iostream>
#include <climits>
#include <random>
#include <ctime>

void printMenu(){
	
	std::cout<<"Input a selection\n";
	std::cout<<"1) Add more values to original tree\n";
	std::cout<<"2) Copy the original tree\n";
	std::cout<<"3) Delete the original tree (one time only)\n";
	std::cout<<"4) Print original tree\n";
	std::cout<<"5) Print copy\n";
	std::cout<<"6) Search original tree\n";
	std::cout<<"7) Search copy\n";
	std::cout<<"8) Exit\n";
	std::cout<<"Your choice: "
	
	
	
}

int main(int argc, char** argv){
	
	
	
	std::string nodes = argv[1];
	int numNodes = atoi(nodes.cstr());
	
	std::cout<<"Arg count: "<<argc;
	std::cout<<"\nNode count: "<<numNodes;
	
	std::cout<<"Filling tree with "<<numNodes<<" values";
	
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(INT_MIN,INT_MAX);
	
	BinarySearchTree<int>* myBST = new BinarySearchTree<int>();
		
	
	for(int i = 0;i<numNodes;i++){
		
		int random = distribution(generator);
		std::cout<<"Adding "<<random<<" to original tree";
		
		
	}
	
	
	






}