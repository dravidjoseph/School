/*******************************************************
* @file: Sorts.hpp
* @author: Dravid Joseph
* @date: 7/20/15
* @brief: Templated implementation file for Sorts class
********************************************************/

template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size){
	
	bool swapped = false;
	
	for(int i = 0;i<size;i++){
		
		
		for(int j = 0;j<size-1;j++){
			
			if(arr[i]<arr[j]){
				
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				swapped = true;		//flag to terminate sort early if list is already sorted
			}
		}
		
		if(!swapped){
			return;
		}
		else{
			swapped = false;	//reset flag for next comparison
		}
		
	}
	
	assert(Sorts<T>::isSorted(arr, size));
}


template<typename T>
void Sorts<T>::bogoSort(T arr[], int size){
	
	std::default_random_engine generator(time(nullptr));
	
	while(!isSorted(arr,size)){
		shuffle(arr,size,generator);
	}
	
	
	assert(Sorts<T>::isSorted(arr, size));
}


template<typename T>
void Sorts<T>::insertionSort(T arr[], int size){
	
	
	for(int i = 1;i<size;i++){
		int next = arr[i];
		
		int j = i;
		
		while(j>0 && arr[j-1]>next){
			arr[j] = arr[j-1];
			j--;
		}
		
		arr[j] = next;
	}
	
	
	assert(Sorts<T>::isSorted(arr, size));
}


template<typename T>
void Sorts<T>::selectionSort(T arr[], int size){
	
	for(int i = 0;i<size-1;i++){
		
		int min = i;
		
		for(int j = i+1; j< size; j++){
			
			if(arr[j]<arr[min]){
				min = j;
			}
			
		}
		T temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		
	}
	
	assert(Sorts<T>::isSorted(arr, size));
	
}

template<typename T>
bool Sorts<T>::isSorted(T arr[], int size){
	
	for(int i = 0;i<size-1;i++){
		if(arr[i]>arr[i+1]){
			return false;
		}
	}
	return true;
	
}

template<typename T>
void Sorts<T>::shuffle(T arr[], int size,std::default_random_engine& generator){
	
	//creates a uniform distribution of integers from min to max.
	std::uniform_int_distribution<int> distribution(0,size-1);
	
	for(int i = 0;i<size;i++){
		T temp = arr[i];
		int index = distribution(generator);
		arr[i] = arr[index];
		arr[index] = temp;
	}
	
	
}