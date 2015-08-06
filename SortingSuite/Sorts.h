/*******************************************************
* @file: Sorts.h
* @author: Dravid Joseph
* @date: 8/5/15
* @brief: Templated header for Sorts class
********************************************************/

#ifndef SORTS_H
#define SORTS_H

#include <random>
#include <ctime>
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
	* @post : Sorts array using quickSort, without median pivot
	* @return : void
	********************************************************/
	
	static void quickSort(T arr[], int size);
	
	/*******************************************************
	* @pre :  Valid array, valid size
	* @post : Sorts array using quickSort, with a median pivot
	* @return : void
	********************************************************/
	
	static void quickSortMedian(T arr[], int size);
	
	
	/*******************************************************
	* @pre :  Valid array, valid size
	* @post : Sorts array using mergeSort
	* @return : void
	********************************************************/
	
	static void mergeSort(T arr[], int size);
	
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
	* @pre :  Valid array, valid size,valid function
	* @post : Times each sort
	* @return : double
	********************************************************/
	
	static double sortTimer(std::function<void(T[],int)>,T arr[], int size);
	
	
	/*******************************************************
	* PRIVATE METHDOS
	********************************************************/
private:	
	
	/*******************************************************
	* @pre :  Valid array, two valid indices
	* @post : swaps array at index points
	* @return : void
	********************************************************/
	
	static void swap(T arr[],int firstIndex,int secondIndex);
	
	/*******************************************************
	* @pre :  Valid array pointers, two valid indices
	* @post : combines two arrays using mergeSort
	* @return : void
	********************************************************/
	
	static void merge(T* a1, T* a2, int size1, int size2);
	
	/*******************************************************
	* @pre :  Valid array, two valid indices
	* @post : sorts array by partitioning array
	* @return : void
	********************************************************/
	
	static void quickSortRec(T arr[], int first, int last, bool median);
	
	/*******************************************************
	* @pre :  Valid array, two valid indices
	* @post : puts median value of array in last position
	* @return : void
	********************************************************/
	
	static void setMedianPivot(T arr[], int first, int last);
	
	/*******************************************************
	* @pre :  Valid array, two valid indices
	* @post : partitions array around pivotIndex
	* @return : int
	********************************************************/
	
	static int partition(T arr[], int first, int last, bool median);
	
	/*******************************************************
	* @pre :  Valid array, valid size
	* @post : shuffles array
	* @return : void
	********************************************************/
	
	static void shuffle(T arr[], int size);
	
};
#include "Sorts.hpp"
#endif