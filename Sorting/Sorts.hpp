/*******************************************************
* @file: Sorts.hpp
* @author: Dravid Joseph
* @date: 10/26/15
* @brief: Templated implementation file for Sorts class
********************************************************/

template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size){
	
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
		shuffle(arr,size,generator);	//shuffle
	}
	
	
	assert(Sorts<T>::isSorted(arr, size));
}


template<typename T>
void Sorts<T>::insertionSort(T arr[], int size){
	
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
void Sorts<T>::shuffle(T arr[], int size,std::default_random_engine& generator){
	
	//creates a uniform distribution of integers from min to max.
	std::uniform_int_distribution<int> distribution(0,size-1);
	
	
	//run throuh array
	for(int i = 0;i<size;i++){
		
		//choose a random index
		int index = distribution(generator);
		
		//swap index with the random index
		swap(arr,i,index);
	}
	
	
}

template<typename T>
void Sorts<T>::swap(T arr[], int firstIndex, int secondIndex){
	
	//create a temporary holding variable
	T temp = arr[firstIndex];
	
	//swap 
	arr[firstIndex] = arr[secondIndex];
	arr[secondIndex] = temp;
		
}