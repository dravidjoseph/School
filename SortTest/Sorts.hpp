/*******************************************************
* @file: Sorts.hpp
* @author: Dravid Joseph
* @date: 10/26/15
* @brief: Templated implementation file for Sorts class
********************************************************/

template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size){
	
	//taken from lab 6
	
	bool swapped = true;
	int i = 0;
	
	while(swapped){
		
		//loop will break if swapped doesn't get switched
		//this ensures no unnecessary passes are done
		swapped = false;
		i++;
		
		for(int j = 0;j<size-i;j++){
			
			if(arr[j]>arr[j+1]){
				swap(arr,j,j+1);
				swapped = true;
			}
			//otherwise, do nothing
		}	
	}
	assert(Sorts<T>::isSorted(arr, size));
}

template<typename T>
void Sorts<T>::bogoSort(T arr[], int size){
	
	std::default_random_engine generator(time(nullptr));
	
	//while array is not sorted
	while(!isSorted(arr,size)){
		shuffle(arr,size);	//shuffle
	}
	
	
	assert(Sorts<T>::isSorted(arr, size));
}


template<typename T>
void Sorts<T>::quickSort(T arr[], int size){
	
	//calls quickSortRec, which does the actual sorting
	quickSortRec(arr,0,size-1,false);
	
	assert(Sorts<T>::isSorted(arr, size));
	
}

template<typename T>
void Sorts<T>::quickSortMedian(T arr[], int size){
	
	//calls quickSortRec with flag set true
	//this does the actual sorting
	quickSortRec(arr,0,size-1,true);

	assert(Sorts<T>::isSorted(arr, size));
	
}

template<typename T>
void Sorts<T>::mergeSort(T arr[], int size){
		
	if(size>1){
		int mid = size/2;
	
		T* a1 = arr + 0;
		T* a2 = arr + mid;
		
		mergeSort(a1,mid);
		mergeSort(a2,size-mid);
		
		merge(a1,a2,mid,size-mid);
	}
	
	
	
	assert(Sorts<T>::isSorted(arr, size));
}

template<typename T>
void Sorts<T>::insertionSort(T arr[], int size){
	
	//Taken from Lab 6
	
	for(int i = 1;i < size; i++){
		
		T next = arr[i];
		int index = i;
		
		while((index > 0) && (arr[index-1] > next)){
			arr[index] = arr[index - 1];

			index--;
		}
		arr[index] = next;
		
	}
	
	
	assert(Sorts<T>::isSorted(arr, size));
}

template<typename T>
void Sorts<T>::selectionSort(T arr[], int size){
	
	//taken from lab 6
	
	//find minimum of array
	int minIndex = 0;
	
	for(int i = 0;i<size;i++){
		minIndex = i;
		//only consider the subarrays
		for(int j = i;j<size;j++){
			//if the leftmost element isn't the minimum
			if(arr[minIndex] > arr[j]){
				//swap
				swap(arr,minIndex,j);
			}
			//Otherwise, the leftmost element is the minimum and is fine
		}
	}
	
	
	
	assert(Sorts<T>::isSorted(arr, size));
	
}

template<typename T>
bool Sorts<T>::isSorted(T arr[], int size){
	
	
	//runs through array
	for(int i = 0;i<size-1;i++){
		
		//if i+1 element isn't greater than or equal to the ith element, it's not sorted 
		if(arr[i] > arr[i+1]){
			return false;
		}
	}
	return true;
	
}

template<typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort,T arr[], int size){

	//Timer stuff
	std::chrono::system_clock::time_point start;
	std::chrono::system_clock::time_point end;
	std::chrono::duration<double> elapsed;
	
	//starts clock
	start = std::chrono::system_clock::now();
	//sorts according to the sort parameter
	sort(arr,size);
	
	//stops clock
	end = std::chrono::system_clock::now();
	
	//difference between start and end
	elapsed = end-start;
	
	//returns difference
	return elapsed.count();

}

template<typename T>
void Sorts<T>::swap(T arr[], int firstIndex, int secondIndex){
	
	//create a temporary holding variable
	T temp = arr[firstIndex];
	
	//swap 
	
	arr[firstIndex] = arr[secondIndex];
	arr[secondIndex] = temp;
		
}

template<typename T>
void Sorts<T>::merge(T* a1, T* a2, int size1, int size2){
	//creates temporary array to hold elements
	T* arr = new int[size1+size2];
	
	
	//store first and last indices of first half locally
	int first1 = 0;
	int last1 = size1-1;
	
	//store first and last indices of second half locally
	int first2 = 0;
	int last2 = size2-1;
	
	//starting point for temporary array
	int index = 0;
	
	//while we don't reach the ends of the halves
	while((first1 <= last1 && first2 <= last2)){
		
		//if the first element of the first half <= first element
		//of the second half, place where it needs to go
		if(a1[first1]<=a2[first2]){
			arr[index] = a1[first1];
			//move to next element
			first1++;
		}
		
		//otherwise, do the opposite and imcrement the other one
		else{
			arr[index] = a2[first2];
			first2++;
		}
		//move the temp index up 1.
		index++;	
	}
	
	
	//This is if the halves are of unequal size.
	//Otherwise, the conditions will halt the merge.
	//only one of the following while loops will run.
	
	while(first1 <= last1){
		arr[index] = a1[first1];
		first1++;
		index++;
	}
	
	while(first2 <=last2){
		arr[index] = a2[first2];
		first2++;
		index++;
	}
	
	//Copy from temporary array to the original array
	for(index = 0;index <= size1+size2-1;index++){
		a1[index] = arr[index];
	}
	
	//delete our temporary array
	delete[] arr;
	arr = nullptr;
	
}

template<typename T>
void Sorts<T>::quickSortRec(T arr[], int first, int last, bool median){
	
	//if the array passed in is at least one element
	if(first < last){
			
		//find a pivot using the partition function
			int pivotIndex = partition(arr,first,last,median);
			
			//quickSort everything to the left of the pivot
			quickSortRec(arr,first,pivotIndex-1,median);
			
			//quickSort everything to the right of the pivot.
			quickSortRec(arr,pivotIndex+1,last,median);
	}
	
}

template<typename T>
void Sorts<T>::setMedianPivot(T arr[], int first, int last){
	
	//If the array contains 2 elements and are in the wrong order, swap
	if(last-first == 1){
		if(arr[first] > arr[last]){
			swap(arr,first,last);
		}
	}
	//if the array contains no elements, don't do anything
	else if(last-first == 0){
		return;
	}
	//if the array contains 3+ elements, find the median using median-of-threes
	//swap the median with the last element.
	else{
		int mid = (last-first + 1)/2;
		if(arr[first]> arr[mid] && arr[first] > arr[last]){
			swap(arr,first,last);
		}
		else{
			if(arr[mid] > arr[first] && arr[mid] > arr[last]){
				swap(arr,mid,last);
			}
		}
	}
}


template<typename T>
int Sorts<T>::partition(T arr[], int first, int last, bool median){
	
	//if the median flag is passed in, use setMedianPivot to find median
	if(median){
		setMedianPivot(arr,first,last);
	}
	//set pivotIndex as the last index regardless of method used.
	int pivotIndex = last;
	
	//creates left and right placeholders
	int indexFromLeft = first;
	//we use last-1 to ignore the pivot value
	int indexFromRight = last-1;
	
	//flag to stop the loop when everything is sorted around pivot
	bool done = false;
		
	while(!done){
		//check to see if element is less than pivot.
		//if so, stop.
		//if not, move the placeholder along.
		while(arr[indexFromLeft] < arr[pivotIndex]){
			indexFromLeft++;
		}
		//check to see if element is more than pivot.
		//if so, stop.
		//if not, move the placeholder along.
		while(arr[indexFromRight] > arr[pivotIndex]){
			indexFromRight--;
		}
		
		//As long as the placeholders aren't at the same index
		//or above each other, swap them into their correct regions,
		//then advance the indices
		if(indexFromLeft < indexFromRight){
			swap(arr,indexFromLeft,indexFromRight);
			indexFromLeft++;
			indexFromRight--;
		}
		//if the condition above fails, you're done
		else{
			done = true;
		}
	}
	
	//move the pivot to its proper position.
	swap(arr,pivotIndex,indexFromLeft);
	
	//the elements are swapped, but the pivotIndex needs to change
	pivotIndex = indexFromLeft;
	return pivotIndex;
	
}

template<typename T>
void Sorts<T>::shuffle(T arr[], int size){
	
	std::default_random_engine generator(time(nullptr));
	std::uniform_int_distribution<int> distribution(0,size-1);
	
	for(int i = 0;i<size;i++){
		
		swap(arr,i,distribution(generator));
		
	}
	
}

template<typename T>
int* Sorts<T>::createTestArray(int size, int min, int max){
	
	//declares and seeds the generator
	std::default_random_engine generator(time(nullptr));
	
	//creates a uniform distribution of integers from min to max.
	std::uniform_int_distribution<int> distribution(min,max);
	
	//declare the array pointer
	int* arr = new int[size];
	
	//insert entries into array
	for(int i = 0;i<size;i++){
		arr[i] = distribution(generator);
	}
	
	return arr;
	
}
