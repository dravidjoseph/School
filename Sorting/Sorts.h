/*******************************************************
* @file: Sorts.h
* @author: Dravid Joseph
* @date: 7/20/15
* @brief: Templated header for Sorts class
********************************************************/

#ifndef SORTS_H
#define SORTS_H

#include <random>
#include <ctime>
#include <cassert>

template<typename T>
class Sorts{
	
	/*******************************************************
	* PUBLIC METHDOS
	********************************************************/
	
public:
	
	/*******************************************************
	* @pre :  Valid array, valid size
	* @post : Sorts array using bubbleSort
	* @return : void
	********************************************************/
	
	static void bubbleSort(T arr[], int size);
	
	/*******************************************************
	* @pre :  Valid array, valid size
	* @post : Sorts array using bogoSort
	* @return : void
	********************************************************/
	
	static void bogoSort(T arr[], int size);
	
	/*******************************************************
	* @pre :  Valid array, valid size
	* @post : Sorts array using insertionSort
	* @return : void
	********************************************************/
	
	static void insertionSort(T arr[], int size);
	
	/*******************************************************
	* @pre :  Valid array, valid size
	* @post : Sorts array using selectionSort
	* @return : void
	********************************************************/
	
	static void selectionSort(T arr[], int size);
	
	/*******************************************************
	* @pre :  Valid array, valid size
	* @post : Returns true if sorted, false if not
	* @return : bool
	********************************************************/
	
	static bool isSorted(T arr[], int size);
	
	/*******************************************************
	* PRIVATE METHDOS
	********************************************************/
	
	/*******************************************************
	* @pre :  Valid array, valid size, valid generator reference
	* @post : Shuffles array according to generator
	* @return : void
	********************************************************/
	
	static void shuffle(T arr[], int size,std::default_random_engine& generator);
	
};
#include "Sorts.hpp"
#endif