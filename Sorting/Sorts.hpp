/*******************************************************
* @file: Sorts.hpp
* @author: Dravid Joseph
* @date: 7/20/15
* @brief: Templated implementation file for Sorts class
********************************************************/

template<typename T>
void Sorts<T>::bubbleSort(T arr[], int size){
	
	//This bubble sort bubbles towards the end of the list
	
	
	
	//iterates through every element of the list
	for(int i = 0;i<size;i++){
		bool swapped = false; //flag to terminate sort early if list is already sorted
		//iterates through every element of the list but the last
		for(int j = 0;j<size-1;j++){
			//swap if case holds
			if(arr[i]<arr[j]){
				
				swap(arr,i,j);
				swapped = true;	//flag to continue bubble sort	
			}
		}
		
		if(!swapped){
			//then list is sorted
			return;
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
	
	//loop goes through elements 1:size-1
	
	for(int i = 1;i<size;i++){
		
		//holds element
		T next = arr[i];
		
		int j = i;
		
		//while j isn't the end and the adjacent left element is greater than next
		while(j>0 && arr[j-1]>next){
			
			//shift to the right
			arr[j] = arr[j-1];
			
			//decrement
			j--;
		}
		
		//insert into proper index
		arr[j] = next;
	}
	
	
	assert(Sorts<T>::isSorted(arr, size));
}


template<typename T>
void Sorts<T>::selectionSort(T arr[], int size){
	
	for(int i = 0;i<size-1;i++){
		
		int min = i;
		bool swapped = false; //flag so unnecessary swap doesn't happen
		for(int j = i+1; j< size; j++){
			
			if(arr[j]<arr[min]){
				min = j;
				swapped = true;
			}
			
		}
		if(swapped){
			swap(arr,i,min);
			
		}
		
	}
	
	assert(Sorts<T>::isSorted(arr, size));
	
}

template<typename T>
bool Sorts<T>::isSorted(T arr[], int size){
	
	
	//runs through array
	for(int i = 0;i<size-1;i++){
		
		//if i+1 element isn't greater than or equal to the ith element, it's not sorted 
		if(arr[i] >= arr[i+1]){
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