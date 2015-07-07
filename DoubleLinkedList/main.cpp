/*******************************************************
* @file: Node.h
* @author: Dravid Joseph
* @date: 6/30/15
* @brief: Driver for DoubleLinkedList implementation
********************************************************/

#include <iostream>

#include "DoubleLinkedList.h"

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove value\n"
		<<	"6) print list\n"
		<<	"7) Quit\n"
		<< 	"Your choice: ";
}



int main(){
	
	DoubleLinkedList<int>* dll = new DoubleLinkedList<int>();
	
	dll->pushFront(15);
	dll->printList();
	
	
}