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
	
	//assume first element is "sorted"
	for(int i = 1;i < size; i++){
		
		//consider first element in "unsorted section"
		T next = arr[i];
		//store index
		int index = i;
		
		
		//shift as long as not looking at leftmost index and arr[index]-1 isn't larger than next
		while((index > 0) && (arr[index-1] > next)){
			arr[index] = arr[index - 1];

			index--;
		}
		//arr[index] is now "empty", so fill with proper sorted value
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

template<typename T>
void Sorts<T>::swap(T arr[], int firstIndex, int secondIndex){
	
	//create a temporary holding variable
	T temp = arr[firstIndex];
	
	//swap 
	arr[firstIndex] = arr[secondIndex];
	arr[secondIndex] = temp;
		
}