/*******************************************************
* @file: Sorts.h
* @author: Dravid Joseph
* @date: 10/26/15
* @brief: Templated header for Sorts class
********************************************************/

#ifndef SORTS_H
#define SORTS_H

#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>

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
	* @pre :  Valid array, valid size, valid generator reference
	* @post : Shuffles array according to generator
	* @return : void
	********************************************************/
	
	static void shuffle(T arr[], int size,std::default_random_engine& generator);
	
	/*******************************************************
	* @pre :  Valid array, two valid indices
	* @post : swaps array at index points
	* @return : void
	********************************************************/
	
	static double sortTimer(std::function<void(T[],int)> sort,T arr[], int size);
	
	/*******************************************************
	* @pre :  Valid array, minimum and max values
	* @post : creates an array on heap of size
	* @return : int*
	********************************************************/
	
	static int* createTestArray(int size, int min, int max);
	
	
	/*******************************************************
	* @pre :  Valid array, two valid indices
	* @post : swaps array at index points
	* @return : void
	********************************************************/
	
	static void swap(T arr[],int firstIndex,int secondIndex);
	
	
};
#include "Sorts.hpp"
#endif